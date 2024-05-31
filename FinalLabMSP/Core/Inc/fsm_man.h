/*
 * fsm_man.h
 *
 *  Created on: May 28, 2024
 *      Author: DELL
 */

#ifndef INC_FSM_MAN_H_
#define INC_FSM_MAN_H_

#include "stm32f1xx_hal.h"

#define LED_RED_Port GPIOA
#define LED_RED_Pin GPIO_PIN_8

void wrapAroundCounter();
void fsm_man_run();

#endif /* INC_FSM_MAN_H_ */
