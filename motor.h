#ifndef MOTOR_H
#define MOTOR_H

// Motor
class Motor
{
public:
    Motor();

    // Set direction of motor, values accepted 0 = waiting, -1 = down, 1 = up
    void setDirection(int direction)
    {
        this->direction = direction;
    }

	// Return which direction the lift is currently going
    int getDirection()
    {
        return direction;
    }

private:
    int direction;
};

#endif // MOTOR_H
