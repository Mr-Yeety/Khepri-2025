#include "main.h"

using namespace scarabDrive;



double verticalWheelDiameter = 3.25;
double verticalWheelOffset = 0.44; //Change this


double verticalPos;
double deltaVerticalPos;
double previousVerticalPos = 0;


double heading;
double deltaHeading;
double previousHeading;


double deltaLocalX;
double deltaLocalY;

//unwrapped rotation
double getHeading(){
    double rotation1 = imu1.get_heading();
    //double rotation2 = imu2.get_heading();

    double averageRot = 0;

    //averageRot = ((rotation1 + rotation2)/2); //Learn about gyro effect

    //return averageRot * (M_PI/180.0);
    return rotation1;
}

double getVerticalDistanceTravelled(){
    return ((verticalOdomWheel.get_position()*((M_PI*3.25)/360))); /* #TODO: Change Calculations */
}



void scarabDrive::initializeOdom(){
    verticalOdomWheel.reset();
    imu1.reset();
    imu2.reset();
    pros::delay(3000);
    master.rumble("--");
    printf("Scarab Drive has been Initialized");
    pros::Task odom_task(scarabDrive::getPostion);
}


void scarabDrive::resetOdom(){

    x = 0;
    y= 0;
    theta = 0;

    verticalOdomWheel.reset();

    previousVerticalPos = 0;
    previousHeading = 0;

    imu1.set_heading(0);
    imu2.set_heading(0);
}

void scarabDrive::getPostion(){
    verticalOdomWheel.reset();
    verticalPos = 0;

    while(true){

        verticalPos = getVerticalDistanceTravelled();
        deltaVerticalPos = verticalPos - previousVerticalPos;
        previousVerticalPos = verticalPos;

        //heading = get_heading(); //Change this
        heading = getHeading();
        deltaHeading = heading - previousHeading;
        previousHeading = heading;

        if(deltaHeading == 0){
            deltaLocalX = 0;
            deltaLocalY = deltaVerticalPos;
        }else{
            deltaLocalX = deltaVerticalPos * cos(heading*  (M_PI/180.0) ); //- verticalWheelOffset * sin(deltaHeading);
            deltaLocalY = deltaVerticalPos * sin(heading * (M_PI/180.0)); //+ verticalWheelOffset * (1 - cos(deltaHeading));
        }

        x+= deltaLocalX;
        y += deltaLocalY;

        theta = fmod(getHeading(), 360);

        if (theta < 0) {
       		theta += 360;
		}

        pros::delay(5);
    }
}




