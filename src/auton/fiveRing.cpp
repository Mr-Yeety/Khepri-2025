#include "main.h"

void fiveRing(){


        //_________________________________RED__________________________________________________

    if(isRed){
        liftControlTask.resume();
        intakeLockTask.suspend();
        target= states[2];
        chassis.turnToHeading(45.5,2000);
        chassis.moveToPoint(6.0,6.2,3000,{.forwards=true});
        while(chassis.isInMotion()){pros::delay(10);}
        target= states[4];
        pros::delay(300);

        chassis.moveToPoint(-5.7,-2.5,3000,{.forwards = false, .maxSpeed=127,.minSpeed=127});
        chassis.moveToPoint(-30.7,-7.9,3000,{.forwards = false,.maxSpeed=127,.minSpeed=127});
        target = states[0];
        intake.move_voltage(12000);
        pros::delay(300);
        intake.move_voltage(-12000);

        chassis.moveToPose(-44.4,-17.7,204,3000);
        chassis.moveToPoint(-46,-32.5,3000,{.forwards = true,.maxSpeed=127,.minSpeed=127});

        chassis.moveToPoint(-28,-34,3000,{.forwards = true,.maxSpeed=127,.minSpeed=127});


      
        pros::delay(6000);
        mogoTask.suspend();




    //_________________________________BLUE__________________________________________________
    }else if(!isRed){

    //Mogo 1
    chassis.moveToPoint(0.00, 17.37, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Intermediate
    chassis.moveToPoint(1.88, 26.77, 2000, {.forwards = false, .maxSpeed = 127, .minSpeed = 0}); //  Mogo, backwards approach, Ring 1
    //Mogo Task will clamp on to the Mogo
    
    //2 Rings on the white lines
    chassis.moveToPoint(19.72, 48.83, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Ring 2
    mogoTask.suspend(); //mogo task suspend
    chassis.moveToPoint(28.17, 49.77, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Ring 3

    //Ring Stack -  We want the bottom one
    chassis.moveToPoint(30.52, 36.63, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Ring 4

    //Corner Ring - We want the bottom one
    chassis.moveToPoint(30.05, 13.62, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 7
    chassis.moveToPoint(41.32, 2.82, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 8
    chassis.moveToPoint(9.86, 14.56, 2000, {.forwards = false, .maxSpeed = 127, .minSpeed = 0}); // Point 9
    
    //Ring Stack - We want top one
    intakeLift.set_value(true); //Intake lift up
    chassis.moveToPoint(-8.45, 14.56, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 10
    intakeLift.set_value(false);//Intake lift down
    chassis.moveToPoint(-6, 14.56, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Point 10

    


    }

}