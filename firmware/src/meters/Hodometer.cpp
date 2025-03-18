#include <Arduino.h>

#include "meters/Hodometer.hpp"
#include "constants.hpp"
#include "config.hpp"

Hodometer::Hodometer(uint8_t radius) {

    this->radius            = radius;
    this->circumferenceSize = 0;
    this->distance          = 0;

    this->lastMeasureTime = 0;

    this->isNewDataAvailable = false;

}

void Hodometer::updateCircumferenceSize() {

    this->circumferenceSize = TWO_PI * this->radius;
    this->circumferenceSize *= CENTIMETERS_TO_KILOMETERS;

}


void Hodometer::setRadius(float radius) {

    if (radius > 0) {
        this->radius = radius;
        this->updateCircumferenceSize();
    }
    
}

void Hodometer::ISRHallSensorHit() {
    
    this->lastMeasureTime = micros();
    this->distance += this->circumferenceSize;

}

float Hodometer::getDistance() {
    return this->distance;
}
