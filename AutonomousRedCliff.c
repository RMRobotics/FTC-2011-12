#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S4,     sonarSensor,         sensorSONAR)
#pragma config(Motor,  motorA,          frontTread,    tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorB,          backTread,     tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     frontLeftWheel, tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     frontRightWheel, tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     backRightWheel, tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     backLeftWheel, tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     leftArm,       tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     rightArm,      tmotorNormal, PIDControl, encoder)
#pragma config(Servo,  srvo_S1_C4_1,    leftClaw,             tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    rightClaw,            tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//#include "Autonomous.h"
#include "JoystickDriver.c"


void drive (string auto_command, long time) {
  int left_wheelsPower;
  int right_wheelsPower;
  int WHEELSPEED = 75;

  if(auto_command=="rpoint") {
    //Check for right movement
    //Right Point Turn -- Move right tread backwards, left tread forwards
    left_wheelsPower=WHEELSPEED;
    right_wheelsPower=-WHEELSPEED;
    }else if(auto_command=="lpoint") {
    //Check for left movement
    //Left Point Turn -- Move right tread forwards, left tread backwards
    left_wheelsPower=-WHEELSPEED;
    right_wheelsPower=WHEELSPEED;
    }else if(auto_command=="up") {
    //Check for up movement
    //Forward -- Move both treads forwards
    left_wheelsPower=WHEELSPEED;
    right_wheelsPower=WHEELSPEED;
    }else if(auto_command=="down") {
    //Check for down movement
    //Backward -- Move both treads backwards
    left_wheelsPower=-WHEELSPEED;
    right_wheelsPower=-WHEELSPEED;
    }else if(auto_command=="rswing") {	//SWING TURN RIGHT
    left_wheelsPower=WHEELSPEED;
    right_wheelsPower=0;
    }else if(auto_command=="lswing") {	//SWING TURN LEFT
    left_wheelsPower=0;
    right_wheelsPower=WHEELSPEED;
    }else if(auto_command=="lswingback") {	//SWING TURN BACKWARDS LEFT
    left_wheelsPower=0;
    right_wheelsPower=-WHEELSPEED;
    }else if(auto_command=="rswingback") {	//SWING TURN BACKWARDS RIGHT
    left_wheelsPower=-WHEELSPEED;
    right_wheelsPower=0;
    }else {
    //Do not move
    left_wheelsPower=0;
    right_wheelsPower=0;
  }

  //Drive Code
  motor[frontLeftWheel] = left_wheelsPower;
  motor[backLeftWheel] = left_wheelsPower;
  motor[frontRightWheel] = right_wheelsPower;
  motor[backRightWheel] = right_wheelsPower;
  wait1Msec(time);
  motor[frontLeftWheel] = 0;
  motor[backLeftWheel] = 0;
  motor[frontRightWheel] = 0;
  motor[backRightWheel] = 0;
  return;
}

task main(){
  //Code: drive(auto_command,time);
  //replace auto_command and time with values necessary (if you don't replace them, code won't run)
  //auto_command values are: "rpoint", "lpoint", "up", "down", "rswing", "lswing", "rswingback", "lswingback"
  //time values is the time, in milliseconds, you want the robot to be doing the action specified in auto_command

  //Info:
  //Motor at 75% power travels at 2 feet per second = 60.96 cm
  //Lpoint turn takes 750 ms to turn 90 degrees

  //Use the sonar sensor by: SensorValue[sonarSensor].  It can get a distance from 0cm to 80cm
  //drive("up", 10000);      move forward 10000 milliseconds (10sec)
  //drive("lpoint", 1000);   left point turn for 1000 milliseconds (1sec)
  //drive("up", 10000);      move forward again for 10000 milliseconds (10sec)

  waitForStart();

  long offset_back = 0;
  long offset_right = 0;
  long offset_left = 0;
  long robot_length = 667; //In milliseconds
  long distance = 0;

  /*
  int count = 0;

  string BatteryLevel = externalBatteryAvg;
  string selection = "";


  nxtDisplayCenteredBigTextLine (3, BatteryLevel);
  wait1Msec(3000);
  */

  //1) Drive off home zone
  distance = 1650;
  drive("up", distance);

  //2) Turn left 90 degrees
  distance = 870;
  drive("lpoint", distance);

  //3) Hit bowling ball into back lot
  distance = 2000;
  drive("up", distance);

  //4) Turn left 45 degrees
  distance = 420;
  drive("lpoint", distance);

  //5) Drive into back lot
  distance = 2000;
  drive("up", distance);
}
