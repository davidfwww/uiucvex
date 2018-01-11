//DRIVE FUNCTIONS
void manualDrive() {
	motor[rightDrive1] = vexRT[Ch3] - vexRT[Ch1];
	motor[rightDrive2] = vexRT[Ch3] - vexRT[Ch1];
	motor[leftDrive1] = vexRT[Ch3] + vexRT[Ch1];
	motor[leftDrive2] = vexRT[Ch3] + vexRT[Ch1];
}

//INTAKE FUNCTIONS
void intakeUp(int speed) {
	motor[coneRight] = speed;
	motor[coneLeft] = speed;
}

void intakeDown(int speed) {
	motor[coneRight] = 0 - speed;
	motor[coneLeft] = 0 - speed;
}

void intakeStop() {
	motor[coneRight] = 0;
	motor[coneLeft] = 0;
}

void manualIntake() {
	if (vexRT[Btn5U] == 1) {
		intakeUp(100);
	}
	else if (vexRT[Btn5D] == 1) {
		intakeDown(100);
	}
	else {
		intakeStop();
	}
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
