#include "main.h";

void skillsAuton(){
    intake.move_voltage(-12000);
    pros::delay(250);
    chassis.moveToPoint(-0.1,20.1, 4000, {.forwards=true});




//_______________________________________________________________________________________

// Mogo 1

    chassis.moveToPoint(17.8,18.5,4000, {.forwards=false, .maxSpeed=110});
    pros::delay(1400);
    mogo.set_value(true);
    pros::delay(250);
    intakeStage2.move_voltage(12000);
    pros::delay(500);
    intakeStage2.move_voltage(-12000);



    

    //Ring 1
    chassis.moveToPoint(22,35.5,4000, {.forwards=true, .minSpeed=95});


    //Ring 2
    chassis.moveToPoint(45,69,4000, {.forwards=true, .maxSpeed=75});
    chassis.moveToPoint(58,69,4000, {.forwards=true, .maxSpeed=95});


    //Ring 3
    chassis.moveToPoint(50.5,45.3,4000, {.forwards=true, .maxSpeed=70});

    //Rings 4 and 5
    chassis.moveToPoint(50,24.3,4000, {.forwards=true, .maxSpeed=80});
    chassis.moveToPoint(50,11.4,4000, {.forwards=true, .maxSpeed=70});

//Ring 6 
    chassis.moveToPoint(60.5,16.3,4000, {.forwards=true, .maxSpeed=80});

//Corner Mogo
    chassis.moveToPoint(65,5.4,4000, {.forwards=false, .maxSpeed=80});
    pros::delay(1000);
    mogo.set_value(false);
    intakeStage2.move_voltage(12000);




//______________________________________________________________________________________

    chassis.moveToPoint(-0.1,20.1, 4000, {.forwards=true});


    chassis.moveToPose(-16.4, 18.5, 79, 4000, {.forwards=false, .maxSpeed=110});
    pros::delay(2100);
    mogo.set_value(true);
    pros::delay(250);
    intakeStage2.move_voltage(12000);
    pros::delay(500);
    intakeStage2.move_voltage(-12000);


    

    //Ring 1
    chassis.moveToPoint(-18.3,34.4,4000, {.forwards=true, .maxSpeed=80});


    //Ring 2
    chassis.moveToPoint(-40,69,4000, {.forwards=true, .maxSpeed=60});
    chassis.moveToPoint(-51,69,4000, {.forwards=true, .maxSpeed=90});


    //Ring 3
    chassis.moveToPoint(-40,44,4000, {.forwards=true, .maxSpeed=70});

    //Rings 4 and 5
    chassis.moveToPoint(-40,22.7,4000, {.forwards=true, .maxSpeed=80});
    chassis.moveToPoint(-40,9.7,4000, {.forwards=true, .maxSpeed=80});

//Ring 6 
    chassis.moveToPoint(-56,25,2000, {.forwards=true, .maxSpeed=80});

//Corner Mogo
    chassis.moveToPoint(-59,5.2,1000, {.forwards=false, .maxSpeed=80});
    pros::delay(1000);
    mogo.set_value(false);


    chassis.moveToPoint(-51,62.9,4000, {.forwards=true, .maxSpeed=80, .minSpeed=50, .earlyExitRange=20});






//______________________________________________________________________________________

//Wallstake


//Ring 1
chassis.moveToPoint(-15,94,4000, {.forwards=true, .maxSpeed=80});
target = states[1];

//Ring 2
chassis.moveToPoint(-39.6,90,4000, {.forwards=true, .maxSpeed=80});

//Go to Stake
chassis.moveToPoint(-40,65,4000, {.forwards=true, .maxSpeed=80});
chassis.turnToHeading(270,4000);


/*
intake.move_voltage(0);
intakeStage1.move_voltage(-12000);
target = states[2];
intakeStage2.move_voltage(12000);
pros::delay(100);
intakeStage2.move_voltage(0);
chassis.moveToPoint(-54,69,4000, {.forwards=true, .maxSpeed=80});
chassis.moveToPoint(-44.2,69,4000, {.forwards=false, .maxSpeed=80});
pros::delay(1000);
intakeStage2.move_voltage(-12000);
target = states[1];
pros::delay(1000);
intakeStage2.move_voltage(-12000);
intakeStage2.move_voltage(0);
pros::delay(1500);
target = states[2];
intakeStage2.move_voltage(12000);
pros::delay(100);
intakeStage2.move_voltage(0);
chassis.moveToPoint(-54,69,4000, {.forwards=true, .maxSpeed=80});
chassis.moveToPoint(-44.2,69,4000, {.forwards=false, .maxSpeed=80});
target = states[1];


*/











pros::delay(6000);


}