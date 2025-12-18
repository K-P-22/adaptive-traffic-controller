// main.cpp
#include <iostream>
#include <thread>
#include <chrono>
#include "traffic_light.h"

using namespace std;

int main(){
    TrafficLight northSouth(30, 5, 35);
    TrafficLight eastWest(35, 5, 30);
    

    // Start with North-South GREEN and East-West RED
    northSouth.setState("GREEN");
    eastWest.setState("RED");

    for(int time = 0; time < 200; time++){
    /*
    
    
    
    
    
    
    need to add functionality/logic for traffic lights
    
    
    
    
    
    
    
    
    */

    

        // Print status of the lights every 5 time units
            if(time % 5 == 0){
                cout << "Time: " << time << "s | North-South: " << northSouth.getState() << 
                " | East-West: " << eastWest.getState() << endl;
            }

            this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout << "Simulation complete." << endl;

    return 0;
}
