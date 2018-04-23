void intakeUp(int speed) {
	motor[cone] = speed;
}

void intakeDown(int speed) {
	motor[cone] = 0 - speed;
}

void intakeStop() {
	motor[cone] = 0;
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
		wait1Msec(250);
	}
}

task intakeControl(){
	while(true) {
		if (!isAuton && !autoStack) {
			manualIntake();
		}
		wait1Msec(20);
	}
}//end task

task rollerControl() {
	int lastPos;
	int difference;
	while(true) {
		if (autoStack) {
			continue;
		}
		difference = abs(lastPos - intakePos);
		if (vexRT[Btn8R] && difference < 10) {
			rollerOut(120);
			wait1Msec(500);
		} else {
			rollerIn(30);
		}
		lastPos = intakePos;
		wait1Msec(20);
	}
}//end task
