### Components:
- Dual-core ESP32-S3 WROOM-1 Microcontroller
- SG90 Micro Servo Motors
- 2-Pin Push Buttons
- Breadboard & Jumper wires
- USB-cable

### Description:
I've set up the environment and installed required libraries in the Arduino IDE for using the servos. After setting up the wires between the breadboard, the ESP32 and a servo, connecting the breadboard with an eternal power source and writing the code for moving the servo, I could continuously move it from 0 degree to 90 degrees to 180 degrees. Then instead of the automatic movement, I tried using a push button to move it and I've successfully moved it from 0 degree to 180 dgrees and back to 0 degree on each button press.

I've ran into a problem while trying to use two servos doing the same task. After tweaking the code and wirings, I could finally make it work after many tries. Thus, I've learned how to work with multiple servo motors.