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

        Hodometer();

        void setRadius(float radius);        
        void ISRHallSensorHit();
        
        float getDistance();

    };

#endif
