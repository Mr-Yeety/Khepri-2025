#include "main.h"

void fiveRing(){


        //_________________________________RED__________________________________________________

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
    chassis.moveToPose(3,9.1,90,400, {.forwards = false});
    chassis.moveToPoint(19.2,9.3,400);
    chassis.turnToHeading(0,250);
    chassis.moveToPose(17.7,-3,0,1800, {.forwards = false});
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



    

//Ring 2
        chassis.turnToHeading(311,2000,{.maxSpeed=60});
        intakeStage2.move_voltage(-12000);
        intakeStage1.move_voltage(-12000);
        chassis.moveToPoint(-20.6,59.8,2000);

//Ring 3  
        chassis.turnToHeading(285,2000);
        chassis.moveToPoint(-29.4,61.3,2000);
        chassis.turnToHeading(270,2000);

//Ring 4
        chassis.moveToPoint(-35,61.4,2000);
        chassis.turnToHeading(141,2000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE});
        chassis.moveToPoint(-34.3,45.8,2000);





        
/*

        


   

      



        chassis.moveToPose(-47.5,-22.4,228,3000,{.minSpeed=90}); // Ring 1
        intake.move_voltage(-12000);
        chassis.moveToPose(-34.0,-9,175,3000,{.forwards=false}); // Ring 2
        chassis.moveToPoint(-34,-25,3000,{.minSpeed=90}); // Ring 2
   

        chassis.moveToPose(-7.3,0.9,0,3000); // Ring 2 
        chassis.moveToPoint(-8.3,9.8,3000,{.minSpeed=50}); // Ring 2
        intake.move_voltage(-12000);
        intakeLift.set_value(true);
        while(chassis.isInMotion()){pros::delay(1);}
        intakeLift.set_value(false);
        chassis.moveToPose(-6.1,-6.7,16,3000,{.forwards=false}); // Ring 2 





*/

        




    


        






/*
        chassis.moveToPoint(-27.1,-13.4,3000,{.forwards = false,.maxSpeed=127,.minSpeed=127});
        intake.move_voltage(12000);
        pros::delay(200);
        intake.move_voltage(-12000);

        chassis.moveToPoint(-35.1,-14.5,2000);
    
        chassis.moveToPoint(-45.6,-16.9,2000);
        chassis.moveToPoint(-50.5,-34.2,2000);
        
        chassis.moveToPoint(-40.5,-19.6,2000,{.forwards = false});
        chassis.turnToHeading(215,2000);
        chassis.moveToPoint(-47.6,-30.2,2000,{.maxSpeed=127,.minSpeed=127});











        chassis.moveToPoint(-35.8,-12,2000);
        chassis.moveToPoint(-45.2,-24.3,2000);
        
        chassis.moveToPoint(-39.4,-19.2,2000,{.forwards=false});
     



        target = states[0];
        intake.move_voltage(12000);
        pros::delay(300);
        intake.move_voltage(-12000);

        chassis.moveToPose(-44.4,-17.7,204,3000);
        chassis.moveToPoint(-46,-32.5,3000,{.forwards = true,.maxSpeed=127,.minSpeed=127});

        chassis.moveToPoint(-28,-34,3000,{.forwards = true,.maxSpeed=127,.minSpeed=127});

*/
      
        pros::delay(6000);
        mogoTask.suspend();




    //_________________________________BLUE__________________________________________________
    }else if(!isRed){

    //Ring 1 - Bagel Stack
    intakeLockTask.suspend();
    mogoTask.resume();
    intakeLift.set_value(true);
    intakeStage1.move_voltage(-12000);
    chassis.moveToPose(8.7,15.6,60,1900);
    while(chassis.isInMotion()){pros::delay(10);}

   intakeLift.set_value(false);
   




//Alliance Stake
    chassis.moveToPose(3,9.1,90,400, {.forwards = false});
    chassis.moveToPoint(19.2,9.3,400);
    chassis.turnToHeading(0,250);
    chassis.moveToPose(17.7,-3,0,1800, {.forwards = false});
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



    

//Ring 2
        chassis.turnToHeading(311,2000,{.maxSpeed=60});
        intakeStage2.move_voltage(-12000);
        intakeStage1.move_voltage(-12000);
        chassis.moveToPoint(-20.6,59.8,2000);

//Ring 3  
        chassis.turnToHeading(285,2000);
        chassis.moveToPoint(-29.4,61.3,2000);
        chassis.turnToHeading(270,2000);

//Ring 4
        chassis.moveToPoint(-35,61.4,2000);
        chassis.turnToHeading(141,2000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE});
        chassis.moveToPoint(-34.3,45.8,2000);





    


    }

}