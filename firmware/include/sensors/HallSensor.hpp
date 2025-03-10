#ifndef HALL_SENSOR_HEADER

#define HALL_SENSOR_HEADER

class HallSensor {
    private: 

        int pin;

    public:

        HallSensor();
        bool read(); 

    };

#endif
