/*
 * ExUartRxInterrupt.c
 *
 * Created: 2020-10-27 오후 1:24:14
 * Author : IT학교
 */ 

/*
	uart rx interrupt 처리
	9600bps, data-8bit, stop 1bit, no parity
*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BUF_SIZE 1024

char rxbuf[BUF_SIZE];
int rx_index = 0;

ISR(USART0_RX_vect)
{
	unsigned char buf_recv;
	buf_recv = UDR0;
	rxbuf[rx_index++] = buf_recv;
	
	if(rx_index > BUF_SIZE-1){
		rx_index = 0;
	}
	rxbuf[rx_index] = '\0';
}

uart0_sendString(unsigned char str[])
{
	int i = 0;
	while(str[i] != '\0'){
		uart0_transmit(str[i]);
		++i;
	}
}

void uart0_transmit(unsigned char data)
{
	while(!(UCSR0A & (1<<UDRE0)))
	{
		;
	}
	UDR0 = data;
}

void uart0_init()
{
	UDR0 = 0x00;
	UCSR0A = 0x00;
	UCSR0B = (1<<RXCIE0)|(1<<RXEN0)|(1<<TXEN0);	
	UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
	UBRR0H = 0;
	UBRR0L = 103;
}

void uart0_flush()
{
	rx_index = 0;
	rxbuf[rx_index] = '\0';
}

int main(void)
{
    uart0_init();
	sei();
    while (1) 
    {
		_delay_ms(1000);
		uart0_sendString(rxbuf);
		uart0_flush();
		uart0_transmit('\r');
		uart0_transmit('\n');
    }
}

