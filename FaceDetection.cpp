#include <iostream>
#include <signal.h>
#include <stdio.h>
#include <math.h>
#include <arm_neon.h>
#include "unistd.h"

#include "struct.hpp"
#include "lib/viewer/viewer.hpp"
#include "lib/mediapipe/Mediapipe.hpp"

using namespace std;
 
cv::Mat frame, frameGray, frameGrayHalf, frameGrayHalfEdge;     // cam0
cv::Mat frame1, frame1Gray, frame1GrayHalf, frame1GrayHalfEdge; // cam1
cv::Mat frameBig, imgPreview, imgPreview1, imgWindow, imgcopy0, imgcopy1;
cv::Mat imgORG, imgEdge;

ViewerStatus viewStatus;

//ctrl-c 
void ctrlc_handler(sig_atomic_t s){
    printf("\nCaught signal %d\n",s);
    control_c=true;	
    exit(1);
}

int main(int argc, char** argv){
    signal(SIGINT,ctrlc_handler);
    imgEdge=cv::Mat(camheight, camwidth, CV_8UC3);

    init_camera(0, camwidth, camheight, false, camOpenCV, cambuffered, true, true);
    //init_camera(1, cam1width, cam1height, false, camOpenCV, cambuffered, false, false);

    init_viewer();

    std::vector<std::vector<cv::Point2f>> faceLandmarks;
    std::vector<mpface::Face> faces;

    MediapipeFaceMesh mfm;
    FrameResultSynchroniser meshSync(100);
    //MediapipeFace mf;
    //FrameResultSynchroniser faceSync(100);

    printf("Start Loop\n");
    do {
        // Get frame to frame,frameGray,frameGrayHalf (CamWide is only gray)dupa
        if (GetFrame(0)!=1) { //GetFrame()==1 (new frame from cam0, ==2 from cam1, ==3 from cam0 & cam 1)

            //here you have time to do anything
            sleepms(1);
            continue;
        }

        std::vector<std::vector<cv::Point2f>> faceLandmarks;
        faces.clear();

        meshSync.pushFrame(mfm.pushFrame(frame),frame);
        int resm=meshSync.getFrameFromId(mfm.getFaceMesh(faceLandmarks),imgEdge);

        if (resm&&faceLandmarks.size()) {
            mfm.drawFaceMesh(imgEdge,faceLandmarks);
            std::vector<cv::Rect> facesRects;
            mfm.getFacesRectsFromLandmarks(faceLandmarks,facesRects);
            mfm.drawFacesRects(imgEdge,facesRects,greenScalar);
            tick2on=true;
        }
        viewStatus = viewer_refresh();
/*
        faceSync.pushFrame(mf.pushFrame(frame),frame);
        int resf=faceSync.getFrameFromId(mf.getFaces(faces),imgEdge);

        if(resf&&faces.size()){
            mf.drawFacesRects(imgEdge,faces);
            cv::Rect ff=faces[0].getBoundingBox();
            viewStatus = viewer_refresh();
        }
*/        

    } while (viewStatus != ViewerStatus::Exit && control_c != true);
    closing_function(0);
    return 1;
}
