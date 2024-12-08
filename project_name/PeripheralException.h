#ifndef PERIPHERAL_EXCEPTION_H_
#define PERIPHERAL_EXCEPTION_H_

#include <Arduino.h>
#include <exception>

/**
 * @class PeripheralException
 * @brief Exception personnalisée pour les périphériques
 */
class PeripheralException : public std::exception {
private:
    String message;

public:
    PeripheralException(const String& msg) : message(msg) {}
};

#endif
