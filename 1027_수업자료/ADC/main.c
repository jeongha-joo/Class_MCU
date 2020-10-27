/*
 * ExADC_VR.c
 *
 * Created: 2020-10-27 오후 3:31:39
 * Author : IT학교
 */ 
/*
#include <avr/io.h>
#include <util/delay.h>
#include "myUtil.h"

void adc_init()
{
	ADMUX = (1<<REFS1) | (1<<REFS0) | (6<<MUX0);
	ADCSRA = (1<<ADEN) | (7<<ADPS0) | (1<<ADFR);
	ADCW = 0x00;
}
int main(void)
{
	int adc_data = 0;
	fnd_init();
	adc_init();
	
	ADCSRA |= (1<<ADSC);
	
	while(1)
	{
		while(!(ADCSRA && (1<<ADIF)));
		adc_data = (int)ADCW;
		fnd_displayAll(adc_data);
	}
}
*/