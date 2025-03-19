#ifndef PUSH_BUTTON_SENSOR_H

#define PUSH_BUTTON_SENSOR_H

class PushButtonSensor {
    private:

        uint8_t pin;

        bool lastState;
        bool currentState;

        unsigned long beginPressTime;

        void (* onClick)();
        void (* onLongPress)();

    public:

        PushButtonSensor(int pin);
        
        void read();
        void addClickListener(void (* onClick)());
        void addLongPressListener(void (* onLongPress)());

};

#endif