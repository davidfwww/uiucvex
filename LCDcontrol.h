//Global Variable
int auto = 0;

void clearLCD()
{
	clearLCDLine(0);
	clearLCDLine(1);
}

int getAuto()
{
	return auto;
}

task LCD()
{
	int buttonState = 0;
	int BigState = 0;//only two options anyway, automous and sensors
	int autoMax = 2;//change this as you increase your autonomous capacity
	int sense = 0, senseMax = 5;//change this as you increase your sensor capacity
	int update = 1;

	autoMax -= 1;//subtracts one because it uses 0 as a state

	while(true)
	{
		while(buttonState!=1)//
		{
			if(BigState == 0) //Automous
			{
				if(buttonState == 2)//if button 2 is pressed, increase auto selection
				{
					auto--;
					//clearLCD();
					update = 1;
					//displayLCDString(0,0,"Auto: "); displayNextLCDNumber(auto);//display number
					buttonState = 0;
				}
				else if(buttonState == 4)//if button 4 is pressed, decrease auto selection
				{
					auto++;
					//clearLCD();
					//displayLCDString(0,0,"Auto: ");displayNextLCDNumber(auto);//display number
					update = 1;
					buttonState = 0;
				}

				//upper and lower bounds of the autonomous mode
				if(auto>autoMax)auto=0;//if auto is more than the maxium automous, loop back to 0
				else if(auto<0)auto=autoMax;//if auto is less than 0, then loop back to autoMax

				if(update == 1)
				{
					clearLCD();
					displayLCDString(0,0,"Auto: ");displayNextLCDNumber(auto);//display number
					update = 0;
				}
			}
			else if(BigState == 1)//Sensors
			{
				if(buttonState == 2){sense++;buttonState = 0;}//if button 2 is pressed, increase sense selection
				if(sense>senseMax)sense=0;//if greater than the max senosrs, loop back to 0
				clearLCD();
				switch(sense)
				{
				case 0://wheel encoder
					displayLCDString(0,0,"wheel: ");
					displayLCDNumber(1,0,nMotorEncoder[rightDrive1]);
					if(buttonState == 4){nMotorEncoder[rightDrive1] = 0;buttonState=0;}
					break;
				case 1://body lift encoder
					displayLCDString(0,0,"body lift: ");
					displayLCDNumber(1,0,nMotorEncoder[lift]);
					if(buttonState == 4){nMotorEncoder[lift] = 0;buttonState=0;}
					break;
				case 2://collector lift encoder
					displayLCDString(0,0,"collector: ");
					displayLCDNumber(1,0,nMotorEncoder[coneRight]);
					if(buttonState == 4){nMotorEncoder[coneRight] = 0;buttonState=0;}
					break;
				case 3://gyroscope
					if(buttonState == 4)//reset gyroscope
					{
						clearLCDLine(1);
						displayLCDString(1,0,"Resetting GYRO");
						delay(1000);//wait 1 second
						//reset gyro
						SensorType[in1] = sensorNone;
						delay(1000);
						SensorType[in1] = sensorGyro;
						delay(1000);
						clearLCDLine(1);
						displayLCDString(1,0,"Done");
						delay(1000);
						buttonState = 0;
					}
					displayLCDString(1,0,"Gyro: ");
					displayNextLCDNumber(SensorValue[driveGyro]);
					break;
				case 4://lift buttons (both)
					displayLCDCenteredString(0,"liftButton");
					setLCDPosition(1,0);
					displayNextLCDNumber(SensorValue[liftBump2],1);//left bumper
					setLCDPosition(1,15);
					displayNextLCDNumber(SensorValue[liftBump1],1);//right bumper
					break;
				case 5://batteries
					displayLCDString(1,0,"Battery Av: ");
					displayNextLCDNumber(nAvgBatteryLevel/1000., 3);
					displayNextLCDChar('V');
					break;
				default://error value
					displayLCDCenteredString(0,"Error");
					break;
				}
				wait1Msec(100);//give the delay for the screen
			}
			else//not a BigState
			{
				if(BigState > 1)BigState = 0;
				else if(BigState < 0)BigState = 1;
			}
			//check to see if buttons are pressed
			if(nLCDButtons != 0)
			{
			//	while(nLCD != 0)//loop untill buttons unpressed
			//	{
					buttonState = nLCDButtons;
			//	}
			}
			while(nLCDButtons != 0){wait1Msec(50);}//wait untill button unpressed
		}//end while button != 1
		BigState++;
		buttonState = 0;
		update = 1;
	}//end while(true)
}//end task
