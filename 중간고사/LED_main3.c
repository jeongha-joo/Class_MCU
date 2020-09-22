#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 0xFF;
	DDRA = 0xFF;
	DDRB = 0xFF;
	
	PORTA = 0xAA;
	PORTB = 0x10;
	PORTC = 0x10;
	
}

