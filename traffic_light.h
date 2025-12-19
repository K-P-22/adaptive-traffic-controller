//traffic_light.h
#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H 

#include <string>

using namespace std;

class TrafficLight{
private:
    string state;  // Green, Yellow, or Red  (State of the Light)
    
    int timer = 0;     // Counts how long light has been in current state
    int Greentime;
    int Yellowtime;
    int Redtime;
    

public:
    //Constructor
    TrafficLight(int green = 30, int yellow = 5, int red = 35);

    //Update the state based on the timer
    void update();

    //Get current state
    string getState() const;

    //Get current timer time
    int getTimer() const;

    //Reset the timers when the light goes through a complete cycle
    void reset();

    void setState(const string& newState);

    int SecsRed();

};

#endif