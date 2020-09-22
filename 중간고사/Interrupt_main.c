/*
 * EXInterrupt.c
 *
 * Created: 2020-09-15 오후 4:11:24
 * Author : IT학교
 */ 


/*
	SW = pe7
	led = pc0~7
*/
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

unsigned char flag;

ISR(INT7_vect)
{
	flag = !flag;
}

void gpio_init()
{
	DDRE = 0x00;	//sw
	DDRC = 0xff;	//led
	PORTC = 0xff;
}

void exir_init()
{
	EIMSK = (1<<INT7);
	EICRB = (1<<ISC71) || (1<<ISC70);
	EIFR = 0x00;	//인터럽트 부분 클리어
	sei();			//전역 인터럽트 설정
	//cli();
}

int main(void)
{
	gpio_init();
	exir_init();
	unsigned char ledData=1;
	
    while (1) 
    {
		for(int i = 0; i < 8; ++i){
			if(flag)
				break;
			PORTC = ~ledData;
			ledData = ledData << 1;
			_delay_ms(500);
		}
		ledData = 1;
		PORTC = 0xff;
		_delay_ms(500);
    }
}
-_-v