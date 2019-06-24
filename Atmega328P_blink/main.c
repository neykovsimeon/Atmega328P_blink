/*
 * Atmega328P_blink.c
 *
 * Created: 16.6.2019 г. 17:44:45
 * Author : PC
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	MCUSR = (1<<EXTRF);
	/* Replace with your application code */
    DDRC |= (1 << PINC5);	// set as output
	DDRC |= (1 << PINC6);	// set as output
	PORTC &= ~(1 << PINC6); // set LOW, LED OFF
	PORTC |= (1 << PINC5);  // set HIGH, LED ON
	
	while (1) 
    {
		PORTC ^= (1 << PINC6);
		PORTC ^= (1 << PINC5);
		_delay_ms(500);
    }
}

