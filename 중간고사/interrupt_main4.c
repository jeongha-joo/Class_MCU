/*
 * ExInterrupt4.c
 *
 * Created: 2020-09-22 오후 3:34:25
 * Author : IT학교
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned char FND_DATA[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x67};
int fnd_data = 0;

void fnd_init(){
	DDRD = 0xF0;
	DDRB = 0xF0;
	DDRG = 0x0F;
}

ISR(INT5_vect){
	//sw_flag = !sw_flag;
	fnd_data = fnd_data << 1;
	PORTC = ~fnd_data;
}

void swInterrupt_init(){
	//DDRE(pe5-int5) 입력용 설정
	DDRE = (0<<PE7);
	// 외부인터럽트 int5 설정
	EIMSK = (1 << INT7);
	// 검출한 신호 설정 (low level)
	EICRB = (1 << ISC71) | (0 << ISC70);
	// 모든 외부인터럽트 발생을 초기화
	EIFR = 0x00; //0 << INTF5;
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
	
	fnd_init();
    while (1) 
    {
		fnd_digit(0000);
    }
}

