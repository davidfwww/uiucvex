int liftTarget;

void liftUp(int speed) {
	motor[lift] = speed;
}

void liftStop() {
	motor[lift] = 0;
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
}

task liftControl(){
	bool pidRunning = false; //boolean to activate/deactivate PID
	int liftState = 1;

	//PID Variables
	int encoderVal;
	int error;
	int lastError;
	int proportion;
	float integral;
	int derivative;
	int liftRaw;

	//PID Constants
	const float Kp = 1.8;
	const float Ki = 0.0;
	const float Kd = 5.0;
	const int integralLimit = 50;
	const int maxPower = 80;
	const int minPower = -127;

	while(true) {
		if(SensorValue[liftBump] != 0) liftPos = 0; //recalibrate lift encoder @ down position

		if(bIfiAutonomousMode == true) liftState = 3;//allow values to be sent from elsewhere in program
		else if (vexRT[Btn6U] || vexRT[Btn6D]) liftState = 1; //manual controls
		else if (vexRT[Btn5U] == 1) liftState  = 2; //automated stack

		switch(liftState) {
		case 1: //manual controls
			pidRunning = false;
			manualLift();
			break;
		case 2: //automated stack
			pidRunning = true;
			setLift(0); //replace w height
			break;
		case 3: //auton
			pidRunning = true;
			break;
		default: //default manual
			pidRunning = false;
			manualLift();
			break;
		}
		if(pidRunning == true){
			encoderVal = liftPos;
			encoderVal *= 1; //correct encoder count direction if necessary
			error = liftTarget - encoderVal; //E = target - encoder

			if(Ki != 0.0){//calculate integral
				if(abs(error) < integralLimit) integral += error;
				else if(error > integralLimit) integral = integralLimit;
				else if(error < 0 - integralLimit) integral = 0 - integralLimit;
				else integral = 0;
			}//end if(Ki!=0) statement
			else integral = 0;

			proportion = Kp*error; //calculate proportion
			derivative = Kd*(error-lastError); //calculate derivative
			integral += Ki*error;//calculate integral
			lastError = error; //set "previous error"

			liftRaw = proportion+derivative+integral; //calculate motor power values
			if(liftRaw > maxPower) liftRaw = 127;
			else if(liftRaw < minPower) liftRaw = -127;
			liftUp(liftRaw);//apply motor values
		}//end if(pidRunning) == true
		else{
			encoderVal = 0;
			error = 0;
			lastError = 0;
			proportion = 0;
			integral = 0;
			derivative = 0;
			liftRaw = 0;
		}//end else statement
		wait1Msec(20);//don't hog cpu
	}//end while loop

}
