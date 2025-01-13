#include "main.h"

void controlClamp(){
    if(master.get_digital_new_press(DIGITAL_L1)){
        mogo.toggle();
    }
}


void controlIntake(){
    if(master.get_digital_new_press(DIGITAL_R1)){
        intake.move_voltage(12000); 
    }else if(master.get_digital_new_press(DIGITAL_R2)){
        intake.move_voltage(-12000);
    }
}