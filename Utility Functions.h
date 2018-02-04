//slew function that sets max acceleration
int slew(int max, int targetSpeed, int currentSpeed) {
	int accel;

	accel = targetSpeed - currentSpeed;

	if(accel > max) accel = max;
	else if (accel < 0 - max) accel = 0 - max;

	return currentSpeed + accel;
}

//calculate error for pid
int calcError(int targetPos, int currentPos) {
	return targetPos - currentPos;
}

//calculate proportion for pid
int calcP(const float Kp, int error) {
	return Kp * error;
}

//calculate derivative for pid
int calcD(const float Kd, int error, int prevError) {
	return Kd * (error - prevError);
}
