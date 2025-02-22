#include "main.h"

void winpoint(){



    if(isRed){


   //Ring 1 - Bagel Stack
   intakeLockTask.suspend();
   mogoTask.resume();
   intakeLift.set_value(true);
   intakeStage1.move_voltage(-12000);
   chassis.moveToPose(8.7,15.6,60,1900);
   while(chassis.isInMotion()){pros::delay(10);}

  intakeLift.set_value(false);
  




//Alliance Stake
   chassis.moveToPose(3,8,90,400, {.forwards = false});
   chassis.moveToPoint(19.2,9.3,400);
   chassis.turnToHeading(0,250);
   chassis.moveToPose(17.2,-4.5,0,1800, {.forwards = false});
   while(chassis.isInMotion()){pros::delay(10);}
   intakeStage2.move_voltage(-12000);
   pros::delay(200);
   intakeStage2.move_voltage(0);
   pros::delay(100);
   chassis.moveToPose(19.7,22,0,1800);



//Mogo 1
   chassis.moveToPose(5.7,22.4,147.33,2000, {.forwards = false});
   intakeStage2.move_voltage(-12000);
   pros::delay(200);
   intakeStage2.move_voltage(0);
   chassis.moveToPoint(-8.7,45.9,4000, {.forwards = false, .maxSpeed=50});




   //Ring 1

   chassis.moveToPoint(-34.3,45.8,2000);
   intakeStage2.move_voltage(-12000);
   intakeStage1.move_voltage(-12000);
        pros::delay(100);

   //Mogo drop
   chassis.moveToPoint(47.7,15.7,2000);
   mogoTask.suspend();
   while(chassis.isInMotion()){pros::delay(10);}
   mogo.set_value(false);
   intakeStage2.move_voltage(0);
   intakeStage1.move_voltage(0);
   





   //Mogo 2
   chassis.turnToPoint(57.4,15.5,2000);
   chassis.moveToPoint(57.4,15.5,2000);
   chassis.turnToHeading(153.5,2000);
   pros::delay(250);
   
   chassis.moveToPoint(39.3,50.3,3000, {.forwards = false, .maxSpeed=50});
   mogoTask.resume();

   //Ring 4
   chassis.turnToHeading(90,2000);
   intakeStage2.move_voltage(-12000);
   intakeStage1.move_voltage(-12000);
   chassis.moveToPoint(68.6,49.1,2000);

   //Ladder
   chassis.turnToHeading(350,2000);
   chassis.moveToPoint(30.6,48.1,2000);
        target = states[2];



   


   pros::delay(6000);
   mogoTask.suspend();




    



    }else if(!isRed){
    //Ring One - Bagel Stack (Intake Lift)
    intakeLift.set_value(true);
    intakeStage1.move_voltage(-12000);
    chassis.moveToPoint(-9.1,11.5,1900, {.forwards = true, .maxSpeed=127, .minSpeed=50});
    while(chassis.isInMotion()){pros::delay(10);}
    intakeLift.set_value(false);
    chassis.moveToPoint(-7,11.5,1900, {.forwards = false, .maxSpeed=127, .minSpeed=50});


//Alliance Stake
    chassis.moveToPose(-3,8.9,270,400, {.forwards = false,.maxSpeed=127, .minSpeed=50});
    chassis.moveToPoint(-19.2,9.3,400, {.forwards = true,.maxSpeed=127, .minSpeed=50});
    chassis.turnToHeading(0,250,{.maxSpeed=127, .minSpeed=127});
    chassis.moveToPose(-16.7,-3,0,1800, {.forwards = false,.maxSpeed=127});
    while(chassis.isInMotion()){pros::delay(10);}
    intakeStage2.move_voltage(-12000);
    pros::delay(200);
    intakeStage2.move_voltage(0);


    //Mogo 1
    chassis.moveToPoint(-8.3,23.8,4000, {.forwards = true});
    chassis.moveToPoint(7.7,46.9,4000, {.forwards = false});
    while(chassis.isInMotion()){pros::delay(10);}
    intakeStage2.move_voltage(-12000);



    //Ring 2
    chassis.moveToPoint(25.6,44.4,4000, {.forwards = true});

    //Mogo Drop
    mogoTask.suspend();
    chassis.moveToPoint(-7,30,1900, {.forwards = false, .maxSpeed=127, .minSpeed=127, .earlyExitRange=10});
    
    
    chassis.moveToPoint(-44,30,1900, {.forwards = false, .maxSpeed=127, .minSpeed=127});
    pros::delay(250);
    mogo.set_value(false);
    intakeStage2.move_voltage(12000);
    intakeStage1.move_voltage(12000);





    //Mogo 2
    chassis.turnToPoint(-31,61.3,1000, {.forwards = false});
    chassis.moveToPoint(-31,61.3,2000, {.forwards = false});
    intakeStage2.move_voltage(0);
    mogoTask.resume();


    //Ring 3
    chassis.moveToPoint(-61,50,4000, {.forwards = true,.maxSpeed=127, .minSpeed=50});
    intakeStage2.move_voltage(-12000);
    intakeStage1.move_voltage(-12000);
    pros::delay(500);



    //Ladder
    chassis.moveToPoint(-28.9,58.8,4000, {.forwards = false,.maxSpeed=127, .minSpeed=50});
    while(chassis.isInMotion()){pros::delay(10);}
    target = states[1];
 

    //mogoTask.suspend();
    }
}