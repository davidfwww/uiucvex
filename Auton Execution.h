
void autonExecution(int selection) {
	liftPos = 0;
	gyroPos = 0;
	setDrive("null", 0);
	driveStop();
	setLift(-999);
	liftStop();
	//if add more choices, don't forget to change the autoMax in the LCDcontrol.h file

	//display chioce
	clearLCDLine(0);
	clearLCDLine(1);
	displayLCDNumber(0,1,selection);

	switch(selection)
	{
		case 0:
			leftAuton();
			break;
		case 1:
			rightAuton();
			break;
		case 2:
			noAuton();
			break;
		case 3:
			secretLeft();
			break;
		case 4:
			secretRight();
			break;
		default: //do nothing
			noAuton();
			break;
	}
}

void initializeGyro()
{
	SensorType[in1] = sensorNone; //clear previous sensor readings
	wait1Msec(300);
	SensorType[in1] = sensorGyro; //reconfigure port as gyro
	wait1Msec(1500);
}
