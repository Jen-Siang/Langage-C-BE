/*********************************************************************
 * @file  rotaryAngleSensor.cpp
 * @author Lin Jen-Siang - Revelli Julie
 * @brief Implementation file for the RotaryAngleSensor class
 *********************************************************************/
#include "rotaryAngleSensor.h"
#include <Arduino.h>

//#define rotary A0

#define fullAngle 300 // Maximum measurable angle in degrees
#define ADC_REF 3.3   // ADC reference voltage
#define GROVE_VCC 3.3 // Grove module operating voltage

/**
 * @brief Constructor for the rotaryAngleSensor class
 * @param pin The pin number connected to the rotary angle sensor
 */
rotaryAngleSensor::rotaryAngleSensor(int pin) : Peripheral("RotaryAngleSensor"), pin(pin) {}

/**
 * @brief Initializes the rotary angle sensor
 * Configures the pin as an input and initializes serial communication
 */
void rotaryAngleSensor::init() {
  pinMode(pin, INPUT);           // Configure the pin as an input
  Serial.begin(115200);          // Start serial communication at 115200 baud
  Serial.println("Rotary Angle Sensor initialized"); // Confirmation message
}

/**
 * @brief Reads the rotary angle sensor and prints the direction
 * Calculates the current angle from the sensor's analog input and maps it to a direction
 */
void rotaryAngleSensor::run(void) {
  float voltage;                          // Variable to store the calculated voltage
  int sensorValue = analogRead(pin);      // Read the sensor's analog value
  voltage = (float)sensorValue * ADC_REF / 1023; // Convert the analog value to a voltage
  float degrees = (voltage * fullAngle) / GROVE_VCC; // Map the voltage to an angle in degrees
  
  // Determine the direction based on the angle
  if (degrees >= 0 && degrees < 75) {
    Serial.println("up");  // Angle corresponds to "up"
  } 
  else if (degrees >= 75 && degrees < 150) {
    Serial.println("right");  // Angle corresponds to "right"
  } 
  else if (degrees >= 150 && degrees < 225) {
    Serial.println("down");  // Angle corresponds to "down"
  } 
  else if (degrees >= 225) {
    Serial.println("left");  // Angle corresponds to "left"
  }

  delay(500); // Add a delay to prevent rapid serial output
}