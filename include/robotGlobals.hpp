// Global Variables
#pragma once
#include "main.h"
#include "Driver.hpp"
#include "lemlib/api.hpp"


//Auton Selector
inline int auton = 0;
inline bool isRed = true;


inline bool intakeLock = false;

inline const int numStates = 5;
inline int states[numStates] = {0,3000,13500,25000,22350};
inline int currState = 0;
inline int target = 0;


    


inline Driver driver;
inline bool ringIntaked = false;

//Subsystems
inline pros::Controller master(CONTROLLER_MASTER);

inline pros::MotorGroup leftDrive({-18,19,-20});
inline pros::MotorGroup rightDrive({11,12,-13});

inline pros::Rotation verticalOdomWheel(17);
inline pros::Rotation horizontalOdomWheel(-14);
inline pros::Rotation ladyBrownSensor(6);
inline pros::Distance mogoDistance(16);

inline pros::Imu imu1(15);

inline pros::MotorGroup intake({21,2});
inline pros::Motor intakeStage1(21);
inline pros::Motor intakeStage2(2);
inline pros::Motor ladyBrown(3);


inline pros::Optical colorSensor(5);


//Pneumatics
inline pros::adi::Pneumatics mogo('a',false);
inline pros::adi::Pneumatics intakeLift('b',false);
inline pros::adi::Pneumatics doinker('c',false);


//Lemlib
inline lemlib::Drivetrain drivetrain(&leftDrive,&rightDrive,12,lemlib::Omniwheel::NEW_325, 450,2); 
inline lemlib::TrackingWheel verticalTrackingWheel(&verticalOdomWheel,lemlib::Omniwheel::NEW_275,-1); //CHANGE OFFSET
inline lemlib::TrackingWheel horizontalTrackingWheel(&horizontalOdomWheel, lemlib::Omniwheel::NEW_275, 1); //CHANGE OFFSET

inline lemlib::OdomSensors sensors(&verticalTrackingWheel, nullptr,&horizontalTrackingWheel,nullptr, &imu1);

// lateral PID controller
inline lemlib::ControllerSettings lateral_controller(6.8, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              30, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                            20 // maximum acceleration (slew)
);

// angular PID controller
inline lemlib::ControllerSettings angular_controller(6.9, // proportional gain (kP)
                                              0.025, // integral gain (kI)
                                              70, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

inline lemlib::Chassis chassis(drivetrain,lateral_controller,angular_controller,sensors);


inline pros::Task liftControlTask([] {
  while(true) {
      updateWallStakes();
      pros::delay(10);
  }
});

inline pros::Task mogoTask([] {
  while (true)
  {
      if (mogoDistance.get_distance() <70)
      {
          mogo.set_value(true);
      }
      
  }
  
});

inline pros::Task intakeLockTask([] {
  while (true)
  {
  if(isRed && (colorSensor.get_hue()>0 && colorSensor.get_hue()<15)){ //Red
              master.rumble("..");
              //pros::delay(300);
              intakeStage2.move_voltage(0);
              intakeStage1.move_voltage(12000);
  }
  if(!isRed && (colorSensor.get_hue()>200 && colorSensor.get_hue()<230)){ //Blue
              master.rumble("..");
              //pros::delay(300);
              intakeStage2.move_voltage(0);
              intakeStage1.move_voltage(12000);
      }
      
      
  }
  
});


inline pros::Task telemetryShowTask([] {
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