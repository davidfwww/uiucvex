//DRIVE FUNCTIONS
void manualDrive() {
	motor[rightDrive1] = vexRT[Ch3] - vexRT[Ch1];
	motor[rightDrive2] = vexRT[Ch3] - vexRT[Ch1];
	motor[leftDrive1] = vexRT[Ch3] + vexRT[Ch1];
	motor[leftDrive2] = vexRT[Ch3] + vexRT[Ch1];
}

//MOBILE GOAL INTAKE FUNCTIONS
void mobileOut(int speed) {
	motor[mobileRight] = speed;
	motor[mobileLeft] = speed;
}

void mobileIn(int speed) {
	motor[mobileRight] = 0 - speed;
	motor[mobileLeft] = 0 - speed;
}

void mobileStop() {
	motor[mobileRight] = 0;
	motor[mobileLeft] = 0;
}

void manualMobile() {
	if (vexRT[Btn7U] == 1) {
		mobileOut(100);
	}
	else if (vexRT[Btn7D] == 1) {
		mobileIn(100);
	}
	else {
		mobileStop();
	}
}
