/*
 * Lab1Prelab.c
 *
 *  Created on: Jan 17, 2017
 *      Author: Domin
 */
#include "Lab1Prelab.h"

unsigned char blinkState = 0x00;

void configAll(){
	DDRAbits._P4 = INPUT; //Sets Port 4A to an input
	PORTAbits._P4 = 0x00; //Disables pullups as they are physically in the board already

	DDRBbits._P4 = OUTPUT; //Sets P4B to an output (Button Blink)
	DDRBbits._P5 = OUTPUT; //Sets P5B to an output (Blink)

	TCCR1A = BIT2 | BIT0; //Sets to clock source with prescaling of 1024
	TIMSK1= BIT0; //Set to overflow mode
	OCR1A = 488; //with a count of 488 this timer should trip every half second
	// set timer0 counter initial value to 0
	sei(); //Enable interrupts
	TCNT1=0x00;



}

void buttonBlink(){
	PINBbits._P4 = ~PINAbits._P4;
	//Reads P4A (the button), inverts the bit (0 when button pressed), then passes that to P4B to turn on the LED
}



void serialReturn(){
	if( !getCharDebug() ){
		putCharDebug(getCharDebug());
	}
}

void blink(){
	if(blinkState){
		PINBbits._P5 = 1;
	} else {
		PINBbits._P5 = 0;
	}

}

ISR(TIMER0_OVF_vect) {
	blinkState = ~blinkState;
}
