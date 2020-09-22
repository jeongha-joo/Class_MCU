/*
 * ExInterrupt2.c
 *
 * Created: 2020-09-22 오후 1:29:25
 * Author : IT학교
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int ledFlag = 0;

ISR(INT4_vect){
	cli();		// 인터럽트 처리 동안 다른 인터럽트 차단.
				// 전역 인터럽트 clear
	ledFlag = !ledFlag;
	
	sei();		// 인터럽트 다시 받을 수 있게 설정
				// 전역 인터럽트 set
}

void led_init(){
	DDRC = 0xff;	// LED 연결된 OUTPUT 설정
	PORTC = 0xff;	// LED OFF
}
void exInterrupt_int()
{
	led_init();
	//int(PE4) 입력 설정
	DDRE = (0<<PE5);	
	EIMSK = (1<< INT4);
	// int4 검출신호 설정(상승)
	EICRB = (1<<ISC41) | (1 << ISC40);
	EIFR = 0x00;
}

int main(void)
{
	unsigned char ledData = 1;
	exInterrupt_int();
	//전역에 대한 인터럽트 ENABLE
	sei();
    while (1) 
    {
		if(ledFlag){
			for(int i = 0; i < 8; i++){
				ledData = 1<< i;
				PORTC = ~ledData;	
				_delay_ms(200);
			}
    }else{
		PORTC = 0xff;
		_delay_ms(200);
	}
}
}

