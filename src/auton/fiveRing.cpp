#include "main.h"

void fiveRing(){


        //_________________________________RED__________________________________________________

    if(isRed){

        mogoTask.resume();
        intakeLockTask.suspend();
        chassis.moveToPoint(0,-42,2000,{.forwards = false, .maxSpeed=70});
        while(chassis.isInMotion()){pros::delay(10);}
        intake.move_velocity(-12000);

        chassis.turnToHeading(-300,2000);
        while(chassis.isInMotion()){pros::delay(10);}
        intake.move_velocity(0);
        mogoTask.suspend();
        chassis.moveToPoint(13.6,-25.6,3000);
        pros::delay(300);
        intake.move_velocity(-12000);


        chassis.turnToHeading(-194,2000);

        chassis.moveToPoint(21.8,-34.1,4000);

        chassis.moveToPoint(-18.7,-17.8,2000,{.maxSpeed=70});
        chassis.turnToHeading(-260,2000);

        intakeLift.set_value(true);
        chassis.moveToPoint(-26.7,-25.2,4000);
        while(chassis.isInMotion()){pros::delay(10);}
        intakeLift.set_value(false);
        chassis.moveToPoint(-16.0,-21.9,4000,{.forwards = false, .maxSpeed=70});

        pros::delay(3000);
        mogoTask.suspend();



 







    //_________________________________BLUE__________________________________________________
    }else if(!isRed){
        mogoTask.resume();
        intakeLockTask.suspend();
        chassis.moveToPoint(0,-42,2000,{.forwards = false, .maxSpeed=70});
        while(chassis.isInMotion()){pros::delay(10);}
        intake.move_velocity(-12000);

        chassis.turnToHeading(300,2000);
        while(chassis.isInMotion()){pros::delay(10);}
        intake.move_velocity(0);
        mogoTask.suspend();
        chassis.moveToPoint(-13.6,-25.6,3000);
        pros::delay(300);
        intake.move_velocity(-12000);


        chassis.turnToHeading(194,2000);

        chassis.moveToPoint(-21.8,-34.1,4000);

        chassis.moveToPoint(18.7,-17.8,2000,{.maxSpeed=70});
        chassis.turnToHeading(260,2000);

        intakeLift.set_value(true);
        chassis.moveToPoint(26.7,-25.2,4000);
        while(chassis.isInMotion()){pros::delay(10);}
        intakeLift.set_value(false);
        chassis.moveToPoint(16.0,-21.9,4000,{.forwards = false, .maxSpeed=70});

        pros::delay(3000);
        mogoTask.suspend();



    }

}