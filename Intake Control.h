int intakeTarget;

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

void rollerIn(int speed) {
	motor[roller] = speed;
}

void rollerOut (int speed) {
	motor[roller] = -speed;
}

void rollerStop() {
	motor[roller] = 0;
}


void manualIntake() {
	if (vexRT[Btn5U] == 1) {
		intakeUp(100);
	}
	else if (vexRT[Btn5D] == 1) {
		intakeDown(100);
	} else {
		intakeStop();
	}

	if (vexRT[Btn8R]) {
		rollerOut(120);
	} else {
		rollerIn(30);
	}
}

void setIntake(int target) {
	intakeTarget = target;
}

task intakeControl(){
	while(true) {
		if (!isAuton) {
			manualIntake();
		}
		wait1Msec(20);
	}
}//end task
