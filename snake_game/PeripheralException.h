/*********************************************************************
 * @file  PeripheralException.h
 * @author Lin Jen-Siang - Revelli Julie
 * @brief Header file for custom exception handling for peripherals
 *********************************************************************/
#ifndef PERIPHERAL_EXCEPTION_H_
#define PERIPHERAL_EXCEPTION_H_

#include <Arduino.h>
#include <string>

/**
 * @class PeripheralException
 * @brief Custom exception class for handling peripheral errors
 */
class PeripheralException {
private:
    String message; // Error message

public:
    /**
     * @brief Constructor to create a PeripheralException with a message
     * @param msg The error message
     */
    PeripheralException(const String& msg) : message(msg) {}

    /**
     * @brief Method to get the error message
     * @return Error message as a String
     */
    String getMessage() const {
        return message;
    }
};

#endif
