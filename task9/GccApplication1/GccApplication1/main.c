/*
 * GccApplication1.c
 *
 * Created: 2019-11-14 10:36:13 AM
 * Author : paulc
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>


//F_CPU 1000000 UL


void loop()
{
	
}

void setup()
{
	DDRD |= (1<<PD6)|(1<<PD5); //set as ouput pin

	//PORTD &= ~(1<<PD6); //start pin as 0

	TCCR0B = 0x01; // normal counting mode, no clock prescaling
	//TIMSK0 |=(1<<OCIE0A)|(1<<TOIE0);		//enables timer 0 overflow interrupt
	TCCR0A |= (1<<COM0A0)| (1<<COM0A1);
	TCCR0A |= (1<<WGM00)|(1<<WGM01);
	
	TCCR0B |= (1<<COM0B0)| (1<<COM0B1);
	TCCR0B |= (1<<WGM00);
	TCCR0B |= (1<<CS00);
	
	OCR0A = 200;	//number to compare
	OCR0B = 100;

	sei();

}

int main()
{
	setup();
	while(1) loop();

}

