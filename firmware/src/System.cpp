#include <Arduino.h>
#include <EEPROM.h>
#include "System.hpp"

System* System::instance = nullptr;

System::System() {

    this->radius = EEPROM.read(RADIUS_EEPROM_ADDRESS);

    this->hallSensor = new HallSensor();

    this->speedometer = new Speedometer(this->radius);
    this->hodometer = new Hodometer(this->radius);

    this->speedDisplay = new SpeedDisplay(this->speedometer);
    this->distanceDisplay = new DistanceDisplay(this->hodometer);

    this->leftButton = new PushButtonSensor(LEFT_BUTTON_PIN);
    this->rightButton = new PushButtonSensor(RIGHT_BUTTON_PIN);

    this->lastConfigState = false;
    this->configState = false;

}

System& System::getInstance() {
    if (!System::instance) {
        System::instance = new System();
    }

    return *System::instance;
}

System::~System() {
    delete hallSensor;
    delete speedometer;
    delete hodometer;
    delete speedDisplay;
    delete distanceDisplay;
    delete leftButton;
    delete rightButton;
    
    if (System::instance == this) {
        System::instance = nullptr;
    }
}

void System::setupListeners() {

    this->leftButton->addLongPressListener(System::staticToggleConfigMode);
    this->leftButton->addClickListener(System::staticOnLeftClick);
    this->rightButton->addClickListener(System::staticOnRightClick);

}

void System::setupDisplays() {

    this->distanceDisplay->setup();
    this->speedDisplay->setup();

}

void System::ISRHallSensorHit() {

    this->speedometer->ISRHallSensorHit();
    this->hodometer->ISRHallSensorHit();

}

void System::toggleConfigMode() {

    this->lastConfigState = configState;
    this->configState = !configState;

    Serial.print("Modo de configuração = ");
    Serial.print(this->configState ? "ativado" : "desativado");
    Serial.print("\n");

    if (this->configState) {

        Serial.print("Tamanho do raio atual: R = ");
        Serial.print(this->radius);
        Serial.print("cm");
        Serial.print("\n");

    }

    if (this->lastConfigState && !this->configState) {

        Serial.print("Atualizando o tamanho do raio: R = ");
        Serial.print(this->radius);
        Serial.print("cm");
        Serial.print("\n");

        EEPROM.write(RADIUS_EEPROM_ADDRESS, this->radius);
        this->hodometer->setRadius(this->radius);
        this->speedometer->setRadius(this->radius);

    }

}

void System::onLeftClick() {

    if (!this->configState) return;

    this->radius++;
    Serial.print("Tamanho do raio atual: R = ");
    Serial.print(this->radius);
    Serial.print("cm");
    Serial.print("\n");

}

void System::onRightClick() {

    if (!this->configState || this->radius == 1) return;

    this->radius--;

    Serial.print("Tamanho do raio atual: R = ");
    Serial.print(this->radius);
    Serial.print("cm");
    Serial.print("\n");

}

void System::run() {

    this->leftButton->read();
    this->rightButton->read();
    
}