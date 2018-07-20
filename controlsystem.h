// #pragma once - ask Byran whether it is good practice to use this instead of IFNDEF
#ifndef CONTROLSYSTEM_H
#define CONTROLSYSTEM_H

#include <iostream>

using namespace std;

#include "lift.h"
#include "liftbuttons.h"
#include "floordisplay.h"

#define NUMBER_OF_FLOORS 4 // set as constant, we dont want this to change
#define BOTTOM_FLOOR 1 // constant

const enum LIFTDIRECTION
{ 
	UP = 1, 
	DOWN = -1, 
	WAITING = 0 
};

// Lift Control System
class ControlSystem
{
public:
    ControlSystem();

    // Interface
    // User presses floor button
    void PressFloorButton(int floorFrom, int direction);
    // User presses lift button
    void PressLiftButton(int floorTo);
	// Set lift floor to value for testing ONLY
	void setLiftFloor(int liftReset);

private:
    // Set floors display States
    void SetFloorDisplays(int liftDirection, int floor);
private:
    Lift lift; // Lift object
    FloorDisplay floorDisplays[NUMBER_OF_FLOORS]; // create array of floor displays
};

#endif // CONTROLSYSTEM_H
