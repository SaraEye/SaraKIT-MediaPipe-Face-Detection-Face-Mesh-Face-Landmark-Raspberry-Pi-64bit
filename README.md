# SaraKIT Face Detection, Face landmark detection, Face Mesh (Raspberry Pi4 CM4)

Easy to use based on MediaPipe from Google Face Detection, Face landmark detection, Face Mesh.

<b>The MediaPipe Face Detector</b> task lets you detect faces in an image or video. You can use this task to locate faces and facial features within a frame. The task outputs face locations, along with the following facial key points: left eye, right eye, nose tip, mouth, left eye tragion, and right eye tragion.

<b>The MediaPipe Face Landmarker</b> task lets you detect face landmarks and facial expressions in images and videos. You can use this task to identify human facial expressions, apply facial filters and effects, and create virtual avatars. The task outputs 3-dimensional face landmarks, blendshape scores (coefficients representing facial expression) to infer detailed facial surfaces in real-time, and transformation matrices to perform the transformations required for effects rendering.

```
make
./FaceDetection
```

The program receives the image from the camera, processes it and sends it.
We can see the preview of the operation in the browser at the address of our raspberry on port 7777, e.g. by entering http://192.168.1.16:7777.<br>
We will see one or two images side by side, the content of both images can be configured. By default, on the left we see a preview from the camera, on the right we see the detected face and the detected face points or face landmarks, similar to the video below:


We use the standard Raspberry Pi MMAL functions to capture frames from the camera, but we can also use the standard OpenCV functions.

We write how to install MediaPipe for Raspberry Pi in a separate repository.