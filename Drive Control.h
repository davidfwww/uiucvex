
int driveTarget;
char* direction;
bool newDriveTarget = true;

//drive constants
const int JOYSTICK_THRESHOLD = 15;
const int MAX_ACCEL = 10;

//sets right joystick threshold
int adjustJoy(int joy) {
	if(abs(joy) > JOYSTICK_THRESHOLD) return joy; //set right joystick threshold
	else return 0;
}

//manual drive function
void manualDrive() {
	//set joystick thresholds
	int rightJoy = adjustJoy(rightJoyRaw);
	int leftJoy = adjustJoy(leftJoyRaw);

	//calculate target speed
	int rightDriveSpeed = leftJoy - rightJoy;
	int leftDriveSpeed = leftJoy + rightJoy;

	//apply slew
	rightDriveSpeed = slew(MAX_ACCEL, rightDriveSpeed, motor[rightDrive1]);
	leftDriveSpeed = slew(MAX_ACCEL, leftDriveSpeed, motor[leftDrive1]);

	//apply motor values
	motor[rightDrive1] = rightDriveSpeed;
	motor[rightDrive2] = rightDriveSpeed;
	motor[leftDrive1] = leftDriveSpeed;
	motor[leftDrive2] = leftDriveSpeed;
}

void setDrive(char* dir, int target)
{
	direction = dir;
	driveTarget = target;
	driveEncoder = 0;
	gyroPos = 0;
	newDriveTarget = true;
	if (direction == "right" || direction == "back") driveTarget *= -1;
}

//positive is forward
void drive(int speed) {
	motor[rightDrive1] = speed;
	motor[rightDrive2] = speed;
	motor[leftDrive1] = speed;
	motor[leftDrive2] = speed;
}

//positive is clockwise
void turn(int speed) {
	motor[rightDrive1] = speed;
	motor[rightDrive2] = speed;
	motor[leftDrive1] = -speed;
	motor[leftDrive2] = -speed;
}

void driveStop() {
	drive(0);
}

//drive control task
task driveControl(){
	int driveState = 0;

	//pd constants
	const float encoderKp = 1.0;
	const float encoderKd = 5.0;
	const float gyroKp = 0.55;
	const float gyroKd = 1.35;
	const float maxTurnPower = 90;

	int proportion;
	int derivative;
	int error;
	int prevError;
	int raw;

	while(true) {
		if (!isAuton) driveState = 0;
		else if (direction == "null") driveState = 1;
		else if (direction == "forward" || direction == "back") driveState = 2;
		else if (direction == "right" || direction == "left") driveState = 3;

		switch(driveState) {
			//manual drive case
			case 0:
				manualDrive();
				break;
			//auton no pid case
			case 1:

				break;
			//auton encoder pid case
			case 2:
				//drive encoder counts backward
				error = driveTarget + driveEncoder;

				proportion = encoderKp * error;

				derivative = encoderKd * (error - prevError);
				prevError = error;
				if (newDriveTarget) derivative = 0;

				raw = proportion + derivative;

				drive(raw);

				newDriveTarget = false;
				break;
			//auton gyro pid case
			case 3:
				error = driveTarget - gyroPos;

				proportion = gyroKp * error;

				if (proportion > maxTurnPower) proportion = maxTurnPower;
				else if (proportion < -maxTurnPower) proportion = -maxTurnPower;

				derivative = gyroKd * (error - prevError);
				prevError = error;
				if (newDriveTarget) derivative = 0;

				raw = proportion + derivative;

				turn(raw);

				newDriveTarget = false;
				break;
			//default case: manual controls
			default:
				manualDrive();
				break;
		}
		wait1Msec(20);
	}
}
