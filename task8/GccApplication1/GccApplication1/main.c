/*
 * GccApplication1.c
 *
 * Created: 2019-11-07 10:17:20 AM
 * Author : paulc
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint8_t keep_going = 1;

void loop()
{
	PORTD |= (1 << PD1);
	_delay_ms(100);
	PORTD &= ~(1 << PD1);
	_delay_ms(100);
}

void setup()
{

}

int main()
{
	setup();
	while(keep_going) loop();
	
	return 0;
}

TCNT0 = 0;
TCCR0B = (1<<C500) | (1<< C502);
while(1)
{
	while((TIFR0 & 1) == 0);
	PORTD ^=(1<<PD1);
}
