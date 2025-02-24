#include "./main.h"
#include "./robotGlobalFunctions.hpp"

void testAngularPID(){
    mogo.set_value(true);
    pros::delay(1000);
    chassis.turnToHeading(90,100000);
}

void testLinearPID(){
    mogo.set_value(true);
    pros::delay(1000);
    chassis.moveToPoint(0,10,5000);
}

void driveForwards(){
    chassis.moveToPoint(0,5,2000);
}
