/*
 * task.c
 *
 *  Created on: Nov 24, 2023
 *      Author: thao2
 */


#include "task.h"
#include "uart.h"
#include "global.h"
#include <stdio.h>
#include "main.h"

void task0() {
	printf("Task0 exec at: %d0ms\r\n", timer);
	HAL_GPIO_TogglePin(TASK0_GPIO_Port, TASK0_Pin);
}

void task1() {
	printf("Task1 exec at: %d0ms\r\n", timer);
	HAL_GPIO_TogglePin(TASK1_GPIO_Port, TASK1_Pin);
}

void task2() {
	printf("Task2 exec at: %d0ms\r\n", timer);
	HAL_GPIO_TogglePin(TASK2_GPIO_Port, TASK2_Pin);
}

void task3() {
	printf("Task3 exec at: %d0ms\r\n", timer);
	HAL_GPIO_TogglePin(TASK3_GPIO_Port, TASK3_Pin);
}

void task4() {
	printf("Task4 exec at: %d0ms\r\n", timer);
	HAL_GPIO_TogglePin(TASK4_GPIO_Port, TASK4_Pin);
}
