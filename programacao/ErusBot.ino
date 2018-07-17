#include <Arduino.h>
#include "Pins.h"
#include "Motors.h"
#include "Sensors.h"
#include "PIDControl.h"
#include "Position.h"

#define STOP_TIME 13000

static unsigned long initialTime;
static unsigned long currentTime;
char colorLine = 'p';
int* sensors;
int pos=0; 
double signalControl;
static bool lastMoment = false;
int velocidadeMax = 25;

void setup(void)
{        
	Serial.begin(9600);
	setupSensors();
    setupMotors();
	setupPIDControl(0.029, 0.001, 0.13); //(kp=0.029,ki=0.001,kd=0.13) 
	pinMode(BUTTON, INPUT);
	sensors = readSensors(colorLine);
}

int checkInit(void)
{
	static int init = 0;
	if(!init)
	{
		if(digitalRead(BUTTON))
		{
			init = 1;
            delay(500);            
		}
	}	
	return init;
}

// retorna b se a linha for braca e p se a linha for preta
char checkColorLine (int *sensors){
	if (colorLine == 'p' && sensors[0] == HIGH && sensors[4] == HIGH){
		return 'b';
	}else if (colorLine == 'b' && sensors[0] == HIGH && sensors[4] == HIGH){
		return 'p';
	}else{
		return colorLine;
	}
}

void loop(void)
{       	
    if(!checkInit()){
		return;
	}

	//colorLine = checkColorLine (sensors);
	sensors = readSensors(colorLine);

	pos = getPosition(sensors);
        
    signalControl = round(getPIDControl(pos));

	Serial.print("signalControl: ");
	Serial.println(signalControl);
    
	// cotrole do robô
    /*if (signalControl > 0){ // estar tendendo para direita
		setMotor(1, velocidadeMax+signalControl, 1); // direita
		setMotor(0, velocidadeMax, 1); // esquerda	
	}else if (signalControl < 0){
		setMotor(1, velocidadeMax, 1); // direita
		setMotor(0, velocidadeMax-signalControl, 1); // esquerda		
	}else{
		setMotor(1, velocidadeMax, 1); // direita
		setMotor(0, velocidadeMax, 1); // esquerda		
	}*/
    
    
	// delay para adequar a taxa pra atualizar o sensor
	//delay (10);

	// para garantir a parada no local certo    
	/*if ( millis() - initialTime > STOP_TIME && lastMoment == true){
        setMotor(0,0,1);
        setMotor(1,0,1);
        
        return;
    }*/

    delay(1000);
}
