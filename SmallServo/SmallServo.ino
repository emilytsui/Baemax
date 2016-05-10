#include <Servo.h> 

Servo elbow1;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
Servo shoulder1; 
Servo wrist1;

Servo elbow2;
Servo shoulder2; 
Servo wrist2;


int pos = 0;    // variable to store the servo position 
const int buttonPin = 13;
int buttonState = 0;
const int servo1Pin = 9;
const int servo3Pin = 11;
const int servo5Pin = 10;

const int servo4Pin = 3; 
const int servo6Pin = 4;
const int servo8Pin = 5;


void setup() 
{ 
  pinMode(servo1Pin, OUTPUT);
  pinMode(servo3Pin,OUTPUT);
  pinMode(servo4Pin,OUTPUT);
  pinMode(servo6Pin,OUTPUT);
  pinMode(servo5Pin,OUTPUT);
  pinMode(servo8Pin,OUTPUT);
  pinMode(buttonPin, INPUT);
  elbow2.attach(servo1Pin);  
  wrist2.attach(servo3Pin);
  elbow1.attach(servo6Pin);
  wrist1.attach(servo4Pin);
  shoulder1.attach(servo8Pin);
  shoulder2.attach(servo5Pin);
  Serial.begin(19200);
} 


void loop() 
{ 
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  elbow1.write(90);
  elbow2.write(90);
  wrist1.write(90);
  wrist2.write(90);
  if (buttonState == HIGH) {
    for(pos = 90; pos <= 180; pos += 1) {
      shoulder1.write(180-pos);
      shoulder2.write(pos);
      delay(15);
    }
    
    for(pos = 67; pos <= 90; pos += 1) {
      elbow2.write(pos);
      if (pos<90) {
        elbow1.write(183-pos);
      } else {
        elbow1.write(90);
      }
      delay(15);
    }
    
    delay(1000);
    
    for(pos = 118; pos >= 90; pos -= 1) {
      wrist1.write(pos);
      if (pos>=96) {
        wrist2.write(186-pos);
      } else {
        wrist2.write(90);
      }
      delay(15);
    }
    
    elbow1.write(90);
    elbow2.write(90);
    wrist1.write(90);
    wrist2.write(90);

    delay(3500);
    
    for(pos = 63; pos <= 90; pos += 1) {
      wrist1.write(pos);
      if (pos<90) {
        wrist2.write(182-pos);
      } else {
        wrist2.write(90);   
      }
      delay(15);
    }

    delay(1000);
    
    for(pos = 109; pos>=90; pos-=1)     
    {                     
      elbow2.write(pos);
      elbow1.write(180-pos);
      delay(15);                   
    }
    for(pos = 180; pos >= 90; pos -= 1) {
      shoulder1.write(180-pos);
      shoulder2.write(pos);
      delay(15);
    }
    

  }
  else {
    shoulder1.write(90);
    shoulder2.write(90);
    elbow1.write(90);
    wrist1.write(90);
    elbow2.write(90);
    wrist2.write(90);
  }
}

