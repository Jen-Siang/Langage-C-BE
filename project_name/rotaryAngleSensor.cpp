#include "rotaryAngleSensor.h"
#include <Arduino.h>
#include <cstddef>

rotaryAngleSensor::rotaryAngleSensor()
{
  // Code
  Serial.begin(115200);
  pinMode(rotary, INPUT);
  pinMode(LED,OUTPUT);
  ;
}
  
rotaryAngleSensor::~rotaryAngleSensor()
{
  // Code
  ;
}  

void rotaryAngleSensor::run(void)
{
  float voltage;
  int sensorValue = analogRead(rotary);
  voltage = (float)sensorValue*ADC_REF/1023;
  float degrees = (voltage*fullAngle)/GROVE_VCC;
  Serial.println("The angle between the mark and the starting position:");
  Serial.println(degrees);

  int brightness;
  brightness = map(degrees, 0, fullAngle, 0, 255);
  analogWrite(LED,brightness);

  if(degrees >=0 && degrees <75){
    Serial.println("up");
  }
  else if(degrees >=75 && degrees <150){
    Serial.println("right");
  }
  else if(degrees >=150 && degrees <225){
    Serial.println("down");
  }
  else if(degrees >=225 && degrees <300){
    Serial.println("left");
  }

  delay(500);
}