#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    driveGyro,      sensorGyro)
#pragma config(Sensor, dgtl1,  liftBump1,      sensorTouch)
#pragma config(Sensor, dgtl2,  liftBump2,      sensorTouch)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           mobileLeft,    tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           coneLeft,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rightDrive1,   tmotorVex393_MC29, openLoop, reversed, driveLeft, encoderPort, I2C_1)
#pragma config(Motor,  port4,           rightDrive2,   tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port5,           roller,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           lift,          tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port7,           leftDrive1,    tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port8,           leftDrive2,    tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port9,           coneRight,     tmotorVex393_MC29, openLoop, encoderPort, I2C_3)
#pragma config(Motor,  port10,          mobileRight,   tmotorVex393_HBridge, openLoop)

#define liftPos nMotorEncoder[lift]

int liftTarget;
bool newLiftTarget = true;

void liftUp(int speed) {
	motor[lift] = speed;
}

void liftStop() {
	liftUp(0);
}

void setLift(int target) {
	liftTarget = target;
	newLiftTarget = true;
}

task main(){
	int liftState = 1;

	float Kp = 1.0;
	float Kd = 0.6;

	int proportion;
	int derivative;
	int error;
	int prevError;
	int raw;

	while(true) {

		error = liftTarget - liftPos;

		proportion = Kp * error;

		derivative = Kd * (error - prevError);
		prevError = error;
		if (newLiftTarget) derivative = 0;

		raw = proportion + derivative;
		if (raw > 100) raw = 100;

		liftUp(raw);

		newLiftTarget = false;
		wait1Msec(20);
	}
}
