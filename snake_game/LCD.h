/*********************************************************************
 * @file  LCD.h
 * @author Lin Jen-Siang - Revelli Julie
 * @brief Header file for the LCD class representing an RGB LCD screen
 *********************************************************************/
#ifndef LCD_H_
#define LCD_H_

#include "Peripheral.h"
#include "rgb_lcd.h"

/**
 * @class LCD
 * @brief Class representing an RGB LCD connected as a peripheral
 */
class LCD : public Peripheral {
private:
    rgb_lcd lcd;  // Instance of the `rgb_lcd` object to interface with the LCD

    // RGB color constants for default display color
    const int colorR = 255;  
    const int colorG = 0;    
    const int colorB = 0;    

public:
    /**
     * @brief Constructor for the LCD class
     */
    LCD();

    /**
     * @brief Destructor for the LCD class
     */
    ~LCD() {};

    /**
     * @brief Initializes the LCD screen
     */
    void init() override;

    /**
     * @brief Clears the LCD screen
     */
    void clear();

    /**
     * @brief Displays a message on the LCD screen
     * @param message The message string to display
     */
    void message(const String message);

    /**
     * @brief Sets the cursor position on the LCD screen
     * @param col The column position on the screen (0-15)
     * @param row The row position on the screen (0-1)
     */
    void setCursor(int col, int row);

    /**
     * @brief Changes the LCD's RGB color gradually
     */
    void progChangeColor();

    /**
     * @brief Overloaded operator `<<` for easy message printing
     * @param message The message string to display
     * @return A reference to the current LCD object
     */
    LCD& operator<<(const String& message);
};

#endif
