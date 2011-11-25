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

#include "Autonomous.h"

task main(){
	//Code: drive(auto_command,time);
	//replace auto_command and time with values necessary (if you don't replace them, code won't run)
	//auto_command values are: "rpoint", "lpoint", "up", "down", "rswing", "lswing", "rswingback", "lswingback"
	//time values is the time, in milliseconds, you want the robot to be doing the action specified in auto_command

	string program_type="Red";
	int offset_back = 0;
	int offset_right = 0;
	int robot_length = 0; //Make this a constant?

	if (program_type="Red") {
		//1) Measure offset from walls
		//If possible start robot sideways to reduce time it takes to measure
		//Ultrasonic measurer should be placed facing the back with the edge lined up with the robot's back
		//Convert offset distance into milliseconds
		offset_back = -1;
		offset_right = -1;
		
		//2) Move forward ((Four Feet Seven Inches)-offset_back)
		
		//3) Point turn -90 degrees
		
		//4) Move forward ((Four Feet Eight Inches)-(the robot's length)-offset_right)
		
		//5) Point turn -33.7 degrees
		
		//6) Move forward ((Nine Feet Two Inches)-(the robot's length))
		
		//7) Pause 1 second
		
		//8) Move backward (Three Inches)
		
		//9) Point turn 33.7 degrees
		
		//10) Measure offset from RED base wall (should be from 5' - 7')
		offset_right = -1;
		
		//11) Move backward until (offset=(Two Feet Six Inches))
		//OR Move backward (Two Feet Four Inches)
		//Robot will move into RED Low Zone
		
		//12) Point Turn 90 degrees
		
		//13) Measure offset
		offset_back = -1;
		
		//14) Move until (offset=(Ten Feet Six Inches)-(half the robot's length))
		//OR Move forward (Nine Feet Eight Inches)
		
		//15) Point Turn 90 Degrees
		
		//16) Move forward (Five Feet Six Inches)
	}
  
	drive("up", 10000);      //move forward 10000 milliseconds (10sec)
	drive("lpoint", 1000);   //left point turn for 1000 milliseconds (1sec)
	drive("up", 10000);      //move forward again for 10000 milliseconds (10sec)
}
