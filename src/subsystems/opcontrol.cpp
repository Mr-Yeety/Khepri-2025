#include "main.h"





void controlDrivetrain(){
    scarabDrive::joyDrive(driver.LINEAR_CURVE, driver.ANGLE_CURVE);
}

void controlClamp(){
    if(master.get_digital(driver.MOGO)){
        mogo.set_value(true);
    }else if(!master.get_digital(driver.MOGO)){
        mogo.set_value(false);
    }
}

void controlIntake(){
    if(master.get_digital(driver.INTAKE)){
        intake.move_voltage(12000); 
    }else if(master.get_digital(driver.INTAKE_REV)){
        intake.move_voltage(-12000);
    }else{
        intake.move_voltage(0);
    }
}

void colorSort(){
    if(!isRed && (colorSensor.get_hue()>0 && colorSensor.get_hue()<15)){ //Red
                pros::delay(220);
				intake.brake();
				pros::delay(190);
				intake.move_voltage(-12000);
    }
    if(isRed && (colorSensor.get_hue()>200 && colorSensor.get_hue()<230)){ //Blue
                master.rumble("..");
                pros::delay(25);
				intake.brake();
        }
}



//Wall Stakes
void nextState(){
    currState += 1;
    if(currState ==3){
        currState = 0;
    }
    if(currState ==2){
        intakeStage2.move_voltage(12000);
        pros::delay(10);
        intakeStage2.move_voltage(0);

    }
    target = states[currState];

}

void updateWallStakes(){
    double kp = 0.03;
    double error = target - ladyBrownSensor.get_position();
    double velocity = kp * error;
    ladyBrown.move(velocity);
}

void controlWallStakes(){
    if(master.get_digital_new_press(driver.LADYBROWN)){
        nextState();
    }

}

void controlDoinker(){
    if(master.get_digital_new_press(driver.DOINKER)){
        doinker.toggle();
    }
}

void controlIntakeLift(){
    if(master.get_digital_new_press(driver.INTAKE_LIFT)){
        intakeLift.toggle();
    }
}