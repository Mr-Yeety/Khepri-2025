// Global Variables
#pragma once
#include "main.h"
#include "lemlib/api.hpp"


//Auton Selector
inline bool driver = true;
inline bool auton = true;
inline bool isRed = true;
inline bool skills = false;



//Auton


//Subsystems
inline pros::Controller master(CONTROLLER_MASTER);

inline pros::MotorGroup leftDrive({1,2,3});
inline pros::MotorGroup rightDrive({4,5,6});

inline pros::Rotation verticalOdomWheel(9);

inline pros::Imu imu1(7);
inline pros::Imu imu2(8);

inline pros::MotorGroup intake({10,11});
inline pros::Motor intakeStage1(10);
inline pros::Motor intakeStage2(11);


//Pneumatics
inline pros::adi::Pneumatics mogo('a',false);

//Lemlib
inline lemlib::Drivetrain drivetrain(&leftDrive,&rightDrive,10,lemlib::Omniwheel::NEW_275, 450,2); 
inline lemlib::TrackingWheel verticalTrackingWheel(&verticalOdomWheel,lemlib::Omniwheel::NEW_275, 4); 

inline lemlib::OdomSensors sensors(&verticalTrackingWheel, nullptr,nullptr,nullptr, &imu1);

// lateral PID controller
inline lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

// angular PID controller
inline lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

inline lemlib::Chassis chassis(drivetrain,lateral_controller,angular_controller,sensors);