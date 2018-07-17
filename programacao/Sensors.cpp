#include <Arduino.h>
#include "Pins.h"
#include "Sensors.h"

static int sensorsValues[6];

void setupSensors(void)
{
	pinMode(LIGHT_SENSOR_1, INPUT);
	pinMode(LIGHT_SENSOR_2, INPUT);
	pinMode(LIGHT_SENSOR_3, INPUT);
	pinMode(LIGHT_SENSOR_4, INPUT);
	pinMode(LIGHT_SENSOR_5, INPUT);
}

// Linha pode ser (p)reta ou (b)ranca.
int* readSensors(char linha)
{        
	//Lógica para linha preta em caminho branco; para linha branca em caminho preto retirar '1 -'        
    if (linha=='p'){        
	 	sensorsValues[4] = 1-digitalRead(LIGHT_SENSOR_1); 
		sensorsValues[3] = 1-digitalRead(LIGHT_SENSOR_2);
		sensorsValues[2] = 1-digitalRead(LIGHT_SENSOR_3);
    	sensorsValues[1] = 1-digitalRead(LIGHT_SENSOR_4);
		sensorsValues[0] = 1-digitalRead(LIGHT_SENSOR_5);
	}else if (linha=='b'){
	 	sensorsValues[4] = digitalRead(LIGHT_SENSOR_1); 
		sensorsValues[3] = digitalRead(LIGHT_SENSOR_2);
		sensorsValues[2] = digitalRead(LIGHT_SENSOR_3);
    	sensorsValues[1] = digitalRead(LIGHT_SENSOR_4);
		sensorsValues[0] = digitalRead(LIGHT_SENSOR_5);	
	}
	
	/*Serial.print("Sensors: ");
	int i;
	for (i=0; i<5; i++){
		Serial.print(sensorsValues[i]);
		if (i==4)
			Serial.println("");

		Serial.print(" | ");
	}

	delay(500);
	*/

	return &(sensorsValues[0]);
}
