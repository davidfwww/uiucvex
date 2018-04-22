
void testAuton() {
	setDrive("forward", 500);
	wait1Msec(2000);
	setDrive("back", 500);
	wait1Msec(2000);
	setDrive("left", 900);
	wait1Msec(2000);
	setDrive("right", 900);
}

void leftAuton() {

	//pick up mobile goal intake
	rollerIn(10);
	setLift(300);//250
	wait1Msec(200);
	mobileOut(120);
	wait1Msec(400);
	setDrive("forward", 1400);//1250//1200
	wait1Msec(800);
	mobileStop();
	wait1Msec(800);
	mobileIn(120);
	wait1Msec(1200);
	mobileStop();
	wait1Msec(200);

	//drop preload
	rollerOut(100);
	wait1Msec(500);

	//adjust direction
	direction = "right";
	driveTarget = 0;
	wait1Msec(500);

	//pick up 1st cone
	rollerIn(30);
	setDrive("forward", 225);//240
	intakeDown(100);
	wait1Msec(250);
	setLift(0);
	wait1Msec(1000);

	//adjust direction
	direction = "right";
	driveTarget = 0;

	//score 1st cone
	setLift(300);
	intakeUp(100);
	wait1Msec(750);
	intakeStop();
	wait1Msec(300);
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
	intakeStop();

	//score
	setDrive("back", 1935);//1950//1800
	wait1Msec(3000);
	setDrive("left", 450);
	wait1Msec(1500);
	setDrive("back", 550);//650
	wait1Msec(1500);
	setDrive("left", 900);
	wait1Msec(1500);
	setDrive("null", 0);
	drive(70);
	wait1Msec(1200);
	drive(30);

	//mobile goal intake out
	mobileOut(120);
	wait1Msec(1300);
	mobileStop();
	drive(-50);
	wait1Msec(1000);

	//retract
	mobileIn(120);
	wait1Msec(700);
	drive(-120);
	wait1Msec(400);
	mobileStop();
	drive(0);

	wait1Msec(500);
}

void rightAuton() {
	//pick up mobile goal intake
	rollerIn(10);
	setLift(300);//250
	wait1Msec(200);
	mobileOut(120);
	wait1Msec(400);
	setDrive("forward", 1400);//1250//1200
	wait1Msec(800);
	mobileStop();
	wait1Msec(800);
	mobileIn(120);
	wait1Msec(1200);
	mobileStop();
	wait1Msec(200);

	//drop preload
	rollerOut(100);
	wait1Msec(500);

	//adjust direction
	direction = "left";
	driveTarget = 0;
	wait1Msec(500);

	//pick up 1st cone
	rollerIn(30);
	setDrive("forward", 225);//240
	intakeDown(100);
	wait1Msec(250);
	setLift(0);
	wait1Msec(750);

	//adjust direction
	direction = "left";
	driveTarget = 0;

	//score 1st cone
	setLift(300);
	intakeUp(100);
	wait1Msec(750);
	intakeStop();
	wait1Msec(300);
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
	direction = "left";
	driveTarget = 0;

	//stack 2nd cone
	setLift(300);
	intakeUp(100);
	wait1Msec(750);
	intakeStop();
	rollerOut(100);
	wait1Msec(500);

	//score
	setDrive("back", 1935);//1950
	wait1Msec(3000);
	setDrive("right", 450);
	wait1Msec(1500);
	setDrive("back", 550);//650
	wait1Msec(1500);
	setDrive("right", 900);
	wait1Msec(1500);
	setDrive("null", 0);
	drive(100);
	wait1Msec(1200);
	drive(30);

	//mobile goal intake out
	mobileOut(120);
	wait1Msec(1300);
	mobileStop();
	drive(-50);
	wait1Msec(1000);
	mobileIn(120);
	wait1Msec(700);
	drive(-120);
	wait1Msec(400);
	mobileStop();
	drive(0);
}

void secretLeft() {
	leftAuton();

	//aim at second mobile goal
	setDrive("forward", 165);
	wait1Msec(750);
	setDrive("left", 1300);//1250
	wait1Msec(1500);
	mobileOut(100);
	wait1Msec(1000);
	setDrive("forward", 1555);
	wait1Msec(2000);
	setDrive("left", 400);
	wait1Msec(1000);
	mobileStop();
	wait1Msec(2500);
	setDrive("back", 325);
	wait1Msec(1000);
	setDrive("right", 275);
	wait1Msec(700);
	setDrive("forward", 325);//250
	wait1Msec(750);
	mobileIn(100);
	wait1Msec(750);
	mobileStop();
	setDrive("back", 915);
	wait1Msec(1500);
	setDrive("left", 1105);
	wait1Msec(1500);
	setDrive("forward", 600);
	wait1Msec(1000);
	mobileOut(100);
	wait1Msec(750);
	setDrive("null", -99999);
	drive(-50);
	mobileIn(100);
	wait1Msec(500);
	mobileStop();
}

void secretRight() {
	rightAuton();

	//aim at second mobile goal
	setDrive("forward", 165);
	wait1Msec(750);
	setDrive("right", 1300);//1375
	wait1Msec(1500);
	mobileOut(100);
	wait1Msec(1000);
	setDrive("forward", 1555);
	wait1Msec(500);
	setDrive("right", 400);
	wait1Msec(1000);
	mobileStop();
	wait1Msec(2500);
	setDrive("back", 325);
	wait1Msec(1000);
	setDrive("left", 275);
	wait1Msec(700);
	setDrive("forward", 325);//250
	wait1Msec(750);
	mobileIn(100);
	wait1Msec(750);
	mobileStop();
	setDrive("back", 915);
	wait1Msec(1500);
	setDrive("right", 1105);
	wait1Msec(1500);
	setDrive("forward", 600);
	wait1Msec(1000);
	mobileOut(100);
	wait1Msec(750);
	setDrive("null", -99999);
	drive(-50);
	mobileIn(100);
	wait1Msec(500);
	mobileStop();
}

void noAuton() {
	//literally do nothing
}
