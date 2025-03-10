#include <Arduino.h>

#include "Hodometer.hpp"
#include "constants.hpp"
#include "config.hpp"

Hodometer::Hodometer() {

    this->radius            = 0;
    this->circumferenceSize = 0;
    this->distance          = 0;

    this->lastMeasureTime = 0;
    this->resetTimeThreshold =  RESET_DISTANCE_TIME_SECONDS;
    this->resetTimeThreshold *= SECONDS_TO_MICROSECONDS;

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

void Hodometer::resetTrigger() {

    if (micros() - this->lastMeasureTime > this->resetTimeThreshold) {
        this->distance = 0;
    }

}

void Hodometer::ISRHallSensorHit() {

    this->lastMeasureTime = micros();
    this->isNewDataAvailable = true;

}

float Hodometer::getDistance() {
    return this->distance;
}

void Hodometer::updateDistance() {

    if (this->isNewDataAvailable) {
        noInterrupts();

        this->isNewDataAvailable = false;
        
        this->distance += this->circumferenceSize;

        interrupts();
    }

}