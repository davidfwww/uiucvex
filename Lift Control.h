//#include "Utility Functions.h"

int liftTarget;
bool newLiftTarget = true;

void liftUp(int speed) {
	motor[lift12] = speed;
	motor[lift3] = speed;
}

void liftStop() {
	liftUp(0);
}

void manualLift() {
	if (vexRT[Btn6U] == 1) {
		liftUp(100);
	}
	else if (vexRT[Btn6D] == 1) {
		liftUp(-100);
	}
	else {
		liftStop();
	}
}

void setLift(int target) {
	liftTarget = target;
	newLiftTarget = true;
}

task liftControl(){
	int liftState = 1;

	const float Kp = 1.0;
	const float Kd = 0.6;

	int proportion;
	int derivative;
	int error;
	int prevError;
	int raw;

	while(true) {
		if (liftReset1 == 1 || liftReset2 == 1) liftPos = 0;

		if (vexRT[Btn6U] == 1 || vexRT[Btn6D] == 1) liftState = 0;
		else if ((isAuton && liftTarget == -999) || autoStack) liftState = 1;
		else if (isAuton) liftState = 2;
		else if (vexRT[Btn8D] == 1) {
			liftState = 2;
			setLift(300);
		}

		switch(liftState) {
			//manual drive case
			case 0:
				manualLift();
				break;
			//auton no pid case
			case 1:
				break;
			//auton pid case
			case 2:
				error = calcError(liftTarget, liftPos);

				proportion = calcP(Kp, error);

				derivative = calcD(Kd, error, prevError);
				prevError = error;
				if (newLiftTarget) derivative = 0;

				raw = proportion + derivative;

				liftUp(raw);

				newLiftTarget = false;
				break;
			default:
				manualLift();
				break;
		}
	}
}
