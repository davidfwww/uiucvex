
void autonExecution() {
	setDrive("null", 0);
	driveStop();
	setLift(-999);
	liftStop();
	auton1();
}

void initializeGyro()
{
	SensorType[in1] = sensorNone; //clear previous sensor readings
	wait1Msec(300);
	SensorType[in1] = sensorGyro; //reconfigure port as gyro
	wait1Msec(1500);
}
