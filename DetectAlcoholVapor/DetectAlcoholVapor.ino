/*****************************************************************************/
//	Function: MQ303A Testing - A simple sketch to understand the working of Alcohol sensor.
//			  It can be used to study how to calibrate threshold values. 
//  Hardware: Grove - Alcohol Sensor
//	Arduino IDE: Arduino-1.0
//	Author:	 Frankie.Chu		
//	Date: 	 Jan 21,2013
//	Version: v1.0
//	by www.seeedstudio.com
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
/*******************************************************************************/

/*macro definitions of Alcohol Sensor's pins*/
#define ALCOHOL_DAT A0
#define HEATER_SEL	A1
 
void setup() 
{.
	Serial.begin(9600);  // open the serial port at 9600 bps
	pinsInit();
	switchOnHeater(); 
	Serial.println("Start to heat the sensor, please wait 5~10min befor exposure to alcohol");
}
void loop() 
{
	int sensorValue;
	sensorValue = analogRead(ALCOHOL_DAT); //read the analog value 
	int value = 1023 - sensorValue;
	//Disply the results in serial monitor.
	Serial.print("sensor test value = ");                       
	//sensorValue goes down when alcohol is detected. Hence subtracting from 1023.
	Serial.println(value); 
	/*The information below is recommended result of the judgment*/
	if(value < 200)
		Serial.println("No alcohol vapor detected");
	else if((value > 600) && (value < 750))
		Serial.println("High Concentration of Alcohol detected");
	else
		Serial.println("Very high Concentration of Alcohol detected");
	delay(100);  
}

void pinsInit()
{
	pinMode(HEATER_SEL,OUTPUT);// set the HEATER_SEL as digital output.
	switchOffHeater(); //when HEATER_SEL is set, heater is switched off.
	pinMode(ALCOHOL_DAT,INTPUT);
}
/*switch on the heater of Alcohol sensor*/
void switchOnHeater()
{
	digitalWrite(HEATER_SEL,LOW); 
}
/*switch off the heater of Alcohol sensor*/
void switchOffHeater()
{
	digitalWrite(HEATER_SEL,HIGH); 
}

