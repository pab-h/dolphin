#ifndef HODOMETER_HEADER

#define HODOMETER_HEADER

class Hodometer {

    private:

        float radius;
        float circumferenceSize;
        float distance;
        
        volatile unsigned long lastMeasureTime;

        volatile bool isNewDataAvailable;

        void updateCircumferenceSize();

    public:

        Hodometer(uint8_t radius);

        void setRadius(uint8_t radius);        
        float getDistance();

        void ISRHallSensorHit();

        void reset();

    };

#endif
