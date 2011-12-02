//some constants for you to use in your autnomous programs (same as the constants in teleop)

#define WHEELSPEED 75
#define ARMSPEED 20
#define TREADSPEED 50
#define LCLAWOPEN 127
#define LCLAWCLOSE 255
#define RCLAWOPEN 128
#define RCLAWCLOSE 0

void drive (string auto_command, int time) {
  int left_wheelsPower;
  int right_wheelsPower;

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
}
