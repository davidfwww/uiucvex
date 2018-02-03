void clearScreen();
//void buttonP();
int buttonP(bool *e);

task LCD()
{
	byte screen = 0;
	byte screenMAX = 2;
	bool enter = false;
	byte auto = 1;
	byte select = 1;
	byte selectMAX = 1;//enter how many autonoumous functions you have here
	byte sense = 0;
	byte senseMAX = 3;//enter how many sensors you have
	int bState = 0;
	while(true)
	{
		writeDebugStreamLine("nLCDButtons: %d",nLCDButtons);
		writeDebugStreamLine("screen: %d",screen);
		bState = buttonP(&enter);

		//first button is 1, second button is 2, third button is 4
		while(bState != 2)//push the middle button for screen change
		{
			clearScreen();
			switch(screen)
			{
			case 0://Autonomous Selection
				writeDebugStreamLine("Autonomous");
				displayLCDString(0,0,"Autonomous");
				displayLCDNumber(0,13,auto);
				if(bState==1)
				{
					//buttonP(&enter); //enter is button value of 5
					if(enter){auto=select;}//assigns number to auto if enter is pressed
					else{select--;}//decremetns select value otherwise
				}
				else if(bState==4)
				{
					//buttonP(&enter);
					if(enter){auto=select;}//assigns number to auto if enter is pressed
					else{select++;}//increments select value otherwise
				}
				if(select>selectMAX){select=0;}
				else if(select<1){select=selectMAX;}
				break;//end of autonomous case
			case 1://Sensors
				writeDebugStreamLine("Sensors");
				displayLCDString(0,0,"Sensors");
				if(bState==1)
				{
					//buttonP();
					if(sense<0){sense=senseMAX;}
					else{sense--;}
				}
				else if(bState==4)
				{
					//buttonP();
					if(sense>senseMAX){sense = 0;}
					else{sense++;}
				}
				switch(sense)
				{
				case 0://lift buttons
					displayLCDString(1,0,"liftButton1: ");
					displayNextLCDNumber(1,SensorValue[liftBump1]);
					displayLCDString(1,0,"liftButton2: ");
					displayNextLCDNumber(1,SensorValue[liftBump2]);
					break;
				case 1://gyroscope
					displayLCDString(1,0,"Gyro: ");
					displayNextLCDNumber(SensorValue[driveGyro]);
					//buttonP(&enter);
					if(enter)
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
					}
					break;
				case 2://
					break;

				default:
					displayLCDCenteredString(1,"ERROR NO SENSOR");
					break;
				}
				break;//end of sensor case
			case 2://battery percentage
				writeDebugStreamLine("battery");
				displayLCDString(0,0,"Battery Im: ");
				displayNextLCDNumber(nImmediateBatteryLevel/1000., 3);
				displayNextLCDChar('V');
				displayLCDString(1,0,"Battery Av: ");
				displayNextLCDNumber(nAvgBatteryLevel/1000., 3);
				displayNextLCDChar('V');
				break;//end of battery case
			default:
				displayLCDCenteredString(1,"ERROR FIX ME");
				break;
			}//end of sensor switch
		}//end of while button != 2
		screen = screen + 1;
		if(screen>screenMAX){screen = 0;}//cycle through again
		delay(50);
	}//end of while(true)
}//end of task

void clearScreen()
{
	clearLCDLine(0);
	clearLCDLine(1);
}

//byte buttonP()
//{
//	while(nLCDButtons != 0)
//	{

//	}//wait untill unpressed
//	delay(10);
//}

int buttonP(bool *e)
{
	*e = false;//if not 5 then return 0 through pointer
	int press = nLCDButtons;
	if(press == 0)
	{
		return 0;
	}
	while(press != 0)//wait untill unpressed
	{
		press = nLCDButtons;
	}
	if(nLCDButtons == 5){*e = true;}//if 5 then return 1
	return press;
}
