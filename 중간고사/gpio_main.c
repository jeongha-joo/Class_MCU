/*
 * GPIO_3.c
 *
 * Created: 2020-09-15 오후 1:13:20
 * Author : IT학교
 */ 

#include <avr/io.h>

void gpio_init(void)
{
	DDRC = 0xFF;
	DDRE |= 0x00; //(0<<PE4) | (0<<PE5) | (0<<PE6) | (0<<PE7)
	PINE = 0x00;
	PORTC = 0xFF;	//led off
}
int main(void)
{
	unsigned char swState=0;
    gpio_init();
    while (1) 
    {
		//swState = PINE;
		swState = (PINE >> 4);
		switch(swState){
			case 0x0E : 
				PORTC = 0x00;
			break;
			case 0x0D :
				PORTC = 0xFF;
			break;
			case 0x0B :
				PORTC = 0x00;
			break;
			case 0x07 :
				PORTC = 0xFF;
			break;
		}
    }
}

