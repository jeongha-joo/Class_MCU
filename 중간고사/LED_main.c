/*
 PORTC에 연결된 LED8개를 ON/OFF 하기
*/

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	// 입출력 방향 설정
	DDRC = 0xFF;	// 16진수로 pc7 ~ pc0 출력용 설정
	PORTC = 0x55;
	//DDRC = 0b11111111;	// 2진수로 pc7 ~ pc0 출력용 설정
    while (1) 
    {
		PORTC <<= 1 ; //0xff
		_delay_ms(500);
		
		PORTC >>= 1; //0x00
		_delay_ms(500);
    }
}

