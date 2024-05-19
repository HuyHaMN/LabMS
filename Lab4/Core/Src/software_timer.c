/*
 * software_timer.c
 *
 *  Created on: Nov 24, 2023
 *      Author: thao2
 */


#include "software_timer.h"

// timer for main system
int timer0_counter = 0;
int timer0_flag = 0;

void setTimer0(int duration){
	timer0_counter = duration;
	timer0_flag = 0;
}
void timerRunTIM2(){
	if (timer0_counter > 0){
		timer0_counter--;
		if (timer0_counter <= 0){
			timer0_flag = 1;
		}
	}
}
void Timer_init(){
	setTimer0(50);
}
