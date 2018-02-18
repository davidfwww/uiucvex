
void testAuton() {
	setDrive("forward", 500);
	wait1Msec(2000);
	setDrive("back", 500);
	wait1Msec(2000);
	setDrive("left", 900);
	wait1Msec(2000);
	setDrive("right", 900);
}

void auton1() {

	//pick up mobile goal intake
	rollerIn(10);
	setLift(300);//250
	wait1Msec(200);
	mobileOut(120);
	wait1Msec(400);
	setDrive("forward", 1250);//1200
	wait1Msec(800);
	mobileStop();
	wait1Msec(800);
	mobileIn(120);
	wait1Msec(1200);
	mobileStop();

	//drop preload
	rollerOut(100);
	wait1Msec(500);

	//adjust direction
	direction = "right";
	driveTarget = 0;
	wait1Msec(500);

	//pick up 1st cone
	rollerIn(30);
	setDrive("forward", 240);//240
	intakeDown(100);
	wait1Msec(250);
	setLift(0);
	wait1Msec(600);

	//adjust direction
	direction = "right";
	driveTarget = 0;

	//score 1st cone
	setLift(300);
	intakeUp(100);
	wait1Msec(750);
	intakeStop();
	wait1Msec(200);
	rollerOut(100);
	wait1Msec(500);

	//pick up 2nd cone
	rollerIn(30);
	setDrive("forward", 280);//300
	wait1Msec(200);
	intakeDown(100);
	wait1Msec(250);
	setLift(0);
	wait1Msec(750);


	//adjust direction
	direction = "right";
	driveTarget = 0;

	//stack 2nd cone
	setLift(300);
	intakeUp(100);
	wait1Msec(750);
	intakeStop();
	rollerOut(100);
	wait1Msec(500);

	//score
	setDrive("back", 1800);
	wait1Msec(3000);
	setDrive("left", 450);
	wait1Msec(3000);
	setDrive("back", 650);
	wait1Msec(3000);
	setDrive("left", 900);
	wait1Msec(3000);
	setDrive("null", 0);
	drive(120);
	wait1Msec(800);
	drive(0);

	//mobile goal intake out
	mobileOut(120);
	wait1Msec(1000);
	drive(-50);
	wait1Msec(500);
	mobileIn(120);
	wait1Msec(300);
	drive(-120);
	wait1Msec(1000);
	drive(0);
}

void auton2() {

}
