#ifndef SYSTEM_HEADER
#define SYSTEM_HEADER

#include "setup.hpp"
#include "config.hpp"
#include "pins.hpp"

#include "sensors/HallSensor.hpp"
#include "sensors/PushButtonSensor.hpp"

#include "meters/Speedometer.hpp"
#include "meters/Hodometer.hpp"

#include "displays/SpeedDisplay.hpp"
#include "displays/DistanceDisplay.hpp"
#include "displays/ConfigDisplay.hpp"

class System {

    private:

        HallSensor* hallSensor;

        Speedometer* speedometer;
        Hodometer*   hodometer;

        SpeedDisplay*    speedDisplay;
        DistanceDisplay* distanceDisplay;
        ConfigDisplay*   configDisplay;

        PushButtonSensor* leftButton;
        PushButtonSensor* rightButton;

        bool lastConfigState;
        bool configState;

        uint8_t radius;

        static System* instance;

        System();

        void onLeftClick();
        void onRightClick();
        void toggleConfigMode();

        static void staticToggleConfigMode() {
            if (System::instance) {
                System::instance->toggleConfigMode();
            }
        }

        static void staticOnLeftClick() {
            if (System::instance) {
                System::instance->onLeftClick();
            }
        }
        
        static void staticOnRightClick() {
            if (System::instance) {
                System::instance->onRightClick();
            }
        }

    public:

        static System& getInstance();

        ~System();

        void setupDisplays();
        void setupListeners();
        void ISRHallSensorHit();
        void run();

};

#endif