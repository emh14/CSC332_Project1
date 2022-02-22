# Motion Acitvated Mouse 
## Sensor Nodes Project
WFU CSC 332 Mobile and Pervasive Computing
Ethan Harrison and Henry Lynn

## Project Statement 
This project is an accessibility mouse for disabled individuals who may be missing or have limited capabilities in their hands. Two sensors detect the presence of a limb (or other object) without requiring any of the hardware to be touched at all (after intial setup). 

## Abstract 
The mouse functions with a time-of-flight sensor for the x-axis and an ultrasonic sensor for the y-axis. The sensors connect to an Arduino board (Uno, Nano, or other board of choice) which maps the sensor data to a pixel range of the computer's  display. The data is sent via serial port to a Python program, which positions the laptop’s cursor according to the data. 

## Materials
1. Computer (with display)
2. Arduino Board 
3. USB Adapter Cable 
4. Breadboard
5. HC-SR04 Ultrasonic Distance Sensor
6. Adafruit VL6180X Time of Flight MicroLIDAR Distance Sensor
7. 4 Male-Female Pin Connectors 
8. 6 Male-Male Pin Connectors

## Circuit Diagrams 
Created using circuito.io
###### Arduino Uno
<img width="510" alt="UnoDiagram" src="https://user-images.githubusercontent.com/54651014/155056745-e115d2d0-da0a-4c2d-a492-7fde96c07f56.png">

###### Arduino Nano
<img width="820" alt="NanoDiagram" src="https://user-images.githubusercontent.com/54651014/155056771-2dc8de8f-5c88-438e-8d61-e851efa9247d.png">

## Construction 
1. Connect the Arduino’s 5V pin to one of the “+” red rails on a breadboard
2. Connect one the Arduino’s ground pins (labeled GND) to the breadboard’s blue “-“ rail
3. Use two cables to connect the HC-SR04 Ultrasonic sensor’s Vcc and GND pins to the “+” and “-“ rails, respectively
4. Use two cables to link the Ultrasonic sensor’s Trig pin to Arduino’s digital pin 3 and the sensor’s echo pin to Arduino digital pin 2
5. Use two wires to connect the VL53L0X TOF sensor’s SCL and SDA pins to the Arduino’s SCL and SDA ports 
      (these are adjacent to the AREF pin, and their labels on on the under-side of the Arduino board)
7. Finally, connect the TOF sensors VIN and GND pins to the “+” and “-“ rails, respectively 
8. The circuit is now fully assembled

## DevOps

###### Arduino
We developed our Arduino code with 6 steps in mind.
1. Create a circuit with the chosen sensors and assure they are outputting reasonable information.
2. Set up necessary variables to hold sensor data and outgoing information.
3. Put pins in the the proper modes to retrieve sensor data.
4. Have the sensors to continually collect data and assign the data to the correct variables.
5. Map that collected data into pixel ranges which matches the size of our laptop screen (Y for the ultrasonic sensor and X for the Time-of-flight sensor.
6. Send that data via serial to the laptop, with proper formatting for the python code to interpret.

###### Python
After we knew the Arduino was working properly, we could test it in Python 
1. We imported a few libraries during the development of our Python code and istalled them using pip. This includes time, sys, serial and pyserial
2. The most important library to include is pyautogui (in our code "as mouse"). This is what allows Python to control your computer's screen. 
3. It is necessary to specificy the correct port your Arduino is connected to and list it in the serial function
       (this can be done by going to Arduino > Tools > Port)
5. The Python code is set up to continually read in data as long as the Arduino is running 
6. We isolate each variable (x coordinates, y coordinates, and z is to represent a click of the mouse)
7. Finally, use pyautogui.moveTo to send the mouse to those coordinates 

## Testing
Below are pictures of us testing our prototype

![Test1](https://user-images.githubusercontent.com/54651014/155059640-1f81e8cd-1b03-409f-9c39-75432fadbba8.jpg)
![Test2](https://user-images.githubusercontent.com/54651014/155059641-1b1a4997-c2d3-431b-a753-460a8f62ecbc.jpg)
![Test3](https://user-images.githubusercontent.com/54651014/155059642-b685676e-a4c1-4470-b706-df0e56e02a02.jpg)

