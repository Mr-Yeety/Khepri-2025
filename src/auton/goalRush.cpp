#include "main.h"


void goalRush(){
    pros::Task mogoTask([] {
        while (true)
        {
            if (mogoDistance.get_distance() <70)
            {
                mogo.set_value(true);
            }
            
        }
        
    });

    pros::Task intakeLockTask([] {
        while (true)
        {
    if (intakeLock == true)
            {
            if(isRed && (colorSensor.get_hue()>0 && colorSensor.get_hue()<15)){ //Red
                master.rumble("..");
                    pros::delay(100);
                    intakeStage1.move_voltage(0);
                    intakeStage2.move_voltage(0);
        }
        if(!isRed && (colorSensor.get_hue()>200 && colorSensor.get_hue()<230)){ //Blue
                    master.rumble("..");
                    pros::delay(100);
                    intakeStage1.move_voltage(0);
                    intakeStage2.move_voltage(0);
            }
            }
            
        }
        
    });

    if(isRed){
        intakeLock = true;
        intakeStage1.move_voltage(-12000);
        intakeStage2.move_voltage(-12000);
        chassis.moveToPoint(0,47.5, 2000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); //Mogo 1
        while(chassis.isInMotion()){pros::delay(10);}
        doinker.set_value(true);
        pros::delay(500);
        chassis.moveToPoint(9.0,22, 4000, {.forwards = false, .maxSpeed = 127, .minSpeed = 0}); //Mogo 1 -Drop
        while(chassis.isInMotion()){pros::delay(10);}
        doinker.set_value(false);
    

    
        chassis.moveToPoint(-19.3,37.8, 3000, {.forwards = false, .maxSpeed = 80, .minSpeed = 0}); //Mogo 2
        while(chassis.isInMotion()){pros::delay(10);}
        intakeLock = false;
        intakeStage2.move_voltage(12000);
        pros::delay(100);
        intakeStage1.move_voltage(-12000);
        intakeStage2.move_voltage(-12000);
        pros::delay(800);
        mogoTask.suspend();
        mogo.set_value(false);

        chassis.moveToPoint(2.6,15.2, 3000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); //Mogo 1 - Grab
        chassis.moveToPoint(7,40, 3000, {.forwards = false, .maxSpeed = 100, .minSpeed = 0}); //Mogo 1 - Grab
        while(chassis.isInMotion()){pros::delay(10);}
        mogoTask.resume();

        chassis.moveToPose(-13,10,270, 3000, {.forwards = true, .maxSpeed = 127, .minSpeed = 0}); //Mogo 1 - Grab

        chassis.moveToPoint(-45.5,19.5,3000, {.forwards = true, .maxSpeed = 127, .minSpeed =0}); //Intake Lift





        pros::delay(6000);
        mogoTask.suspend();
        












    }else if(!isRed){
        std::cout << "Blue Goal Rush";
    }
}