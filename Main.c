#pragma config(Sensor, in1,    driveGyro,      sensorGyro)
#pragma config(Sensor, dgtl1,  liftBump,       sensorTouch)
#pragma config(Sensor, dgtl2,  liftQuad,       sensorQuadEncoder)
#pragma config(Motor,  port1,           mobileLeft,    tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           coneLeft,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           leftDrive1,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftDrive2,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           leftLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rightLift,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           rightDrive1,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightDrive2,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           coneRight,     tmotorVex393_MC29, openLoop)
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

//Included files
#include "Basic Movement.c"
#include "Lift Control.c"

void pre_auton() {}

task autonomous() {
	startTask(liftControl);
}

task usercontrol() {
	while(true) {
		startTask(liftControl);
		manualLift();
		manualIntake();
		manualMobile();
		manualDrive();
	}
}
