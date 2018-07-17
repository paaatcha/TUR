#include <Arduino.h>
#include "Pins.h"
#include "PIDControl.h"

static double kp, ki, kd;
static int lastPosition;
static long int sumPosition;
static long int saturationPosition;

void setupPIDControl(double kpp, double kip, double kdp)
{
	lastPosition = 0;
	sumPosition = 0;
	kp = kpp;
	ki = kip;
	kd = kdp;
	saturationPosition = 100;
}

static long int saturate (long int sumPosition)
{
	if(sumPosition > saturationPosition)
	{
		return saturationPosition;
	}
	
	if(sumPosition < -saturationPosition)
	{
		return -saturationPosition;
	}
	return sumPosition;
}

double getPIDControl(int position)
{
	if (position == 0){
		sumPosition = sumPosition/2;
	} else {	
		sumPosition = sumPosition + position;
		sumPosition = saturate(sumPosition);
	}

	double p = kp*position;
	double i = ki*sumPosition;
	double d = kd*(position - lastPosition);
	
	Serial.print("Position: ");
	Serial.println(position);

	Serial.print("p: ");
	Serial.println(p);

	Serial.print("i: ");
	Serial.println(i);

	Serial.print("d: ");
	Serial.println(d);
	
	//delay(500);

	lastPosition = position;
	
	return (p+i+d);
}
