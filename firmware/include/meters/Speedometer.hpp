#ifndef SPEEDOMETER_HEADER

#define SPEEDOMETER_HEADER

class Speedometer {

    private:

        float radius;
        float circumferenceSize;
        float velocity;
        
        volatile unsigned long lastHitHallSensorTime;
        volatile unsigned long currentHitHallSensorTime;
        unsigned long hitHallSensorPeriod;
        
        volatile unsigned long lastMeasureTime;

        volatile bool isNewDataAvailable;

        void updateCircumferenceSize();

    public:

        Speedometer(uint8_t radius);

        void setRadius(float radius);        
        void resetTrigger();
        void ISRHallSensorHit();
        
        float getVelocity();

    };

#endif
