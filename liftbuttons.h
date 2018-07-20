#ifndef LIFTBUTTONS_H
#define LIFTBUTTONS_H

#define NUMBER_OF_FLOORS 4

// Lift Buttons
class LiftButtons
{
public:
    LiftButtons();

    // turn light on for individual floor button in lift
    void LightOn(int i);
	// turn light off for individual floor button in lift
    void LightOff(int i);

private:
    bool buttons[NUMBER_OF_FLOORS]; // array of lift buttons limited by number of floors
};

#endif // LIFTBUTTONS_H
