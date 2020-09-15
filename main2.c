/*
 * GPIO_fnd.c
 *
 * Created: 2020-09-15 오후 1:44:13
 * Author : IT학교
 * fnd 숫자 출력하기;
	(select -> pg 3~0)
	(data -> PD4~7, PB4~7)
	1234 출력
 */ 

#include <avr/io.h>
#include <util/delay.h>

unsigned char FND_DATA[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x27,0x7F,0x6F};

void fnd_init(void)
{
	//(select -> pg 3~0)
	//(data -> PD4~7, PB4~7)
	
	//data
	DDRD = 0xF0;
	DDRB = 0xF0;
	
	//select
	DDRG = 0x0F;
}

void fnd_display(int data)
{
	//PORTx = FND_DATA[data];
	PORTD = (FND_DATA[data] & 0x0F) << 4;
	PORTB = (FND_DATA[data] & 0xF0);
}

void fnd_displayAll(int index, int data)
{
	switch(index){
		case 1:		//일
			PORTG = 1;
		break;
		case 2:		//십
			PORTG = 2;
		break;
		case 3:		//백
			PORTG = 4;
		break;
		case 4:		//천
			PORTG = 8;
		break;
	}
	fnd_display(data);
}

void fnd_digit(int data)
{
	fnd_displayAll(1,data/1000);
	_delay_ms(2);
	fnd_displayAll(2,data%1000/100);
	_delay_ms(3);
	fnd_displayAll(3,data%100/10);
	_delay_ms(2);
	fnd_displayAll(4,data%10);
	_delay_ms(5);
}


int main(void)
{
	int displayData = 1234;
	
	fnd_init();
	
    while (1) 
    {
		fnd_digit(8888);
	}
}

