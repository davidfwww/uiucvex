//DRIVE CONTROL FUNCTIONS
void manualDrive() {
	motor[rightDrive1] = -vexRT[Ch3] - vexRT[Ch1];
	motor[rightDrive2] = -vexRT[Ch3] - vexRT[Ch1];
	motor[leftDrive1] = -vexRT[Ch3] + vexRT[Ch1];
	motor[leftDrive2] = -vexRT[Ch3] + vexRT[Ch1];
}

//task driveControl() {
