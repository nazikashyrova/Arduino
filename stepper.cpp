#include "stepper.h"

int main() {
    const int motorPin1 = 2;
    const int motorPin2 = 3;
    const int motorPin3 = 4;
    const int motorPin4 = 5;

    Stepper myMotor(10, 1000, motorPin1, motorPin2, motorPin3, motorPin4);

    myMotor.setSpeed(5);    // Set motor speed (adjust as needed)
    myMotor.setDirection(1); // Set motor direction (1 for forward, -1 for backward)
    myMotor.setPitch(500);   // Set motor pitch (adjust as needed)

    // Perform steps (simulate motor steps)
    for (int i = 0; i < 10; ++i) {
        myMotor.step();
    }

    return 0;
}
