#include <Arduino.h>

#include "pins.hpp"
#include "sensors/HallSensor.hpp"

HallSensor::HallSensor() {
    this->pin = HALL_SENSOR_PIN;
}

bool HallSensor::read() {
    return digitalRead(this->pin);
}
