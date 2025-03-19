#include <Arduino.h>

#include "sensors/PushButtonSensor.hpp"

#include "constants.hpp"
#include "config.hpp"

PushButtonSensor::PushButtonSensor(int pin) {

    this->pin = pin;

    this->lastState    = false;
    this->currentState = false;

    this->beginPressTime = 0;

    this->onLongPress = nullptr;
    this->onClick     = nullptr;

}

void PushButtonSensor::addClickListener(void (* onClick)()) {
  this->onClick = onClick;
}

void PushButtonSensor::addLongPressListener(void (* onLongPress)()) {
  this->onLongPress = onLongPress;
}

void PushButtonSensor::read() {

  this->lastState = this->currentState;
  this->currentState = digitalRead(this->pin);

  if (!this->lastState && this->currentState) {
    this->beginPressTime = millis();
  }

  if (this->lastState && !this->currentState) {

    if (millis() - this->beginPressTime <= CLICK_PRESS_THRESHOLD) {
      if (this->onClick != nullptr) {
        this->onClick();
        return;
      }
    }

    if (millis() - this->beginPressTime >= LONG_PRESS_THRESHOLD) {
      if (this->onLongPress != nullptr) {
        this->onLongPress();
        return;
      }
    }

  }

}
