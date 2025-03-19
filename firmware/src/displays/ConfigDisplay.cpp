#include <TM1637Display.h>

#include "displays/ConfigDisplay.hpp"

#include "pins.hpp"

ConfigDisplay::ConfigDisplay(uint8_t* radius) {

    this->radius = radius;

    this->topClockPin = DISPLAY_DISTANCE_CLOCK_PIN;
    this->topDioPin   = DISPLAY_DISTANCE_DATA_PIN;

    this->bottomClockPin = DISPLAY_VELOCITY_CLOCK_PIN;
    this->bottomDioPin   = DISPLAY_VELOCITY_DATA_PIN;
    
    this->topDisplay    = new TM1637Display(
        this->topClockPin,
        this->topDioPin
    );
    this->bottomDisplay = new TM1637Display(
        this->bottomClockPin,
        this->bottomDioPin
    );

}

void ConfigDisplay::setup() {

    this->topDisplay->setBrightness(7);
    this->bottomDisplay->setBrightness(7);

    this->topDisplay->setSegments(this->FLATLINE);
    this->bottomDisplay->showNumberDec(
        (int) *this->radius,
        true
    );

}

void ConfigDisplay::done() {

    this->topDisplay->setSegments(this->DONE);
    this->bottomDisplay->setSegments(this->FLATLINE);

}

void ConfigDisplay::update() {

    this->bottomDisplay->showNumberDec(
        (int) *this->radius,
        true
    );
    
}
