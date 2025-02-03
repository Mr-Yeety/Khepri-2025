 #pragma once

#include "api.h"
 
 
 
 class Driver{

	public:

	pros::controller_digital_e_t MOGO;
	pros::controller_digital_e_t FLEX;
	pros::controller_digital_e_t INTAKE;
	pros::controller_digital_e_t INTAKE_REV;
	pros::controller_digital_e_t LADYBROWN;
	pros::controller_digital_e_t DOINKER;
	pros::controller_digital_e_t LB_JERK;
	pros::controller_digital_e_t INTAKE_LIFT;


	int LINEAR_CURVE;
	int ANGLE_CURVE;

    void init(int selector);

};