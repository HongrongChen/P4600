/*
 * GccApplication1.c
 *
 * Created: 2019-11-21 11:01:13 AM
 * Author : paulc
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>


//F_CPU 1000000 UL


void loop()
{
	ADCSRA |=(1<<ADSC); //starts data collection
	while (! ADCSRA & (1<<ADIF));//loop until ADC complete
	
	
	uint16_t lowbyte;
	uint16_t highbyte;	
	//11101101
	lowbyte = ADCL; //00000000 11011101
	highbyte = ADCH;//00000000 00000010
	uint16_t finalvalue;
	finalvalue = (highbyte <<8)|lowbyte;
	
	
	if(finalvalue<300)
	{
		PORTD &= ~(1<<PD5);
		PORTD &= ~(1<<PD6);
		PORTD |=(1<<PD7);
	}
	if(finalvalue>300 & finalvalue<600)
	{
		PORTD &= ~(1<<PD5);
		PORTD |=(1<<PD6);
		PORTD &= ~(1<<PD7);
	}
	if(finalvalue>600)
	{

		PORTD |=(1<<PD5);
		PORTD &= ~(1<<PD6);
		PORTD &= ~(1<<PD7);
	}
	
	
}

void setup()
{
	

	ADMUX |=(1<<REFS0)|(0<<REFS1);//choose ref source
	ADMUX |=(0<<MUX3)|(1<<MUX2)|(0<<MUX1)|(1<<MUX0);//output channel at ADC5
	ADCSRA |=(1<<ADEN);//turn ADC ON
	ADCSRA |=(0<<ADPS2)|(0<<ADPS1)|(0<<ADPS0);//prescaler div = 2
	DDRD |=(1<<PD5)|(1<<PD6)|(1<<PD7);//set as output pins
	
	
	

	//sei();
	
	

}

int main()
{
	setup();
	while(1) loop();

}

