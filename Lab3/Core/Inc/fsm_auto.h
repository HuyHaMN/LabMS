/*
 * fsm_auto.h
 *
 *  Created on: Mar 22, 2024
 *      Author: DELL
 */

#ifndef INC_FSM_AUTO_H_
#define INC_FSM_AUTO_H_

#define INIT 		1
#define RED_GREEN 	2
#define RED_YELLOW 	3
#define GREEN_RED	4
#define	YELLOW_RED 	5

#include "global.h"

void fsm_auto_run();
void handle7SEG();

#endif /* INC_FSM_AUTO_H_ */
