#include "main.h"
#include "Driver.hpp"





void initialize() {
    master.clear();
    pros::delay(50);
    colorSensor.set_led_pwm(100);

    /*
    init();
    while(ready == false) {
        printf(" ");
    }
    */
    
    
    driver.init(auton);
    chassis.calibrate();
    leftDrive.set_brake_mode(MOTOR_BRAKE_COAST);
    rightDrive.set_brake_mode(MOTOR_BRAKE_COAST);
    chassis.setBrakeMode(MOTOR_BRAKE_COAST);
    ladyBrownSensor.set_data_rate(5);
    ladyBrownSensor.reset_position();
    master.clear();
    pros::delay(50);
    
    
    pros::Task liftControlTask([] {
        while(true) {
            updateWallStakes();
            pros::delay(10);
        }
    });
    
    
    pros::Task telemetryShowTask([] {
        while(true) {
            //pros::delay(10);
            
            double averageLeftTemp = (leftDrive.get_temperature(0) + leftDrive.get_temperature(1) + leftDrive.get_temperature(2)) / 3;
            double averageRightTemp = (rightDrive.get_temperature(0) + rightDrive.get_temperature(1) + rightDrive.get_temperature(2)) / 3;
            double averageDriveTemp = (averageRightTemp + averageRightTemp) / 2;
            double firstIntakeTemp = intake.get_temperature(0);
            double secondIntakeTemp = intake.get_temperature(1);

            master.print(0, 0, "%.1lf|%.1lf|%.1lf", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
            master.print(1, 0, "DT:%.0lf|LBT:%.0lf", averageDriveTemp, ladyBrown.get_temperature(0));
            master.print(2, 0, "FST:%.0lf|SST:%.0lf", firstIntakeTemp, secondIntakeTemp);
        }
    });  
}


void disabled() {}


void competition_initialize() {}


void autonomous() {
    chassis.setBrakeMode(MOTOR_BRAKE_HOLD);
    if(pros::competition::is_connected()) {
        if(auton == 0) {
            winpoint(); // Solo AWP
        } else if(auton == 1) {
            goalRush(); // Goal Rush
        } else if(auton == 2) {
            // 5 Ring
        } else if(auton == 3) {
            sixRing(); // 6 Ring
        } else if(auton == 4) {
            driveForwards(); // Go Forwards 5 inches
        } else if(auton == 5) {
            skillsAuton(); // Skills
        }
    } else {
        goalRush(); // Change with test auton
    }
}


void opcontrol() {
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
                auton = 5;
                driver.init(auton);
            }
        }

        pros::delay(50);
    }
}
