#include <Arduino.h>

#include "System.hpp"
#include "pins.hpp"

System& sys = System::getInstance();

void ISRHallSensorHitWrapper() {
  sys.ISRHallSensorHit();
}

void setup() {

  setupPins();

  sys.setupDisplays();

  attachInterrupt(
    digitalPinToInterrupt(HALL_SENSOR_PIN),
    ISRHallSensorHitWrapper,
    RISING 
  );

  sys.setupListeners();

}


void loop() {

  sys.run(); 

}
