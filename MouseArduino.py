import pyautogui as mouse
import sys
import time 
import serial

#Specify the correct COM port
arduino = serial.Serial(port='/dev/cu.usbserial-AB0JQM9A', baudrate=9600, timeout=.1)
arduino.close()
arduino.open()

#delay of 1 second
time.sleep(1)                             


while 1:
   data = str(arduino.readline().decode('ascii'))

   if data == "No convergence" or data == "ECE failure" or data == "Signal/Noise error" :
   		break
   
   list = data.split(":") 
   x = list[0]
   y = list[1]
   z = list[2]
   x = int(x)
   y = int(y)                           # convert to int
   mouse.moveTo(x, y, duration = 1)                 # move cursor to desired position
   #if '1' in z:                                     # read the Status of SW
      #mouse.click(x, y)                             # clicks 

arduino.close()