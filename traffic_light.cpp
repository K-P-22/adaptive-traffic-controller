//traffic_light.cpp
#include "traffic_light.h"

TrafficLight::TrafficLight(int green, int yellow, int red) : 
state("RED"), timer(0), Greentime(green), Yellowtime(yellow), Redtime(red) {}

void TrafficLight::update(){
    timer++;

    if(state == "GREEN" && timer >= Greentime){
        state = "YELLOW";
        timer = 0;
    }
    else if(state == "YELLOW" && timer >= Yellowtime){
        state = "RED";
        timer = 0;
    }
    else if(state == "RED" && timer >= Redtime){
        state = "GREEN";
        timer = 0;
    }
}

string TrafficLight::getState() const{
    return state;
}

int TrafficLight::getTimer() const{
    return timer;
}

void TrafficLight::reset(){
    state = "RED";
    timer = 0;
}

void TrafficLight::setState(const string& newState){
    state = newState;
    timer = 0;
}


