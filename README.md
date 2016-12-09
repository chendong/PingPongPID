# Project1506 - PID Regulation #
Solution for Project1506.
Code written by Elvin Lapovski and Nadia Manoh.

**Video Demonstration**

Regulation parameters used for the video demonstration:

` kp = 0.28 `
` ti = 0.855 `
` td = 0.23 `
` dt = 0.1 `
` bv = Setpoint `

* [Setpoint = 25cm](https://www.youtube.com/watch?v=43g1AmXBxpA)
* [Setpoint = 30cm](https://www.youtube.com/watch?v=8H91RBycpMM)
* [Setpoint = 35cm](https://www.youtube.com/watch?v=hHX6vfV04ZY)
* [Setpoint = 40cm](https://www.youtube.com/watch?v=kiCDJbtWZzs)
* [Setpoint = 45cm](https://www.youtube.com/watch?v=R1WYQgb--_M)
* [Setpoint = 50cm](https://www.youtube.com/watch?v=xD2bGLk0sq4)

![alt text](https://s28.postimg.org/bsrqhtxil/Full_Size_Render_jpg.jpg "Project setup")

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