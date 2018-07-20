#ifndef FLOORDISPLAY_H
#define FLOORDISPLAY_H

// Floor Display
class FloorDisplay
{
public:
    FloorDisplay();

    // Set Floor Display State
    void SetState(int liftDirection, int floor);
    // Print Floor Display State
    void PrintState();

private:
    int liftDirection;
    int floor;
};

#endif // FLOORDISPLAY_H
