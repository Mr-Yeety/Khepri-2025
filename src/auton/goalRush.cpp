#include "main.h"


void goalRush(){

    chassis.setBrakeMode(MOTOR_BRAKE_HOLD);


  

    if(isRed){



        intakeLockTask.resume();


        intakeStage1.move_voltage(-12000);
        intakeStage2.move_voltage(-12000);

        chassis.moveToPose(-2.0,52.6,-36,5000, {.lead=0.15});
        liftControlTask.resume();
        target = states[2];
        while(chassis.isInMotion()){pros::delay(10);}
        target = states[4];
        pros::delay(400);
        chassis.turnToHeading(270,2000, {.direction=AngularDirection::CW_CLOCKWISE, .maxSpeed=90});
        chassis.moveToPoint(-18,52,3000);






        
        /*
        intakeLock=true;
        target = states[1];
        pros::delay(450);
        intakeStage2.move_voltage(-9000);
        pros::delay(300);
        intakeStage2.move_voltage(5000);
        pros::delay(100);
        intakeStage2.move_voltage(0);
        pros::delay(200);
        target = states[2];
        pros::delay(200);
        chassis.moveToPoint(0,48.9,2000, {.maxSpeed=127});
        intakeStage1.move_voltage(-12000);
        intakeStage2.move_voltage(-12000);
        while(chassis.isInMotion()){pros::delay(1);}
        target = states[4];
        pros::delay(150);
        chassis.turnToHeading(180,2000, {.direction=AngularDirection::CW_CLOCKWISE, .maxSpeed=90});
*/

        intakeLockTask.suspend();
        pros::delay(6000);

















    }else if(!isRed){
        std::cout << "Blue Goal Rush";
    }
}