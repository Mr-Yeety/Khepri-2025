#include "main.h"

void sixRing(){

    pros::Task mogoTask([] {
        while (true)
        {
            if (mogoDistance.get_distance() <70)
            {
                mogo.set_value(true);
            }
            
        }
        
    });


        //_________________________________RED__________________________________________________

    if(isRed){

// Mogo 1
chassis.moveToPoint(16.43, 0.00, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Intermediate
chassis.moveToPoint(26.77, 2.82, 2000, {.forwards = false, .maxSpeed = 127, .minSpeed = 0}); //  Mogo, backwards approach, Ring 1



// 2 Rings on the white lines
chassis.moveToPoint(48.83, 17.84, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Ring 2
chassis.moveToPoint(50.71, 30.05, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Ring 3

// Ring Stack - We want bottom one
chassis.moveToPoint(37.10, 30.05, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Ring 4

// Corner Ring - We want bottom one
chassis.moveToPoint(8.45, 35.69, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Intermediate
chassis.moveToPoint(1.88, 41.79, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Ring 5

// Ring Stack - We want top one
chassis.moveToPoint(15.03, 24.42, 2000, {.forwards = false, .maxSpeed = 127, .minSpeed = 0}); // Intermediate
// Intake Lift up
chassis.moveToPoint(14.56, -7.51, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); // Ring 6
//Intake Lift down
chassis.moveToPoint(14.56, -7.51, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0});




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