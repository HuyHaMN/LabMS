/*
 * software_timer.h
 *
 *  Created on: Nov 24, 2023
 *      Author: thao2
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_


// variable
extern int timer0_counter;
extern int timer0_flag;

// function
void setTimer0(int duration);
void timerRunTIM2();
void Timer_init();


#endif /* INC_SOFTWARE_TIMER_H_ */
