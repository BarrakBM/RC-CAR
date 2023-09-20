# Arduino Bluetooth Controlled Car

This project controls a car using Bluetooth communication through Arduino. The car can move forward, backward, turn left, turn right, and also control the front and back lights.

## Pre-requisites:
1. Arduino IDE installed.
2. **AFMotor Library**: This is essential for motor operations. It can be obtained from [here](https://learn.adafruit.com/adafruit-motor-shield/library-install).
   
    **Installation of AFMotor Library**:
    - Download the AFMotor Library ZIP file.
    - Open Arduino IDE.
    - Go to Sketch -> Include Library -> Add .ZIP Library.
    - Locate and select the downloaded ZIP file.
    - Click on Open.

3. **Bluetooth Module**: Ensure to disconnect the Bluetooth module before uploading the Arduino code. If the Bluetooth module is connected during the code upload, you may encounter a compilation error.

## Wiring:
**Motors**:
- EA Pin: 3
- MA Pin: 6
- EB Pin: 4
- MB Pin: 5
- EC Pin: 7
- MC Pin: 10
- ED Pin: 8
- MD Pin: 9

**Lights**:
- Front Left Light: 11
- Front Right Light: 2
- Back Left Light: 12
- Back Right Light: 13

## Usage:

Connect to the car's Bluetooth module using a suitable device (like a smartphone with a Bluetooth control app). Send the following commands for control:

- **'F'**: Move Forward
- **'B'**: Move Backward
- **'L'**: Turn Left
- **'R'**: Turn Right
- **'W'**: Switch ON Front Lights
- **'w'**: Switch OFF Front Lights
- **'U'**: Switch ON Back Lights
- **'u'**: Switch OFF Back Lights

The Arduino receives these commands through Bluetooth and responds by moving the car or controlling the lights as per the received instruction.

## Note:

Ensure that the baud rate in your Bluetooth control app matches the baud rate set in the Arduino code (9600 in this case) for proper communication.

## Troubleshooting:

- Always ensure the Bluetooth module is disconnected before uploading the code.
- If the motors or lights are not working, check the wiring connections.
- Ensure the AFMotor Library is properly installed in the Arduino IDE.
