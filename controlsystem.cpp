#include "controlsystem.h"
#include <windows.h>


ControlSystem::ControlSystem():
    lift(), 
    floorDisplays()
{
	lift.PrintDoorsState();
}

void ControlSystem::setLiftFloor(int liftReset)
{
	lift.setFloor(liftReset);
}

void ControlSystem::PressFloorButton(int floor, int direction)
{
	// check if lift button pressed is valid and within floors that exist range
	if (floor > NUMBER_OF_FLOORS || floor < BOTTOM_FLOOR)
	{
		cout << "Floor " << floor << " is an invalid floor selection, please select again" << endl;
		return;
	}
	
	if (floor == 4 && direction == UP)
	{
		cout << "Request to go up from floor " << floor << " cannot go up further " << endl;
		return;
	}

	if (floor == 1 && direction == DOWN)
	{
		cout << "Request to go down from floor " << floor << " cannot go down further " << endl;
		return;
	}

	// Output floor button status, use ternary operator if greater than 0 it's up
	// if less than 0 we are going down
	cout << "Floor " << floor << " Button pressed - passenger requesting " << (direction > 0 ? "Up" : "Down") << endl;

    if(lift.getFloor() < floor) // if the lift is below the floor call
    {
		lift.CloseDoors();
        SetFloorDisplays(UP, lift.getFloor()); // show lift going up from current lift floor
        lift.SetDirection(UP); // set the lift to go up
    }
    else if(lift.getFloor() > floor) // if the lift is above the floor call
    {
		lift.CloseDoors();
        SetFloorDisplays(DOWN, lift.getFloor()); // show lift going down from current lift floor
        lift.SetDirection(DOWN); // set the lift to go down
	}
    else
    {
        SetFloorDisplays(WAITING, lift.getFloor()); // set display to show lift is already here at floor
    }

	// main movement loop to call lift to waiting passenger

    while(lift.getFloor() != floor) // while current floor and destination floor are not the same
    {
        if(lift.getFloor() < floor) // if the lift is below floor request
        {
            SetFloorDisplays(UP, lift.getFloor()); // show lift going up from current lift floor
            lift.SetDirection(UP); // move the lift up
        }
        else if(lift.getFloor() > floor) // if the lift is above floor request
        {
            SetFloorDisplays(DOWN, lift.getFloor()); // show lift going down from current lift floor
            lift.SetDirection(DOWN); // move the lift down
        }
    }

    lift.SetDirection(WAITING); // lift has now arrived, set waiting status
	
	lift.OpenDoors(); // open doors, exception will occur if motor running

	int motorStatus = lift.GetDirection();
	cout << "motor status is " << motorStatus << endl; // motor status output
	SetFloorDisplays(WAITING, lift.getFloor()); // update floor displays with lift status
}

void ControlSystem::PressLiftButton(int floor)
{
	// check if lift button pressed is valid and within floors that exist range
	if (floor > NUMBER_OF_FLOORS || floor < BOTTOM_FLOOR)
	{
		cout << "Floor " << floor << " is an invalid floor selection, please select again" << endl;
		return;
	} 

    cout << "Lift Button " << floor << " pressed"<< endl;
    lift.LightsOn(floor); // illuminate the floor destination button in the lift

    if(lift.getFloor() > floor) // if the lift is above the destination floor
    {
		lift.CloseDoors();
        SetFloorDisplays(DOWN, lift.getFloor()); // show we are going down
        lift.SetDirection(DOWN); // move the lift down
    }
    else if(lift.getFloor() < floor) // if the lift is below the destination floor
    {
		lift.CloseDoors();
        SetFloorDisplays(UP, lift.getFloor()); // show we are going up
        lift.SetDirection(UP); // move the lift up
    }
    else
    {
        SetFloorDisplays(WAITING, lift.getFloor()); // show waiting, we are already at the requested floor
		lift.OpenDoors();
    }

	// main movement loop inside lift after requesting floor

    while(lift.getFloor() != floor)
    {
        if(lift.getFloor() < floor) // we need to go up
        {
            SetFloorDisplays(UP, lift.getFloor());
            lift.SetDirection(UP);
        }
        else if(lift.getFloor() > floor) // we need to go down
        {
            SetFloorDisplays(DOWN, lift.getFloor());
            lift.SetDirection(DOWN);
        }
    }

	// stop the lift, turn of floor lights, update display and open doors
    lift.SetDirection(WAITING); // disable motor
    lift.LightsOff(floor); // turn off floor light in lift
	lift.OpenDoors(); // open the doors
	cout << "Lift waits for 10 seconds for passenger to alight --------------" << endl;
	lift.CloseDoors();
	SetFloorDisplays(WAITING, lift.getFloor()); // turn off light on floors
 }

// update all lift status displays on all floors

void ControlSystem::SetFloorDisplays(int liftDirection, int floor)
{
    for(int i = 0; i < NUMBER_OF_FLOORS; i++)
    {
        floorDisplays[i].SetState(liftDirection, floor); // set array elements with lift info
    }
    cout << "Floor displays: ";
    floorDisplays[0].PrintState(); // show the status of floor displays to console
}
