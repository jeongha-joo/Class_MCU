/*
 * ExInterrupt3.c
 *
 * Created: 2020-09-22 오후 2:46:28
 * Author : IT학교
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//unsigned int sw_flag = 0;
unsigned char ledData = 1;

ISR(INT5_vect){
	//sw_flag = !sw_flag;
	ledData = ledData << 1;
	PORTC = ~ledData;
	if(0x80 == ledData)
		ledData = 0x01;
		_delay_ms(100);
}

void led_init(){
	DDRC = 0xff;
	PORTC = 0xff;
}

void swInterrupt_init(){
	//DDRE(pe5-int5) 입력용 설정
	DDRE = (0<<PE5);
	// 외부인터럽트 int5 설정
	EIMSK = (1 << INT5);
	// 검출한 신호 설정 (low level)
	EICRB = (0 << ISC51) | (0 << ISC50);
	// 모든 외부인터럽트 발생을 초기화
	EIFR = 0x00; //0 << INTF5;
}

int main(void)
{
    led_init();
	swInterrupt_init();
	sei();		//전역 인터럽트 set
	while (1) 
    {
		;
	}
}

