/*
 * global.h
 *
 *  Created on: Mar 22, 2024
 *      Author: DELL
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"
#include "software_timer.h"
#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "fsm_auto.h"
#define INIT		1
#define RED_GREEN	2
#define RED_YELLOW	3
#define GREEN_RED	4
#define YELLOW_RED	5


#define MAN_RED 	12
#define MAN_GREEN	13
#define MAN_YELLOW	14

extern int TIME_NORMAL_RED;
extern int TIME_NORMAL_GREEN;
extern int TIME_NORMAL_YELLOW;

extern int statusLed;
extern int mode;

extern int count1 ;
extern int count2 ;

extern int countMan1;
extern int countMan2;

extern int status;

#endif /* INC_GLOBAL_H_ */

