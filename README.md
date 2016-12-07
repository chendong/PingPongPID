# Project1506 - PID Regulation #
Solution for Project1506.
Code written by Elvin Lapovski and Nadia Manoh.
[Video Demonstration](https://drive.google.com/file/d/0B4JHuoKHUfcvMVJxNjBwMk5ER0E/view)
![alt text](https://s27.postimg.org/nsalb2onn/IMG_0831.jpg "Project setup")

## How to use - Atmel Studio ##
1. Launch "Project.atsln" using ***Atmel Studio 6.1***.
2. Connect a Arduino Due device to the computer.
3. Build the project and start BossacArduinoDue(Debug) under the "Tools" menu.

## How to use - Matlab ##
#### In order to use the Matlab code, you need to complete the steps for Atmel Studio. ####
1. Open "Init.m" and make sure that the COM-port that the Arduino Due is connected to is listed.
2. If you're using a different setup than the one used for this solution it is recommended to change the values for variables "dt", "kp", "ti", "td" and "bv".
3. Open "Plot.m" and set N to desired plot runtime in seconds.
4. Run "Init.m" to start PID regulation.
5. Run "Plot.m" to start plotting.