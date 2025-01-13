#include "main.h"

double scarabDrive::driveCurve(double input, double curve){
        return (std::pow(2.718, -(curve / 10)) + std::pow(2.718, (std::abs(input) - 127) / 10) * (1 - std::pow(2.718, -(curve / 10)))) * input;
}

void scarabDrive::joyDrive(double linearCurve, double rotationalCurve){

    int power = scarabDrive::driveCurve(master.get_analog(ANALOG_LEFT_Y), linearCurve);
    int turn = scarabDrive::driveCurve(master.get_analog(ANALOG_RIGHT_X), rotationalCurve);

    leftDrive.move_voltage((power + turn) * (12000.0 / 127));
    rightDrive.move_voltage((power - turn) * (12000.0 / 127));
}