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
        unsigned long resetTimeThreshold;

        volatile bool isNewDataAvailable;

        void updateCircumferenceSize();

    public:

        Speedometer();

        void setRadius(float radius);        
        void resetTrigger();
        void ISRHallSensorHit();
        
        float getVelocity();

    };

#endif
