#include "pins.hpp"

#include "displays/DistanceDisplay.hpp"
#include "meters/Hodometer.hpp"

DistanceDisplay::DistanceDisplay(Hodometer* hodometer) {

    this->clockPin = DISPLAY_DISTANCE_CLOCK_PIN;
    this->dioPin   = DISPLAY_DISTANCE_DATA_PIN;

    this->hodometer = hodometer;
    this->display     = new TM1637Display(
        this->clockPin, 
        this->dioPin
    );

    this->display->setBrightness(7);

}

DistanceDisplay::~DistanceDisplay() {
    delete this->display;
}

void DistanceDisplay::setup() {

    this->display->setBrightness(7);
    this->display->showNumberDecEx(
        0, 
        0b01000000,
        true
    );

}

void DistanceDisplay::update() {

    this->display->showNumberDecEx(
        this->hodometer->getDistance() * 100,
        0b01000000,
        true
    );

}