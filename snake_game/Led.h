/*********************************************************************
 * @file  Led.h
 * @author Lin Jen-Siang - Revelli Julie
 * @brief Header file for the LED class representing a peripheral LED
 *********************************************************************/
#ifndef LED_H_
#define LED_H_

#include "Peripheral.h"

/**
 * @class Led
 * @brief Class representing an LED connected to a specified pin
 */
class Led : public Peripheral {
private:
    int pin;  // Pin connected to the LED

public:
    /**
     * @brief Constructor for the LED class
     * @param pin The pin number where the LED is connected
     */
    Led(int pin);

    /**
     * @brief Destructor for the LED class
     */
    ~Led() {};

    /**
     * @brief Initializes the LED
     * Sets the LED pin as an OUTPUT and turns it OFF by default.
     */
    void init() override;

    /**
     * @brief Turns the LED ON
     */
    void high();

    /**
     * @brief Turns the LED OFF
     */
    void low();
};

#endif 
