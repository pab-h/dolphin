#include "pins.hpp"

#include "displays/SpeedDisplay.hpp"
#include "meters/Speedometer.hpp"

SpeedDisplay::SpeedDisplay(Speedometer* speedometer) {

    this->clockPin = DISPLAY_VELOCITY_CLOCK_PIN;
    this->dioPin   = DISPLAY_VELOCITY_DATA_PIN;

    this->speedometer = speedometer;
    this->display     = new TM1637Display(
        this->clockPin, 
        this->dioPin
    );

    this->display->setBrightness(7);

}

SpeedDisplay::~SpeedDisplay() {
    delete this->display;
}

void SpeedDisplay::setup() {

    this->display->setBrightness(7);
    this->display->showNumberDecEx(
        0, 
        0b01000000,
        true
    );

}

void SpeedDisplay::update() {

    this->display->showNumberDecEx(
        this->speedometer->getVelocity() * 100,
        0b01000000,
        true
    );

}