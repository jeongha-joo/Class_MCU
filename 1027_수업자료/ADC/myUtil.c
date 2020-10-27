/*
 * myUtil.c
 *
 * Created: 2020-10-27 오후 3:42:41
 *  Author: IT학교
 */ 

#include <avr/io.h>
#include <util/delay.h>

unsigned char FND_DATA[] ={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x27,0x7f,0x6f} ;

void fnd_init(void)
{
	//data
	DDRD  = 0xF0;//0b1111 0000
	DDRB  = 0xF0;//0b1111 0000
	
	//select	 pg3~0
	DDRG = 0x0F;////0b0000 1111
}

void fnd_data(int data)
{
	//PORTx = FND_DATA[data];
	PORTD = (FND_DATA[data] & 0x0F) << 4 ;
	PORTB = (FND_DATA[data] & 0xF0) ;
}

void fnd_display(int index, int data)
{
	//select PG0-> FND출력(전체)
	//일자리 0bxxxx 0001
	//십자리 0bxxxx 0010
	//백자리 0bxxxx 0100
	//천자리 0bxxxx 1000
	switch(index){
		case 1: //0x01 일
		PORTG = 1;
		break;
		case 2: //0bxxxx 0010 십
		PORTG = 2;
		break;
		case 3: //0bxxxx 0100 백
		PORTG = 4;
		break;
		case 4: //0bxxxx 1000 천
		PORTG = 8;
		break;
		
	}
	fnd_data(data);
}

void fnd_displayAll(int data)
{
	fnd_display(1,data/1000);
	_delay_ms(2);
	fnd_display(2,(data%1000)/100);
	_delay_ms(3); 
	fnd_display(3,data%100/10);
	_delay_ms(2);
	fnd_display(4,data%10);
	_delay_ms(5);
}