#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Motor,  motorA,          frontTread,    tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorB,          backTread,     tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     frontLeftWheel, tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     frontRightWheel, tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     backLeftWheel, tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     backRightWheel, tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     leftArm,       tmotorNormal, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     rightArm,      tmotorNormal, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    leftClaw,             tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    rightClaw,            tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

int initialize(int lOpen, int rOpen, int position1, int position2)
{
    motor[frontLeftWheel] = 0;
    motor[frontRightWheel] = 0;
    motor[backLeftWheel] = 0;
    motor[backRightWheel] = 0;
    motor[leftArm] = 0;
    motor[rightArm] = 0;
    nMotorEncoder[leftArm] = 0;
    servo[leftClaw] = lOpen;
    servo[rightClaw] = rOpen;
    position1 = 0;
    position2 = 0;
    return position1;
    return position2;
}

//Function - finds the tangent of the given value; RobotC does not support tan()  :(
float tangentOf(float tanvalue)
{
    float calc_tanvalue;
    calc_tanvalue = sin(tanvalue) / cos(tanvalue);

    return calc_tanvalue;
}


task main()
{

    //-----------Constants------------------
#define WHEELSPEED 75
#define ARMSPEED 20
#define TREADSPEED 20
#define LCLAWOPEN 127
#define LCLAWCLOSE 255
#define RCLAWOPEN 128
#define RCLAWCLOSE 0
    //--------------------------------------
    // when give your motors/servos values, use these constants, not numbers
    // so that if we need to change them, they're easy to access

    int position1, position2;
    initialize(LCLAWOPEN, RCLAWOPEN, position1, position2);

    while (true) {

	getJoystickSettings(joystick);

	//------------Driving-----------------

	//Primary Objective:
	//     - Make robot go forward/backward/point-turn when
	//       the left joystick is pushed up/down/left/right.
	//     - Wheel speeds should be set as WHEELSPEED.
	//     - When nothing is pushed, wheels should stop.
	//     - Make sure to create a 5 unit deadzone around the joystick
	//       (the joystick doesn't always center exactly on 0)
	//     - all wheels should be slaved to the front-left wheel
	//
	//Secondary Objective:
	//     - Make robot swing-turn when left joystick is pushed
	//       diagonally (ie. pushed into a corner)

	int wheels_x1;
	int wheels_y1;
	int left_wheelsPower;
	int right_wheelsPower;

	float angle_leftright;	//Used for calculating size of triangle of motion that will define point turning left/right
	float angle_updown;	//Used for calculating size of triangle of motion that will define moving forward/back

	wheels_x1 = joystick.joy1_x1;	//x-value = left-right joystick movement
	wheels_y1 = joystick.joy1_y1;	//y-value = up-down joystick movmeent

	angle_leftright = PI / 6;	//Graph of y=tan(angle_leftright) used for point turn left/right; MUST BE IN RADIANS
	angle_updown = PI / 3;	//Graph of y=tan(angle_updown) used for forward/back; MUST BE IN RADIANS

	/*RANGES OF MOTION
	   Take grid of joystick x-values and y-values, split into twelve 30 degree triangles
	   Use graphs of y=tan(30)x, y=-tan(30)x, y=tan(60)x, y=-tan(60)x  -
	   To alter sizes of triangles, change the degree (e.g. tan(45))
	   Test to see which triangle values fall in
	   Depending on triangle, move forwards/backwards/point turn/swing turn
	 */

	//!! ROBOTC DOES NOT SUPPORT TAN() FUNCTION - Use user-defined function tangentOf(angle_leftright or angle_updown)

	if (!(wheels_x1 < 10 && wheels_x1 > -10 && wheels_y1 < 10 && wheels_y1 > -10)) {	//If in deadzone, ignore movement - no need to run useless code

	    if ((wheels_y1 <= tangentOf(angle_leftright) * wheels_x1) && (wheels_y1 >= -tangentOf(angle_leftright) * wheels_x1)) {	//Check for right movement
		//Right Point Turn -- Move right tread backwards, left tread forwards
		left_wheelsPower = WHEELSPEED;
		right_wheelsPower = -WHEELSPEED;
	    } else if ((wheels_y1 >= tangentOf(angle_leftright) * wheels_x1) && (wheels_y1 <= -tangentOf(angle_leftright) * wheels_x1)) {	//Check for left movement
		//Left Point Turn -- Move right tread forwards, left tread backwards
		left_wheelsPower = -WHEELSPEED;
		right_wheelsPower = WHEELSPEED;
	    } else if ((wheels_y1 >= tangentOf(angle_updown) * wheels_x1) && (wheels_y1 >= -tangentOf(angle_updown) * wheels_x1)) {	//Check for up movement
		//Forward -- Move both treads forwards
		left_wheelsPower = WHEELSPEED;
		right_wheelsPower = WHEELSPEED;
	    } else if ((wheels_y1 <= tangentOf(angle_updown) * wheels_x1) && (wheels_y1 <= -tangentOf(angle_updown) * wheels_x1)) {	//Check for down movement
		//Backward -- Move both treads backwards
		left_wheelsPower = -WHEELSPEED;
		right_wheelsPower = -WHEELSPEED;
	    } else {		//If NOT forward/backward/point turn, then swing turn
		//CHECK WHICH QUADRANT VALUES ARE IN
		//Swing turn depending on which quadrant values are in
		if (wheels_x1 > 0 && wheels_y1 > 0) {
		    //SWING TURN RIGHT
		    left_wheelsPower = WHEELSPEED;
		    right_wheelsPower = WHEELSPEED / 2;

		} else if (wheels_x1 < 0 && wheels_y1 > 0) {
		    //SWING TURN LEFT
		    left_wheelsPower = WHEELSPEED / 2;
		    right_wheelsPower = WHEELSPEED;

		} else if (wheels_x1 < 0 && wheels_y1 < 0) {
		    //SWING TURN BACKWARDS LEFT
		    left_wheelsPower = -WHEELSPEED / 2;
		    right_wheelsPower = -WHEELSPEED;

		} else {
		    //SWING TURN BACKWARDS RIGHT
		    left_wheelsPower = -WHEELSPEED;
		    right_wheelsPower = -WHEELSPEED / 2;
		}
	    }

	} else {		//Joystick is in dead zone - set powers to zero
	    left_wheelsPower = 0;
	    right_wheelsPower = 0;
	}

	//Drive Code
	motor[frontLeftWheel] = left_wheelsPower;
	motor[backLeftWheel] = left_wheelsPower;
	motor[frontRightWheel] = right_wheelsPower;
	motor[backRightWheel] = right_wheelsPower;

	//------------------------------------


	//------------Arms--------------------

	//Primary Objective:
	//     - raise arm while btn 5 pressed, lower arm while btn 6 pressed
	//     - when neither btn 5 or 6 is pressed, arm should stop
	//     - arm speed should be set as ARMSPEED
	//     - the right arm should be slaved to the left arm
	//
	//Secondary Objective:
	//     - see if you can find a way to get the arms to rotate to a predetermined position and then stop

	if (joy1Btn(5) == 1 || joy1Btn(6) == 1) {
	    if (servo[leftClaw] == LCLAWCLOSE) {
		if (joy1Btn(5) == 1) {
		    motor[leftArm] = -ARMSPEED * 4;
		    motor[rightArm] = -ARMSPEED * 4;
		} else if (joy1Btn(6) == 1) {
		    motor[leftArm] = ARMSPEED;
		    motor[rightArm] = ARMSPEED;
		} else {
		    motor[leftArm] = 0;
		    motor[rightArm] = 0;
		}
	    } else {
		if (joy1Btn(5) == 1) {
		    motor[leftArm] = -ARMSPEED;
		    motor[rightArm] = -ARMSPEED;
		} else if (joy1Btn(6) == 1) {
		    motor[leftArm] = ARMSPEED;
		    motor[rightArm] = ARMSPEED;
		} else {
		    motor[leftArm] = 0;
		    motor[rightArm] = 0;
		}
	    }
	    position1 = nMotorEncoder[leftArm];
	    position2 = position1;
	} else {
	    position2 = position1;
	    position1 = nMotorEncoder[leftArm];
	    if (position1 != position2) {
		motor[leftArm] = -ARMSPEED * 4;
		motor[rightArm] = -ARMSPEED * 4;
	    }
	}

	//------------------------------------


	//-----------Claws--------------------

	//Primary Objective:
	//     - close claws when btn 7 pressed, open claws when btn 8 pressed (claws should start open)
	//     - opening positions for left/right claws are LCLAWOPEN and RCLAWOPEN
	//     - closing positions for left/right claws are LCLAWCLOSE and RCLAWCLOSE

	if (joystick.joy1_Buttons == 7) {
	    //close left claw
	    servo[leftClaw] = LCLAWCLOSE;
	    //close right claw
	    servo[rightClaw] = RCLAWCLOSE;
	}

	if (joystick.joy1_Buttons == 8) {
	    //open left claw
	    servo[leftClaw] = LCLAWOPEN;
	    //open right claw
	    servo[rightClaw] = RCLAWOPEN;
	}
	//------------------------------------


	//-----------Tread--------------------

	//Primary Objective:
	//     - if btn 1 is pressed, have tread move forward until btn 2 is pressed.
	//     - tread should move at speed TREADSPEED

	if (joy1Btn(1) == 1) {
	    motor[frontTread] = TREADSPEED;
	    motor[backTread] = TREADSPEED;
	} else if (joy1Btn(2) == 1) {
	    motor[frontTread] = 0;
	    motor[backTread] = 0;
	}
	//------------------------------------
    }
}
