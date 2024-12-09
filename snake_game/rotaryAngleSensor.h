/*********************************************************************
 * @file  rotaryAngleSensor.h
 * @author Lin Jen-Siang - Revelli Julie
 * @brief Header file for the rotary angle sensor class
 *********************************************************************/
#ifndef ROTARYANGLESENSOR_H_
#define ROTARYANGLESENSOR_H_

#include "Peripheral.h"

/**
  * @class rotaryAngleSensor
  * @brief Represents a rotary angle sensor and its functionalities
*/    
class rotaryAngleSensor : public Peripheral {
  private:
    int pin; // Pin connected to the rotary angle sensor

  public:
    /**
     * @brief Constructor for the rotary angle sensor
     * @param pin The pin number connected to the rotary angle sensor
    */    
    rotaryAngleSensor(int pin);

    /**
     * @brief Destructor for the rotary angle sensor
    */
    ~rotaryAngleSensor() {};

    /**
     * @brief Initializes the rotary angle sensor
    */
    void init() override;

    /**
     * @brief Reads the sensor value and prints the corresponding direction
    */
    void run();
};

#endif
