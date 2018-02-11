
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

	rollerIn(10);
	setLift(-999);
	liftUp(100);
	wait1Msec(200);
	liftStop();
	mobileOut(120);
	wait1Msec(400);
	setDrive("forward", 1200);
	wait1Msec(800);
	mobileStop();
	wait1Msec(800);
	mobileIn(120);
	wait1Msec(1200);
	mobileStop();
	rollerOut(100);
	wait1Msec(500);
	rollerIn(30);

	setDrive("forward", 240);
	intakeDown(100);
	wait1Msec(250);
	liftUp(-75);
	wait1Msec(600);
	liftUp(100);
	intakeUp(100);
	wait1Msec(350);
	liftStop();
	wait1Msec(400);
	intakeStop();
	rollerOut(100);
	wait1Msec(500);

	setDrive("forward", 300);
	intakeDown(100);
	wait1Msec(250);
	liftUp(-100);
	wait1Msec(850);
	liftUp(100);
	intakeUp(100);
	wait1Msec(350);
	liftStop();
	wait1Msec(400);
	intakeStop();
	rollerOut(100);
	wait1Msec(500);


}

void auton2() {

}
