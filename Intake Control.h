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

void manualIntake() {
	if (vexRT[Btn8U] == 1) {
		intakeUp(100);
	}
	else if (vexRT[Btn8D] == 1) {
		intakeDown(100);
	}
	else {
		intakeStop();
	}
}

void setIntake(int target) {
	intakeTarget = target;
}

task intakeControl(){
	bool pidRunning = false; //boolean to activate/deactivate PID
	int intakeState = 1;

	//PID variables
	int potVal;
	int error;
	int errorPrevious;
	int proportion;
	int integral;
	int derivative;
	int intakeRaw;

	//PID CONSTANTS
	const int scale = 10;
	const float Kp = 0.3 * scale;
	const float Ki = 0.0;
	const float Kd = 0.5 * scale;
	const int integralLimit = 50;
	const int maxPower = 120;
	const int minPower = -120;

	while(true){
		if(bIfiAutonomousMode == true){ //allow values to be sent from elsewhere in program
			intakeState = 3;
		}//end if statement
		else if(vexRT[Btn8U] == 1 || vexRT[Btn8D] == 1) intakeState = 1;
		else if(vexRT[Btn5U] == 1) intakeState = 2;

		switch(intakeState){ //intakeState determines code segment
		case 1: //Manual controls
			pidRunning = false;
			manualIntake();
			break;
		case 2: //automated stack
			pidRunning = true;
			break;
		case 3: //Auton
			if(intakeTarget == -999) pidRunning = false;
			else pidRunning = true;
			break;
		default: //Default manual
			pidRunning = false;
			manualIntake();
			break;
		}//end switch case

		if(pidRunning == true){
			potVal = intakePos / scale;
			error = intakeTarget - potVal; //calculate error

			if(Ki != 0){
				if(abs(error) < integralLimit) integral += error;
				else if(error > integralLimit) integral = integralLimit;
				else if(error < 0 - integralLimit) integral = 0 - integralLimit;
				else integral = 0;
			}//end if(Ki != 0)
			else {
				integral = 0;
			}//end else statement

			proportion = Kp * error; //calculate proportion
			derivative = Kd * (error - errorPrevious); //calculate derivative
			errorPrevious = error; //set "previous error"
			integral *= Ki; // calculate integral

			intakeRaw = proportion + integral + derivative; //calculate motor value
			if(intakeRaw > maxPower) intakeRaw = 127;
			else if(intakeRaw < minPower) intakeRaw = -127;

			intakeUp(intakeRaw);//apply motor values
		}//end if(pidRunning == true)
		else { //clear all
			potVal = 0;
			error = 0;
			errorPrevious = 0;
			proportion = 0;
			integral = 0;
			derivative = 0;
			intakeRaw = 0;
		}//end else statement
		wait1Msec(20);//don't hog cpu
	}//end while loop
}//end task
