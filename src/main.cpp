#include "main.h"
#include "Driver.hpp"







void initialize() {
    master.clear();
    pros::delay(50);

if(pros::competition::is_connected()){
    inital();
    while(ready==false){
        printf(" ");
    }
    
}

    driver.init(auton);
    chassis.calibrate();
    leftDrive.set_brake_mode(MOTOR_BRAKE_HOLD);
    rightDrive.set_brake_mode(MOTOR_BRAKE_HOLD);
    chassis.setBrakeMode(MOTOR_BRAKE_HOLD);
    ladyBrownSensor.set_data_rate(5);
    ladyBrownSensor.reset_position();
    colorSensor.set_led_pwm(100);
    colorSensor.set_integration_time(10);
    master.clear();
    pros::delay(50);

    
    pros::Task liftControlTask([] {
        while(true){
            updateWallStakes();
            pros::delay(10);
        }
    });


    pros::Task telemetryShowTask([] {
        while(true){

            
            double averageLeftTemp = (leftDrive.get_temperature(0) + leftDrive.get_temperature(1) + leftDrive.get_temperature(2))/3;
            double averageRightTemp = (rightDrive.get_temperature(0) + rightDrive.get_temperature(1) + rightDrive.get_temperature(2))/3;
            double averageDriveTemp = (averageRightTemp+ averageRightTemp)/2;
            double averageIntakeTemp = (intake.get_temperature(0) + intake.get_temperature(1))/2;

            master.print(0,0,"%.1lf|%.1lf|%.1lf", chassis.getPose().x,chassis.getPose().y, chassis.getPose().theta);
            master.print(1,0,"DT:%.0lf|LBT:%.0lf", averageDriveTemp,ladyBrown.get_temperature(0));
            master.print(2,0,"IT:%.0lf", averageIntakeTemp);
        }
    });    
    


}


void disabled() {}


void competition_initialize() {}


void autonomous() {
    if(pros::competition::is_connected()){
        if(auton==0){
            winpoint();
        }else if(auton ==1){
            sixRing();
        }else if(auton == 2){
            goalRush();
        }else if(auton == 3){
            skillsAuton();
        }
    }else{
        testLinearPID(); //Chnage with test auton
    }
}


void opcontrol() {

    while(true){


        controlDrivetrain();
        controlClamp();
        controlIntake();
        controlWallStakes();
        controlDoinker();
        controlIntakeLift();
   

        if(!pros::competition::is_connected()){
            if(master.get_digital_new_press(DIGITAL_LEFT)){
                autonomous();
            }


        }


        pros::delay(50);
}}