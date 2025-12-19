// main.cpp
#include <iostream>
#include <thread>
#include <chrono>
#include "traffic_light.h"
// ANSI color codes for terminal output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define GRAY    "\033[90m"

using namespace std;

int main(){
    cout << "\n" << GREEN << "SMART TRAFFIC LIGHT SIMULATION " << RESET << endl;
    cout << GRAY << "---------------------------------------------" << RESET << endl;

    TrafficLight northSouth(30, 5, 43);
    TrafficLight eastWest(35, 5, 37);

    // Start with North-South GREEN and East-West RED
    northSouth.setState("GREEN");
    eastWest.setState("RED");

    string prevNS = northSouth.getState();
    string prevEW = eastWest.getState();

    for(int time = 0; time <= 200; time++){
        northSouth.update();
        eastWest.update();

        // --- detect a light turning RED ---
        bool nsToRed = (northSouth.getState() == "RED" && prevNS != "RED");
        bool ewToRed = (eastWest.getState() == "RED" && prevEW != "RED");

        if (nsToRed || ewToRed) {
            cout << "\n" << GRAY << ">>> All-Red Clearance Phase (2 seconds) <<<" << RESET << endl;

            // Set both lights RED
            northSouth.setState("RED");
            eastWest.setState("RED");

            // Show a live 2-second countdown on one line
            for (int i = 2; i >= 0; i--) {
                cout << "\rTime: " << time << "s | North-South: " << RED << "RED" << RESET
                 << " | East-West: " << RED << "RED" << RESET
                 << " | " << GRAY << "(All-Red " << i << "s remaining)" << RESET << flush;
                this_thread::sleep_for(chrono::seconds(1));
            }

            cout << "\rTime: " << time << "s | North-South: " << RED << "RED" << RESET
             << " | East-West: " << RED << "RED" << RESET
             << " | " << GRAY << "(All-Red complete!)" << RESET << endl;

            // Resume the next cycle
            if (nsToRed)
                eastWest.setState("GREEN");
            else if (ewToRed)
                northSouth.setState("GREEN");

            cout << GRAY << "---------------------------------------------" << RESET << endl;
        }



        prevNS = northSouth.getState();
        prevEW = eastWest.getState();

        // Choose colors based on current state
        string nsColor, ewColor;

        if (northSouth.getState() == "GREEN") nsColor = GREEN;
        else if (northSouth.getState() == "YELLOW") nsColor = YELLOW;
        else nsColor = RED;

        if (eastWest.getState() == "GREEN") ewColor = GREEN;
        else if (eastWest.getState() == "YELLOW") ewColor = YELLOW;
        else ewColor = RED;

        // Print colored states every 5 time units
        if(time % 2 == 1){ //Comment out if statement to see total status of light
            cout << "Time: " << time << "s | North-South: " << nsColor << northSouth.getState() << RESET
             << " | East-West: " << ewColor << eastWest.getState() << RESET << endl;
        }

        // sanity check
        if((northSouth.getState() == "GREEN" || northSouth.getState() == "YELLOW") &&
           (eastWest.getState() == "GREEN"  || eastWest.getState()  == "YELLOW")){
            cout << "Light ERROR!! | At Time: " << time << "s" << endl;
            cout << northSouth.getTimer() << " " << eastWest.getTimer() << endl;
            cout << "Simulation ended" << endl;
            return 1;
        }

        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout << "Simulation complete." << endl;
    return 0;
}
