/*
 * myUtil.h
 *
 * Created: 2020-10-27 오후 3:32:30
 *  Author: IT학교
 */ 
#ifndef MYUTIL_H_
#define MYUTIL_H_


#include <avr/io.h>
#include <util/delay.h>

void fnd_init(void);
void fnd_data(int data);
void fnd_display(int index, int data);
void fnd_displayAll(int data);

#endif