#include <iostream>
#include <queue> // use FIFO queue idea to store requests? need to research this

using namespace std;

#include "controlsystem.h"

int main()
{
    ControlSystem control; // instantiate the control system

	// TEST 1 - CALL LIFT FROM FLOOR 1, TRAVEL TO FLOOR 3 - LIFT STARTS AT FLOOR 4
	cout << "----------------------------------------------------" << endl;
	cout << "TEST 1 - CALL LIFT FROM FLOOR 1, TRAVEL TO FLOOR 3 - LIFT STARTS AT FLOOR 4" << endl;
	control.setLiftFloor(4); // start the lift at floor 4 in the building
    control.PressFloorButton(1, UP); // passenger presses down call button on floor 4
    control.PressLiftButton(3); // passenger in lift requests floor 3
	cout << "----------------------------------------------------" << endl;
	cout << endl;
	cin.get();

	// TEST 2 - CALL LIFT FROM FLOOR 1, TRAVEL TO FLOOR 2 - LIFT STARTS AT FLOOR 3
	cout << "----------------------------------------------------" << endl;
	cout << "TEST 2 - CALL LIFT FROM FLOOR 1, TRAVEL TO FLOOR 2 - LIFT STARTS AT FLOOR 3" << endl;
	control.setLiftFloor(3); // start the lift at floor 3 in the building
    control.PressFloorButton(1, UP); // passenger presses up call button on floor 1
    control.PressLiftButton(2); // passenger in lift requests floor 2
	cout << "----------------------------------------------------" << endl;
	cout << endl;
	cin.get();

	// TEST 3 - CALL LIFT FROM FLOOR 3, TRAVEL TO FLOOR 5 - LIFT STARTS AT FLOOR 2
	cout << "----------------------------------------------------" << endl;
	cout << "TEST 3 - CALL LIFT FROM FLOOR 3, TRAVEL TO FLOOR 5 - LIFT STARTS AT FLOOR 2" << endl;
	control.setLiftFloor(2); // start the lift at floor 2 in the building
	control.PressFloorButton(3, UP); // passenger presses up call button on floor 1
	control.PressLiftButton(5); // passenger in lift requests floor 5
	cout << "----------------------------------------------------" << endl;
	cout << endl;
	cin.get();

	// TEST 4 - CALL LIFT FROM FLOOR 4,  TO FLOOR 0 - LIFT STARTS AT FLOOR 1
	cout << "----------------------------------------------------" << endl;
	cout << "TEST 4 - CALL LIFT FROM FLOOR 4, TRAVEL TO FLOOR 0 - LIFT STARTS AT FLOOR 1" << endl;
	control.setLiftFloor(1); // start the lift at floor 4 in the building
	control.PressFloorButton(4, DOWN); // passenger press up call button on floor 1 
	control.PressLiftButton(0); // passenger in lift requests floor 0
	cout << "----------------------------------------------------" << endl;
	cout << endl;
	cin.get();

	// TEST 5 - TEST PASSENGER PRESSING LIFT REQUEST FOR FLOOR LIFT IS ALREADY ON
	cout << "----------------------------------------------------" << endl;
	cout << "TEST 5 - CALL LIFT FROM FLOOR 4 WHEN LIFT IS ALREADY AT FLOOR 4" << endl;
	control.setLiftFloor(4); // start the lift at floor 4 in the building
	control.PressLiftButton(4);
	cout << "----------------------------------------------------" << endl;
	cout << endl;
	cin.get();

	// TEST 6 - TEST PASSENGER REQUESTING UP WHEN ALREADY ON TOP FLOOR
	cout << "----------------------------------------------------" << endl;
	cout << "TEST 6 - CALL LIFT FROM TOP FLOOR AND SELECT UP" << endl;
	control.setLiftFloor(4); // start the lift at floor 4 in the building
	control.PressFloorButton(4, UP);
	cout << "----------------------------------------------------" << endl;
	cout << endl;
	cin.get();

	// TEST 7 - TEST PASSENGER REQUESTING DOWN WHEN ALREADY ON GROUND FLOOR
	cout << "----------------------------------------------------" << endl;
	cout << "TEST 7 - CALL LIFT FROM BOTTOM AND SELECT DOWN" << endl;
	control.setLiftFloor(1); // start the lift at floor 4 in the building
	control.PressFloorButton(1, DOWN);
	cout << "----------------------------------------------------" << endl;
	cout << endl;
	cin.get();

	// TEST 8 - LIFT CALLED BUT NOBODY GETS IN, GOES IDLE
	cout << "----------------------------------------------------" << endl;
	cout << "TEST 8 - CALL LIFT AND DONT BOARD" << endl;
	control.setLiftFloor(4); // start the lift at floor 4 in the building
	control.PressFloorButton(4, DOWN); // passenger press up call button on floor 1 
	cout << "----------------------------------------------------" << endl;
	cout << endl;
	cin.get();

    system("pause");
    return 0;
}
