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
 
cv::Mat frame0, frame0Gray, frame0GrayHalf, frame0GrayHalfEdge; // cam0
cv::Mat frame1, frame1Gray, frame1GrayHalf, frame1GrayHalfEdge; // cam1
cv::Mat imgProcessed;

ViewerStatus viewStatus;

//ctrl-c 
void ctrlc_handler(sig_atomic_t s){
    printf("\nCaught signal %d\n",s);
    control_c=true;
    exit(1);
}

int main(int argc, char** argv){
    signal(SIGINT,ctrlc_handler);
	
	camwidth=640;
	camheight=480;

    imgProcessed=cv::Mat(camheight, camwidth, CV_8UC3);

    init_camera(0, camwidth, camheight, false, false, true, true, true);
    //init_camera(1, camwidth, camheight, false, camOpenCV, true, true, true);
    sleepms(200);

    //init_viewer(ViewMode::Camera0, ViewMode::Camera1, 1, false, true);
    init_viewer(ViewMode::Camera0,ViewMode::Processed);

    std::vector<std::vector<cv::Point2f>> faceLandmarks;
    std::vector<mpface::Face> faces;

    //for Face Mesh
    MediapipeFaceMesh mfm;
    FrameResultSynchroniser meshSync(100);

    //for Face Detect
    //MediapipeFace mf;
    //FrameResultSynchroniser faceSync(100);

    printf("Start Loop\n");
    do {
        // Get frame to frame,frameGray,frameGrayHalf
        if (GetFrame()==0) { //GetFrame()==1 (new frame from cam0 ==1, ==2 from cam1, ==3 from cam0 & cam 1)

            //here you have time to do anything

            sleepms(1);
            continue;
        }

        std::vector<std::vector<cv::Point2f>> faceLandmarks;
        faces.clear();

        //face Mesh
        meshSync.pushFrame(mfm.pushFrame(frame0),frame0);
        int resm=meshSync.getFrameFromId(mfm.getFaceMesh(faceLandmarks),imgProcessed);

        if (resm&&faceLandmarks.size()) {
            mfm.drawFaceMesh(imgProcessed,faceLandmarks);
            std::vector<cv::Rect> facesRects;
            mfm.getFacesRectsFromLandmarks(faceLandmarks,facesRects);
            mfm.drawFacesRects(imgProcessed,facesRects,greenScalar);
            tick2on=true;
        }      

        //face Detect
        // faceSync.pushFrame(mf.pushFrame(frame0),frame0);
        // int resf=faceSync.getFrameFromId(mf.getFaces(faces),imgProcessed);

        // if(resf&&faces.size()){
        //     mf.drawFacesRects(imgProcessed,faces);
        //     cv::Rect ff=faces[0].getBoundingBox();
        //     tick2on=true;
        // }

        viewStatus = viewer_refresh();
    } while (viewStatus != ViewerStatus::Exit && control_c != true);
    closing_function(0);
    return 1;
}
