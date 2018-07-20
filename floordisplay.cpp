#include <iostream>
using namespace std;

#include "floordisplay.h"

FloorDisplay::FloorDisplay()
{

}

// method to set the floor displays with lift direction and current floor of lift
void FloorDisplay::SetState(int liftDirection, int floor)
{
    this->liftDirection = liftDirection;
    this->floor = floor;
}

void FloorDisplay::PrintState()
{
    if(liftDirection > 0)
    {
        cout << "Lift going up - from floor " << floor << " to " <<  floor + 1 << endl;
    }
    else if(liftDirection < 0)
    {
        cout << "Lift going down - from floor " << floor << " to " <<  floor - 1 << endl;
    }
    else
    {
        cout << "Lift Waiting at floor " << floor << endl;
    }
}
