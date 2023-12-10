#ifndef STEPPER_H
#define STEPPER_H

#include <iostream>
#include <chrono>
#include <thread>

class Stepper {
public:
    Stepper(int number_of_steps, int motor_pin_1, int motor_pin_2,
                                 int motor_pin_3, int motor_pin_4);

    void setSpeed(int newSpeed);

    void setDirection(int newDirection);

    void setPitch(int newPitch);

    void step(int number_of_steps);
};

#endif 
