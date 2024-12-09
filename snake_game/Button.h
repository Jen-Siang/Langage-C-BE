/*********************************************************************
 * @file  Button.h
 * @author Lin Jen-Siang - Revelli Julie
 * @brief Header file for the Button class representing a button peripheral
 *********************************************************************/
#ifndef BUTTON_H_
#define BUTTON_H_

#include "Peripheral.h"

/**
 * @class Button
 * @brief Class representing a button connected as a peripheral
 */
class Button : public Peripheral {
private:
    int pin;  // The digital pin connected to the button

public:
    /**
     * @brief Constructor for the Button class
     * @param pin The pin number where the button is connected
     */
    Button(int pin);

    /**
     * @brief Destructor for the Button class
     */
    ~Button() {}

    /**
     * @brief Initializes the button
     */
    void init() override;

    /**
     * @brief Checks if the button is pressed
     * @return `true` if the button is pressed, `false` otherwise.
     */
    bool isPress();
};

#endif
