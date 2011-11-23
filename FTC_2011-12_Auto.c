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

  //example of a autonomous program (runs):
  drive("up", 10000);      //move forward 10000 milliseconds (10sec)
  drive("lpoint", 1000);   //left point turn for 1000 milliseconds (1sec)
  drive("up", 10000);      //move forward again for 10000 milliseconds (10sec)
}
