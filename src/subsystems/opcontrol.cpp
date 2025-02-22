#include "main.h"





void controlDrivetrain(){
    chassis.arcade(master.get_analog(ANALOG_LEFT_Y),master.get_analog(ANALOG_RIGHT_X));

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
        intakeStage1.move_voltage(12000); 
        intakeStage2.move_voltage(12000); 
    }else if(master.get_digital(driver.INTAKE_REV)){
        if(currState == 1){
            intakeStage1.move_voltage(-12000);
            intakeStage2.move_voltage(-10000);
        }else{
            intakeStage1.move_voltage(-12000); 
            intakeStage2.move_voltage(-12000);         }
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
    target = states[currState];

}

void updateWallStakes(){
    double kp = 0.033;
    double error = target - ladyBrownSensor.get_position();
    double velocity = kp * error;
    ladyBrown.move(velocity);
}

void controlWallStakes(){
    if(master.get_digital_new_press(driver.LADYBROWN)){
        nextState();
    }
    else if(master.get_digital_new_press(DIGITAL_DOWN)){
        if(target == states[3]){
            target = states[0];
        }else{
        target = states[3];
        }
    }
    else if(master.get_digital_new_press(DIGITAL_RIGHT)){
        if(target == states[4]){
            target = states[0];
        }else{
 
        target = states[4];
        }
    }
    else if(master.get_digital_new_press(DIGITAL_UP)){
        if(target == states[5]){
            target = states[0];
        }else{
 
        target = states[5];
        }
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

void resetLB(){
    liftControlTask.suspend();
    ladyBrown.set_brake_mode(MOTOR_BRAKE_COAST);
    ladyBrown.move(-127);
    pros::delay(900);
    ladyBrown.move(0);
    pros::delay(400);
    ladyBrown.set_brake_mode(MOTOR_BRAKE_HOLD);
    pros::delay(100);
    ladyBrownSensor.reset_position();
    liftControlTask.resume();
}