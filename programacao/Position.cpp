#include <Arduino.h>
#include "Pins.h"
#include "Position.h"

/*
A variavel statePosition vai armazenar o estado atual da posição e a partir dela
será atribuido um valor para atual posição.

Significado dos estados:
0 - O sensor S5 está na linha           ### extrema direita
1 - Gap entre sensores S4 e S5          ### media direita
2 - O sensor S4 está na linha           ### pouco a direita
3 - O sensor S3 e S4 estão na linha     ### um pouquinho a direita
4 - O sensor S3 está na linha           ### centro
5 - O sensor S2 e S3 estão na linha     ### um pouquinho a esquerda
6 - O sensor S2 está na linha           ### pouco a esquerda
7 - Gap entre os sensores S1 e S2       ### media esquerda
8 - O sensor S1 está na linha           ### extrema esquerda
*/

/* Disposição dos sensores:

S1 = sensors[4]
S2 = sensors[3]
S3 = sensors[2]
S4 = sensors[1]
S5 = sensors[0]

*/

unsigned int statePosition;
unsigned int lastStatePosition;


int findStatePosition(int* sensors)
{
	if (sensors[0] == HIGH && sensors[1] == LOW && sensors[2] == LOW &&
		sensors[3] == LOW && sensors[4] == LOW){
		statePosition = 0;
	}else if (sensors[0] == LOW && sensors[1] == LOW && sensors[2] == LOW &&
		sensors[3] == LOW && sensors[4] == LOW && (lastStatePosition == 0 || lastStatePosition == 2)){
		statePosition = 1;
	}else if (sensors[0] == LOW && sensors[1] == HIGH && sensors[2] == LOW &&
		sensors[3] == LOW && sensors[4] == LOW){
		statePosition = 2;
	}else if (sensors[0] == LOW && sensors[1] == HIGH && sensors[2] == HIGH &&
		sensors[3] == LOW && sensors[4] == LOW){
		statePosition = 3;
	}else if (sensors[0] == LOW && sensors[1] == LOW && sensors[2] == HIGH &&
		sensors[3] == LOW && sensors[4] == LOW){
		statePosition = 4;
	}else if (sensors[0] == LOW && sensors[1] == LOW && sensors[2] == HIGH &&
		sensors[3] == HIGH && sensors[4] == LOW){
		statePosition = 5;
	}else if (sensors[0] == LOW && sensors[1] == LOW && sensors[2] == LOW &&
		sensors[3] == HIGH && sensors[4] == LOW){
		statePosition = 6;
	}else if (sensors[0] == LOW && sensors[1] == LOW && sensors[2] == LOW &&
		sensors[3] == LOW && sensors[4] == LOW && (lastStatePosition == 8 || lastStatePosition == 6)){
		statePosition = 7;
	}else if (sensors[0] == LOW && sensors[1] == LOW && sensors[2] == LOW &&
		sensors[3] == LOW && sensors[4] == HIGH){
		statePosition = 8;
	}        

	lastStatePosition = statePosition;
    return statePosition;
}

// função para definir a distancia da linha de acordo com o estado indicado pelos sensores
int getPosition(int* sensors){
	int position,statePos;
		
	statePos = findStatePosition (sensors);

	switch (statePos){
		case 0:
			position = 45; // extrema direita
		break;

		case 1:
			position = 35; // media direita
		break;

		case 2:
			position = 20; // pouco a direita
		break;

		case 3:
			position = 10; // pouquíssimo a direita
		break;

		case 4: 
			position = 0; // centro
		break;

		case 5:
			position = -10; // pouquíssimo a esquerda
		break;

		case 6:
			position = -20; // pouco a esquerda
		break;

		case 7:
			position = -35; // Media esquerda
		break;

		case 8:
			position = -45; // extrema esquerda
		break;
	}


	
	Serial.print("State Position: ");
	Serial.println(statePos);



	return position;
}


