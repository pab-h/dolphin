#include <Arduino.h>

#include "meters/Speedometer.hpp"

#include "constants.hpp"
#include "config.hpp"

Speedometer::Speedometer(uint8_t radius) {

    this->radius            = (float) radius;
    this->circumferenceSize = 0;
    this->velocity          = 0;
    
    this->lastHitHallSensorTime    = 0;
    this->currentHitHallSensorTime = 0;
    this->hitHallSensorPeriod      = 0;
    
    this->lastMeasureTime = 0;

    this->isNewDataAvailable = false;

}

void Speedometer::updateCircumferenceSize() {

    this->circumferenceSize = TWO_PI * this->radius;
    this->circumferenceSize *= CENTIMETERS_TO_KILOMETERS;

}

void Speedometer::setRadius(uint8_t radius) {

    if (radius > 0) {
        this->radius = radius;
        this->updateCircumferenceSize();
    }
    
}

void Speedometer::resetTrigger() {

    if (micros() - this->lastMeasureTime > RESET_VELOCITY_THRESHOLD) {
        this->velocity = 0;
    }

}


void Speedometer::ISRHallSensorHit() {

    this->lastHitHallSensorTime    = this->currentHitHallSensorTime;
    this->currentHitHallSensorTime = micros();
    this->lastMeasureTime          = this->currentHitHallSensorTime;

    if (this->lastHitHallSensorTime > 0) {
        this->hitHallSensorPeriod  = this->currentHitHallSensorTime;
        this->hitHallSensorPeriod -= this->lastHitHallSensorTime;

        this->velocity  = this->circumferenceSize;
        this->velocity /= (float) this->hitHallSensorPeriod;
        this->velocity /= (float) MICROSECONDS_TO_SECOUNDS * SECONDS_TO_HOURS;
    }

}

float Speedometer::getVelocity() {

    return this->velocity;

}
