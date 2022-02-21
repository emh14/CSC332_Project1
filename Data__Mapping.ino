#include <Wire.h>
#include "Adafruit_VL6180X.h"
Adafruit_VL6180X vl = Adafruit_VL6180X();
const int maxX = 1440;
const int maxY = 900;
int distance;
long duration;
int pulsePin = 3;
int echoPin = 2;

int mouseX;
int mouseY;
int newX;
int newY;
int z;
void setup() {
   while (!Serial) {
    delay(1);
  }
  vl.begin();
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(echoPin, INPUT);
 pinMode(pulsePin, OUTPUT);

 
}

void loop() {

uint8_t range = vl.readRange();
uint8_t status = vl.readRangeStatus();

  // Some error occurred, print it out!
  
  if  ((status >= VL6180X_ERROR_SYSERR_1) && (status <= VL6180X_ERROR_SYSERR_5)) {
    Serial.println("System error");
  }
  else if (status == VL6180X_ERROR_ECEFAIL) {
    Serial.println("ECE failure");
  }
  else if (status == VL6180X_ERROR_NOCONVERGE) {
    Serial.println("No convergence");
  }
  else if (status == VL6180X_ERROR_RANGEIGNORE) {
    Serial.println("Ignoring range");
  }
  else if (status == VL6180X_ERROR_SNR) {
    Serial.println("Signal/Noise error");
  }
  else if (status == VL6180X_ERROR_RAWUFLOW) {
    Serial.println("Raw reading underflow");
  }
  else if (status == VL6180X_ERROR_RAWOFLOW) {
    Serial.println("Raw reading overflow");
  }
  else if (status == VL6180X_ERROR_RANGEUFLOW) {
    Serial.println("Range reading underflow");
  }
  else if (status == VL6180X_ERROR_RANGEOFLOW) {
    Serial.println("Range reading overflow");
  }
  newX = map(range, 0, 180, 0, maxX);
  newX = constrain(newX, 0, maxX);

  digitalWrite(pulsePin, LOW);
  delay(2);
  digitalWrite(pulsePin, HIGH);
  delay(10);
  digitalWrite(pulsePin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = ((duration * .034) / 2);
  newY = map(distance, 0, 24, 0, maxY);
  newY = constrain(newY, 0, maxY);


 if (status == VL6180X_ERROR_NONE) {
 
    if(mouseX!=newX or mouseY!=newY or z==1) // prints only when the joystick is moved
    {
    Serial.print(newX);    // print the data and separating by ":"
    Serial.print(":");
    Serial.print(newY);
    Serial.print(":");
    Serial.println(z);
    mouseX = newX;
    mouseY = newY;
    }
  
  } 
   
}
