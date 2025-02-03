#include "./main.h"
#include "./robotGlobalFunctions.hpp"

void testAngularPID(){
    mogo.set_value(true);
    pros::delay(1000);
    chassis.turnToHeading(90,1000);
}

void testLinearPID(){
    mogo.set_value(true);
    pros::delay(1000);
    chassis.moveToPoint(0,20,5000);
}
