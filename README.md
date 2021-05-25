# Servo Motors Microcontroller Project
Controls an x-direction motor and y-direction motor using a potentiometer and pulse width modulation on an STM32F4 Discovery board

Features:
* Switch 15 controls whether it's in manual or automatic mode
* The 7-segment display at position 7 shows whether it's in automatic or manual mode
* When in manual mode, switches 0 and 1 determine whether you want to control the x-direction and/or y-direction motors.
* A potentiometer connected to the ADC changes the position of the servo motors in manual mode. In automatic mode, they move back and forth on their own.
* The 7-segment displays at positions 0 and 1 give the x-direction motor position as a range between 0 and 90. The motors can move 90 degrees in either direction from center. The 7-segment displays at positions 2 and 3 give the y-direction motor position.
* Whether the x-direction motor is being controlled displays on 7-segment display 4, y-direction motor on 7-segment display 5
