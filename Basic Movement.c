//DRIVE FUNCTIONS
void manualDrive() {
	motor[rightDrive1] = vexRT[Ch3] - vexRT[Ch1];
	motor[rightDrive2] = vexRT[Ch3] - vexRT[Ch1];
	motor[leftDrive1] = vexRT[Ch3] + vexRT[Ch1];
	motor[leftDrive2] = vexRT[Ch3] + vexRT[Ch1];
}

//LIFT FUNCTIONS
void liftUp(int speed) {
	motor[leftLift] = speed;
	motor[rightLift] = speed;
}

void liftDown(int speed) {
	motor[leftLift] = 0 - speed;
	motor[rightLift] = 0 - speed;
}

void liftStop() {
	motor[leftLift] = 0;
	motor[rightLift] = 0;
}

void manualLift() {
	if (vexRT[Btn6U] == 1) {
		liftUp(100);
	}
	else if (vexRT[Btn6D] == 1) {
		liftDown(100);
	}
	else {
		liftStop();
	}
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
