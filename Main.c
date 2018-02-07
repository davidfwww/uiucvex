#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    driveGyro,      sensorGyro)
#pragma config(Sensor, dgtl1,  liftBump1,      sensorTouch)
#pragma config(Sensor, dgtl2,  liftBump2,      sensorTouch)
#pragma config(Sensor, dgtl3,  liftQuad,       sensorQuadEncoder)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           mobileLeft,    tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           coneLeft,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           leftDrive1,    tmotorVex393_MC29, openLoop, driveLeft, encoderPort, I2C_1)
#pragma config(Motor,  port4,           leftDrive2,    tmotorVex393_MC29, openLoop, reversed, driveLeft)
#pragma config(Motor,  port5,           roller,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           lift,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           rightDrive1,   tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port8,           rightDrive2,   tmotorVex393_MC29, openLoop, reversed, driveRight)
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
#define driveEncoder nMotorEncoder[leftDrive1]
#define gyroPos SensorValue(driveGyro)
#define rightJoyRaw vexRT[Ch1]
#define leftJoyRaw vexRT[Ch3]
#define isAuton bIfiAutonomousMode

//Included files
#include "Utility Functions.h"
#include "Drive Control.h"
#include "Lift Control.h"
#include "Intake Control.h"
#include "Mobile Control.h"
#include "LCDcontrol.h"


void pre_auton() {}

task autonomous() {

}

task usercontrol() {
	startTask(liftControl);
	startTask(intakeControl);
	startTask(driveControl);
	startTask(LCD);
	while(true) {
		manualMobile();
	}
}
