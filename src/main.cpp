#include "main.h"

void initialize() {
    init();
    while(ready==false){
        printf(" ");
    }

    chassis.calibrate();
    


}


void disabled() {}


void competition_initialize() {}


void autonomous() {


}


void opcontrol() {

    

    while(true){

        scarabDrive::joyDrive(0,0);

        controlClamp();
        controlDoinker();
        controlHang();
        controlIntake();
        controlIntakeLift();
        controlWallStakes();

        std::cout<<"X: "<< chassis.getPose().x<<" " << "Y: " << chassis.getPose().y << " Theta: " << chassis.getPose().theta << "\n";



    

    }
    


}
