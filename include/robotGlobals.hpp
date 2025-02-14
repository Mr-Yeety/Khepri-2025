// Global Variables
#pragma once
#include "main.h"
#include "Driver.hpp"
#include "lemlib/api.hpp"


//Auton Selector
inline int auton = 0;
inline bool isRed = true;


inline bool intakeLock = false;

inline const int numStates = 4;
inline int states[numStates] = {0,2200,13500};
inline int currState = 0;
inline int target = 0;

inline Driver driver;
inline bool ringIntaked = false;

//Subsystems
inline pros::Controller master(CONTROLLER_MASTER);

inline pros::MotorGroup leftDrive({-17,18,-19});
inline pros::MotorGroup rightDrive({11,-12,13});

inline pros::Rotation verticalOdomWheel(16);
inline pros::Rotation horizontalOdomWheel(-15);
inline pros::Rotation ladyBrownSensor(6);
inline pros::Distance mogoDistance(20);

inline pros::Imu imu1(8);

inline pros::MotorGroup intake({14,21});
inline pros::Motor intakeStage1(14);
inline pros::Motor intakeStage2(21);
inline pros::Motor ladyBrown(3);


inline pros::Optical colorSensor(2);


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