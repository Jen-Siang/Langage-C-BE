/*********************************************************************
 * @file  LCD.cpp
 * @author Lin Jen-Siang - Revelli Julie
 * @brief Implementation file for the LCD class
 *********************************************************************/
#include "LCD.h"
#include "rgb_lcd.h"
#include <Arduino.h>

/**
 * @brief Constructor for the LCD class
 */
LCD::LCD() : Peripheral("LCD") {}

/**
 * @brief Initializes the LCD
 * Configures the LCD with default settings: 16x2 dimensions and a default RGB color.
 */
void LCD::init() {
  Serial.begin(115200);         // Initialize serial communication at 115200 baud
  lcd.begin(16, 2);             // Set up the LCD with 16 columns and 2 rows
  lcd.setRGB(colorR, colorG, colorB); // Set the default background color
  lcd.print("Initialisation");  // Display the initialization message
  delay(2000);                  // Wait for 2 seconds
  lcd.clear();                  // Clear the screen
}

/**
 * @brief Clears the LCD display
 * Resets the cursor position to the top-left corner.
 */
void LCD::clear() {
  lcd.clear();                 // Clear the LCD screen
  lcd.setCursor(0, 0);         // Set the cursor to column 0, row 0
}

/**
 * @brief Displays a message on the LCD
 * @param message The message to display
 */
void LCD::message(const String message) {
  lcd.print(message);          // Print the message to the LCD
}

/**
 * @brief Sets the cursor position on the LCD
 * @param col The column index (starting at 0)
 * @param row The row index (starting at 0)
 */
void LCD::setCursor(int col, int row) {
  lcd.setCursor(col, row);     // Set the cursor to the specified column and row
}

/**
 * @brief Gradually changes the LCD backlight color
 * Smoothly transitions the RGB color through a gradient.
 */
void LCD::progChangeColor() {
  // Increase RGB values gradually
  for (int i = 0; i <= 255; i++) {
    lcd.setRGB(i, 255 - i, i / 2); // Set RGB values dynamically
    delay(10);                    // Delay for smooth transition
  }

  // Decrease RGB values gradually
  for (int i = 255; i >= 0; i--) {
    lcd.setRGB(i, 255 - i, i / 2); // Set RGB values dynamically
    delay(10);                    // Delay for smooth transition
  }
}

/**
 * @brief Overloads the `<<` operator to print messages to the LCD
 * @param message The message to display
 * @return Reference to the current LCD object
 */
LCD& LCD::operator<<(const String& message) {
  this->message(message);      // Call the message method to display the text
  return *this;                // Return the current object for chaining
}
