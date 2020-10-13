/*
 * Mycar.c
 *
 * Created: 2020-09-22 오후 4:47:10
 * Author : IT학교
	atmega 2560
	motor 동작
	A : DIR-PG5 : output
	: 전력공급-pe3:
 */ 
#include <avr/io.h>
#include <util/delay.h>

#define MTR_A_DIR_DDR	DDRG
#define MTR_A_SPEED_DDR DDRE
#define MTR_B_DIR_DDR	DDRH
#define MTR_B_SPEED_DDR DDRH

#define MTR_A_DIR_PORT	 PORTG
#define MTR_A_SPEED_PORT PORTE
#define MTR_B_DIR_PORT	 PORTH
#define MTR_B_SPEED_PORT PORTH

#define MTR_A_DIR_PIN	PG5
#define MTR_A_SPEED_PIN PE3
#define MTR_B_DIR_PIN	PH4
#define MTR_B_SPEED_PIN PH3

void motor_init(void){
	MTR_A_DIR_DDR |= (1<<MTR_A_DIR_PIN);
	MTR_A_SPEED_DDR |= (1<<MTR_A_SPEED_PIN);
	MTR_B_DIR_DDR |= (1<<MTR_B_DIR_PIN);
	MTR_B_SPEED_DDR |= (1<<MTR_B_SPEED_PIN);
	
	MTR_A_SPEED_PORT |= (0<<MTR_A_SPEED_PIN);
	MTR_B_SPEED_PORT |= (0<<MTR_B_SPEED_PIN);
}
// 오른쪽 바퀴
void motor_a_forward(){
	MTR_A_DIR_PORT	|= (1<<MTR_A_DIR_PIN);
	MTR_A_SPEED_PORT |= (1<<MTR_A_SPEED_PIN);
}


void motor_a_backward(){
	MTR_A_DIR_PORT &= ~(1<<MTR_A_DIR_PIN);
	MTR_A_SPEED_PORT |= (1<<MTR_A_SPEED_PIN);
}

//왼쪽 바퀴
void motor_b_forward(){
	MTR_B_DIR_PORT &= ~(1<<MTR_B_DIR_PIN);
	MTR_B_SPEED_PORT |= (1<<MTR_B_SPEED_PIN);
}

void motor_b_backward(){
	MTR_B_DIR_PORT |= (1<<MTR_B_DIR_PIN);
	MTR_B_SPEED_PORT |= (1<<MTR_B_SPEED_PIN);
}

void motor_go(){
	motor_b_forward();
	motor_a_forward();
}

void motor_right(){
	motor_a_forward();
	motor_b_backward();
}

void motor_left(){
	motor_b_forward();
	motor_a_backward();
}

void motor_stop(){
	MTR_A_SPEED_PORT &= (0<< MTR_A_SPEED_PIN);
	MTR_B_SPEED_PORT &= (0<< MTR_B_SPEED_PIN);
}


int main(void)
{
    motor_init();
	
	DDRK = 0xFF;
	PORTK = 0xFF;
		
	while (1) 
    {
		motor_right();
		_delay_ms(500);
		
		motor_stop();
		_delay_ms(2000);
		
		motor_left();
		_delay_ms(500);
		
		motor_stop();
		_delay_ms(2000);
    }
}

