#ifndef DOORS_H
#define DOORS_H

// Lift doors
class Doors
{
public:
    Doors();

    // Open doors
    void Open();

    // Close doors
    void Close();

    // Print open/close
    void PrintState();

private:
    bool isOpen;
};

#endif // DOORS_H
