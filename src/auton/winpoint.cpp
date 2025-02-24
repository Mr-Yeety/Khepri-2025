#include "main.h"

void winpoint(){



    if(isRed){


   //Ring 1 - Bagel Stack
   intakeLockTask.suspend();
   mogoTask.resume();
   intakeLift.set_value(true);
   intakeStage1.move_voltage(-12000);
   chassis.moveToPoint(10.2,8.8,2000);
   while(chassis.isInMotion()){pros::delay(10);}

  intakeLift.set_value(false);
  




//Alliance Stake
   chassis.moveToPose(3,8,90,1000, {.forwards = false});
   chassis.moveToPoint(19.2,9.3,400);
   chassis.turnToHeading(0,250);
   chassis.moveToPose(15.7,-4.5,0,1800, {.forwards = false});
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


    mogoTask.suspend();

   


   pros::delay(6000);
   mogoTask.suspend();
    }else if(!isRed){

      //Ring 1 - Bagel Stack
   intakeLockTask.suspend();
   mogoTask.resume();
   intakeLift.set_value(true);
   intakeStage1.move_voltage(-12000);
   chassis.moveToPose(-8.7,15.6,-60,1900);
   while(chassis.isInMotion()){pros::delay(10);}

  intakeLift.set_value(false);
  




//Alliance Stake
   chassis.moveToPose(-3,8,-90,400, {.forwards = false});
   chassis.moveToPoint(-19.2,9.3,400);
   chassis.turnToHeading(0,250);
   chassis.moveToPose(-17.2,-4.5,0,1800, {.forwards = false});
   while(chassis.isInMotion()){pros::delay(10);}
   intakeStage2.move_voltage(-12000);
   pros::delay(100);
   intakeStage2.move_voltage(0);
   pros::delay(100);
   chassis.moveToPose(-19.7,22,0,1800);



//Mogo 1
   chassis.moveToPose(-5.7,22.4,-147.33,2000, {.forwards = false});
   intakeStage2.move_voltage(-12000);
   pros::delay(200);
   intakeStage2.move_voltage(0);
   chassis.moveToPoint(8.7,45.9,4000, {.forwards = false, .maxSpeed=50});




   //Ring 1

   chassis.moveToPoint(34.3,45.8,2000);
   intakeStage2.move_voltage(-12000);
   intakeStage1.move_voltage(-12000);
        pros::delay(100);

   //Mogo drop
   chassis.moveToPoint(-47.7,15.7,2000);
   mogoTask.suspend();
   while(chassis.isInMotion()){pros::delay(10);}
   mogo.set_value(false);
   intakeStage2.move_voltage(0);
   intakeStage1.move_voltage(0);
   





   //Mogo 2
   chassis.turnToPoint(-57.4,15.5,2000);
   chassis.moveToPoint(-57.4,15.5,2000);
   chassis.turnToHeading(-153.5,2000);
   pros::delay(250);
   
   chassis.moveToPoint(-39.3,50.3,3000, {.forwards = false, .maxSpeed=50});
   mogoTask.resume();

   //Ring 4
   chassis.turnToHeading(90,2000);
   intakeStage2.move_voltage(-12000);
   intakeStage1.move_voltage(-12000);
   chassis.moveToPoint(-68.6,49.1,2000);

   //Ladder
   chassis.turnToHeading(-350,2000);
   chassis.moveToPoint(-30.6,48.1,2000);
    target = states[2];



   


   mogoTask.suspend();

}
}