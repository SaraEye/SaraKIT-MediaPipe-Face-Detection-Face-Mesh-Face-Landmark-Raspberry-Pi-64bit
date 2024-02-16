# SaraKIT Face Analysis: Face Detection, Landmark Detection, and Face Mesh for Raspberry Pi 4 CM4

SaraKIT is an easy-to-use face analysis solution for Raspberry Pi 4 CM4, powered by state-of-the-art algorithms based on MediaPipe from Google. It provides robust functionality for face detection, face landmark detection, and face mesh processing, specifically optimized for the Raspberry Pi 64-bit platform.

## MediaPipe Face Detector
The MediaPipe Face Detector task allows you to accurately detect faces in images and videos. It provides precise face localization and identifies key facial features, including the left eye, right eye, nose tip, mouth, left eye tragion, and right eye tragion.

## MediaPipe Face Landmarker
The MediaPipe Face Landmarker task enables the detection of face landmarks and facial expressions in real-time images and videos. It empowers various applications such as facial expression analysis, facial filters and effects, and virtual avatar creation. This task outputs 3D face landmarks, blendshape scores (coefficients representing facial expressions), and transformation matrices for seamless real-time rendering of detailed facial surfaces.

To utilize SaraKIT for face analysis, follow these steps:

1. Compile the code by running the command `make`.
2. Execute the program using `./FaceDetection`.
3. The program captures frames from the camera, processes them, and sends the output.
4. Preview the operation in your web browser by accessing the Raspberry Pi's IP address followed by port 7777 (e.g., http://raspberrypi:7777/ or http://192.168.1.16:7777).
5. The browser preview displays one or two images side by side, where the content of each image can be customized. By default, the left image shows the camera preview, while the right image displays the detected face along with face landmarks. Refer to the video below for a similar visualization.

Both the standard Raspberry Pi MMAL functions and OpenCV functions can be used to capture frames from the camera.

For instructions on how to install MediaPipe on Raspberry Pi, please refer to our separate repository dedicated to this topic.

![SaraKIT_Face](https://github.com/SaraEye/SaraKIT-MediaPipe-Face-Detection-Face-Mesh-Face-Landmark-Raspberry-Pi-64bit/assets/35704910/f3cb2907-a7da-4629-a1a8-a15b9ffb9393)

## See more

### SaraKIT - Color Tracking:

![SaraKIT_ColorTracking](https://github.com/SaraEye/SaraKIT-Face-Tracking-MediaPipe-Raspberry-Pi-64bit/assets/35704910/7120ee8a-7612-4d82-8a3c-8cf38c451009)

[Video Link](https://saraai.com/_SaraKIT/video/SaraKIT_ColorTracking.mp4)

### SaraKIT - Object Detection:

![SaraKIT_Object_Detection](https://github.com/SaraEye/SaraKIT-Face-Tracking-MediaPipe-Raspberry-Pi-64bit/assets/35704910/e76bcf47-3d1c-4179-a330-c69601f94a8a)

[Video Link](https://saraai.com/_SaraKIT/video/SaraKIT_Object_Detection.mp4)

### SaraKIT - Field Oriented Control (FOC):

![SaraKIT_field_oriented_control_FOC](https://github.com/SaraEye/SaraKIT-Face-Tracking-MediaPipe-Raspberry-Pi-64bit/assets/35704910/e93a09ee-23c4-44a3-a6e2-f6a2e64c351b)

[Video Link](https://saraai.com/_SaraKIT/video/SaraKIT_field_oriented_control_FOC.mp4)

### SaraKIT - BLDC Gimbal Motors (FOC) vs Servo vs Stepper motor

[YouTube Link](https://youtu.be/Nwvnoo5efzE)

## SaraAI LLC

Website: [https://SaraAI.com](https://SaraAI.com)<br>
Project Page: [https://SaraKIT.SaraAI.com](https://SaraKIT.SaraAI.com)
