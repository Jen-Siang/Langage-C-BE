#include "rotaryAngleSensor.h"
#include <Arduino.h>

//#define rotary A0
#define fullAngle 300 //300 degrees
#define ADC_REF 3.3
#define GROVE_VCC 3.3

rotaryAngleSensor::rotaryAngleSensor(int pin) : Peripheral("RotaryAngleSensor"), pin(pin) {}

void rotaryAngleSensor::init() {
  pinMode(pin, INPUT);
  Serial.begin(115200);
  Serial.println("Rotary Angle Sensor initialized");
}
 

void rotaryAngleSensor::run(void) {
  float voltage;
  int sensorValue = analogRead(pin);
  voltage = (float)sensorValue*ADC_REF/1023;
  float degrees = (voltage*fullAngle)/GROVE_VCC;

  if(degrees >=0 && degrees <75){
    Serial.println("up");
  }
  else if(degrees >=75 && degrees <150){
    Serial.println("right");
  }
  else if(degrees >=150 && degrees <225){
    Serial.println("down");
  }
  else if(degrees >=225){
    Serial.println("left");
  }

  delay(500);
}
