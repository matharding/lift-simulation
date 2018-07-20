#include <iostream>
using namespace std;

#include "liftbuttons.h"

LiftButtons::LiftButtons(): buttons{0, 0, 0, 0} // initialise the all buttons in array to be off
{

}

void LiftButtons::LightOn(int i)
{
	// check if the light is not on
	if(!buttons[i - 1]) // toggle logic to turn button on if it is off (i-1 because array starts at 0)
    {
		// if the light is not on set it to on
        buttons[i - 1] = true;
        cout << "Lift button " << i << " light on" << endl;
    }
}

void LiftButtons::LightOff(int i)
{
	// check if the light is on
    if(buttons[i - 1]) // toggle logic to turn button on if it is off (i-1 because array starts at 0)
    {
		// if the light is on set it to off
        buttons[i - 1] = false;
        cout << "Lift button " << i << " light off" << endl;
    }
}
