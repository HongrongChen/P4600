/*
 * GccApplication1.c
 *
 * Created: 2019-11-25 10:54:21 AM
 * Author : paulc
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
int setup(void)
{
	DDRB |=(1<<PB3) | (1<<PB5) | (1<<PB6)|(1<<PB2);	
	SPCR |= (1<<SPE)|(1<<CPOL)|(1<<MSTR);
	PORTB |= (1<<PB2);//SS high
}

int main(void)
{
	setup();
    //uint8_t data;
	uint8_t datareceived;
	int i;
	while (1)
	{
		
		for(i=0;i<255;i++)
		{
			
			
			PORTB &= ~(1<<PB6);//pulls chip select low
			SPDR = i;
			while(!(SPSR & (1<<SPIF)));
			
			datareceived = SPDR;
			PORTB |= (1<<PB6);//set chip select high	
			_delay_ms(100);
		}
	}

}

