#include "main.h"
#include "Driver.hpp"





void initialize() {
    liftControlTask.suspend();
    master.clear();
    pros::delay(50);

    /*
    init();
    while(ready == false) {
        printf(" ");
    }
    */
    
   
    driver.init(auton);
    colorSensor.set_led_pwm(100);
    chassis.calibrate();
    leftDrive.set_brake_mode(MOTOR_BRAKE_COAST);
    rightDrive.set_brake_mode(MOTOR_BRAKE_COAST);
    chassis.setBrakeMode(MOTOR_BRAKE_COAST);
    ladyBrownSensor.set_data_rate(5);
    //ladyBrownSensor.reset_position();
    master.clear();
    pros::delay(50);
}


void disabled() {}


void competition_initialize() {}


void autonomous() {
    if(pros::competition::is_connected()) {
        if(auton == 0) {
            fiveRing(); // Solo AWP
        } else if(auton == 1) {
            goalRush(); // Goal Rush
        } else if(auton == 2) {
            // 5 Ring
        } else if(auton == 3) {
             // 5 Ring Qual
        } else if(auton == 4) {
            sixRing(); // 6 Ring
        } else if(auton == 5) {
            // 6 Ring - Qual
        } else if(auton == 6) {
            driveForwards(); //5 inches forward
        } else if(auton == 7) {
            skillsAuton(); //Skills
        }
    } else {
        goalRush(); // Change with test auton
    }
}


void opcontrol() {
    liftControlTask.resume();
    telemetryShowTask.resume();
    intakeLockTask.suspend();
    mogoTask.suspend();
    chassis.setBrakeMode(MOTOR_BRAKE_COAST);
    target = states[0];


    while(true) {
        controlDrivetrain();
        controlClamp();
        controlIntake();
        controlWallStakes();
        controlDoinker();
        controlIntakeLift();
   
        if(!pros::competition::is_connected()) {
            if(master.get_digital_new_press(DIGITAL_B)) {
                autonomous();
            }

            if(master.get_digital_new_press(DIGITAL_X)) {
                auton = 7;
                driver.init(auton);
            }
        }

        pros::delay(50);
    }
}
