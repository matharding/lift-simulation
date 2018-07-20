#ifndef LIFT_H
#define LIFT_H

#include "motor.h"
#include "doors.h"
#include "liftbuttons.h"

#define NUMBER_OF_FLOORS 4

// Lift
class Lift
{
public:
    Lift();

    // set direction of move
    void SetDirection(int direction);

	// get floor number
    int getFloor()
    {
        return floor;
    } 

	// set floor number used for testing
	void setFloor(int floorReset)
	{
		floor = floorReset;
	}

	// get floor direction
	int GetDirection()
	{
		return motor.getDirection(); // get the direction the lift is travelling from motor object
	}

	// return whether motor is engaged (TRUE) or not (FALSE)
	bool motorEngaged()
	{
		int status = motor.getDirection();
		if (status != 0)
		{
			return true;
		}
		else return false;
	}

	// turn a lift intenal floor button off
	void LightsOff(int Floor)
	{
		liftButtons.LightOff(Floor); // get the value from liftButtons object
	}

	// turn a lift internal floor button on
	void LightsOn(int Floor)
	{
		liftButtons.LightOn(Floor); // get the value from liftButtons object
	}

	// print whether doors are open or closed to console
	void PrintDoorsState()
	{
		doors.PrintState(); // get the value from the doors object
	}

	void OpenDoors()
	{
		if (motorEngaged())
		{
			cout << "Motor is engaged we cannot open doors, call emergency" << endl;
			throw std::exception();
		}
		else
		{
			cout << "Motor is not engaged we can open doors" << endl;
			doors.Open(); // open method within doors object
		}
	}

	void CloseDoors()
	{
		doors.Close(); // close method within doors object
	}

private:
    int         floor; // current floor for the lift
    Motor       motor; // motor object for this lift
	LiftButtons	liftButtons; // internal floor buttons for this lift
	Doors		doors; // doors for this lift
};

#endif // LIFT_H
