#include <iostream>
using namespace std;

#include "lift.h"

Lift::Lift() :
	floor(1), // initialise the lift to start at floor 1
	motor(),
	liftButtons(),
	doors()
{

}


void Lift::SetDirection(int direction)
{
    motor.setDirection(direction); // tell the motor which direction to go

	// move the lift and show updates to console
    if(direction > 0)
    {
        cout << "Lift leaves floor " << floor << endl;
        floor++;
        cout << "Lift reaches floor " << floor << endl;
    }
    else if(direction < 0)
    {
        cout << "Lift leaves floor" << floor << endl;
        floor--;
        cout << "Lift reaches floor " << floor << endl;
    }
    else
    {
        cout << "Lift stopped at floor " << floor << endl;
    }

}
