#ifndef HALL_SENSOR_HEADER

#define HALL_SENSOR_HEADER

class HallSensor {
    private: 

        uint8_t pin;

    public:

        HallSensor();
        
        bool read(); 

    };

#endif
