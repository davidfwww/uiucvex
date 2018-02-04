//DRIVE CONTROL FUNCTIONS
/*void manualDrive() {
	motor[rightDrive1] = -vexRT[Ch3] - vexRT[Ch1];
	motor[rightDrive2] = -vexRT[Ch3] - vexRT[Ch1];
	motor[leftDrive1] = -vexRT[Ch3] + vexRT[Ch1];
	motor[leftDrive2] = -vexRT[Ch3] + vexRT[Ch1];
}*/
const int JOYSTICK_THRESHOLD = 15;
const int MAX_ACCEL = 10;

//sets right joystick threshold
int rightJoyAdjusted() {
	if(abs(rightJoyRaw) > JOYSTICK_THRESHOLD) return rightJoyRaw; //set right joystick threshold
	else return 0;
}

//sets left joystick threshold
int leftJoyAdjusted() {
	if(abs(leftJoyRaw) > JOYSTICK_THRESHOLD) return leftJoyRaw; //set right joystick threshold
	else return 0;
}

//slew function that sets max acceleration
int slew(int targetSpeed, int currentSpeed) {
	int accel;

	accel = targetSpeed - currentSpeed;

	if(accel > MAX_ACCEL) accel = MAX_ACCEL;
	else if (accel < 0 - MAX_ACCEL) accel = 0 - MAX_ACCEL;

	return currentSpeed + accel;
}

void manualDrive() {
	//set joystick thresholds
	int rightJoy = rightJoyAdjusted();
	int leftJoy = leftJoyAdjusted();

	//calculate target speed
	int rightDriveSpeed = -leftJoy - rightJoy;
	int leftDriveSpeed = -leftJoy + rightJoy;

	//apply slew
	rightDriveSpeed = slew(rightDriveSpeed, motor[rightDrive1]);
	leftDriveSpeed = slew(leftDriveSpeed, motor[leftDrive1]);

	motor[rightDrive1] = rightDriveSpeed;
	motor[rightDrive2] = rightDriveSpeed;
	motor[leftDrive1] = leftDriveSpeed;
	motor[leftDrive2] = leftDriveSpeed;

}

task driveControl(){
	while(true) {
		manualDrive();

		wait1Msec(20);
	}
}
