#include <iostream>
using namespace std;
#include "doors.h"

Doors::Doors() : isOpen(false) // initialise member variable with closed doors
{

}

void Doors::Open()
{
    if(!isOpen) // if the door state is closed then we open them
    {
        isOpen = true;
        cout << "Doors open\n";
    }
	else cout << "Doors already open" << endl;
}

void Doors::Close()
{
    if(isOpen) // if the door state is open we close them
    {
        isOpen = false;
        cout << "Doors close\n";
    }
	else cout << "Doors already closed" << endl;
}

void Doors::PrintState() // print the state of the doors
{
    cout << "Doors are " << (isOpen ? "open" : "closed") << endl;
}
