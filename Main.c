#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    driveGyro,      sensorGyro)
#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in1,    driveGyro,      sensorNone)
#pragma config(Sensor, dgtl1,  liftBump,       sensorTouch)
#pragma config(Sensor, dgtl2,  liftQuad,       sensorQuadEncoder)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           mobileLeft,    tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           coneLeft,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           leftDrive1,    tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port4,           leftDrive2,    tmotorVex393_MC29, openLoop, reversed, driveLeft)
#pragma config(Motor,  port5,           leftLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rightLift,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           rightDrive1,   tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port8,           rightDrive2,   tmotorVex393_MC29, openLoop, reversed, driveRight, encoderPort, I2C_1)
#pragma config(Motor,  port9,           coneRight,     tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port10,          mobileRight,   tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

//Sensor definitions
#define liftPos SensorValue(liftQuad)
#define intakePos nMotorEncoder[coneRight]

//Included files
#include "Drive Control.h"
#include "Mobile Control.c"
#include "Lift Control.c"
#include "Intake Control.c"
#include "LCDcontrol.h"

void pre_auton() {}

task autonomous() {
	startTask(liftControl);
	startTask(intakeControl);
}

task usercontrol() {
	while(true) {
		startTask(liftControl);
		startTask(intakeControl);
		startTask(LCD);
		manualLift();
		manualIntake();
		manualMobile();
		manualDrive();
	}
}