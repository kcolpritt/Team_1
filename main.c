/*
 * main.c
 *
 *  Created on: Jan 17, 2017
 *      Author: Domin
 */

#include "main.h"

#define MODE 0

int main(){
	initRBELib();
	debugUSARTInit(115200);
	configAll();
	while(1){
		switch(MODE){
		case 0:
			buttonBlink();
			break;
		case 1:
			blink();
			break;
		case 2:
			serialReturn();
			break;
		}
	}
	return 0;
}
