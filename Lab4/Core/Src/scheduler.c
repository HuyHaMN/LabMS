
#include <stdio.h>
#include "global.h"
#include "scheduler.h"
#include "software_timer.h"
#include "main.h"
#include "watchdog.h"

sTask SCH_tasks_G[SCH_MAX_TASKS];
unsigned char Error_code_G = 0;

// SCH_MAX_TASK = 40
uint8_t current_index_task = 0;


// Other function help to do:
// Swap two tasks
void swapTasks(int index_a, int index_b) {
	SCH_tasks_G[index_a].pTask = SCH_tasks_G[index_b].pTask;
	SCH_tasks_G[index_a].Delay = SCH_tasks_G[index_b].Delay;
	SCH_tasks_G[index_a].Period =  SCH_tasks_G[index_b].Period;
	SCH_tasks_G[index_a].RunMe = SCH_tasks_G[index_b].RunMe;

	SCH_tasks_G[index_a].TaskID = SCH_tasks_G[index_b].TaskID;
}

// extra function
// function find the empty min index of array task
void find_new_min_index_task() {
	// find new min index of schedule array
	min_index = 0;
	min_delay = SCH_tasks_G[min_index].Delay;

	for (uint8_t i = min_index + 1; i < current_index_task; i++) {
		if (SCH_tasks_G[i].Delay < min_delay) {
			min_index = i;
			min_delay = SCH_tasks_G[i].Delay;
		}
	}
}

void SCH_Init(void){
	unsigned char i;
	// Check current to avoid error
	if (current_index_task != 0){
		for (i = 0; i < SCH_MAX_TASKS; i++){
			SCH_Delete_Task(i);
		}
	}
	// Reset the global error variable
	// SCH_Delete_Task() will generate an error code
	// (because the task array is empty)
	Error_code_G = 0;
	Timer_init();
	find_new_min_index_task();
}


void SCH_Update() {
	// Reduce Delay
	if (SCH_tasks_G[min_index].Delay > 0) SCH_tasks_G[min_index].Delay--;
	// Reset Delay and update flag RunMe
	else {
		 SCH_tasks_G[min_index].Delay =  SCH_tasks_G[min_index].Period;
		 SCH_tasks_G[min_index].RunMe += 1;
	}
}
/*
 SCH_Add_Task() causes a task (function) to be executed at regular intervals or after a user-defined delay
 */
uint32_t SCH_Add_Task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD){
	// If SCH_Init run first, then assign current_index_task to 0
	unsigned char Return_code;

	if(current_index_task < SCH_MAX_TASKS){

		SCH_tasks_G[current_index_task].pTask = pFunction;
		SCH_tasks_G[current_index_task].Delay = DELAY;
		SCH_tasks_G[current_index_task].Period =  PERIOD;
		SCH_tasks_G[current_index_task].RunMe = 0;

		SCH_tasks_G[current_index_task].TaskID = current_index_task;

		current_index_task++;

		Return_code = RETURN_NORMAL;

	} else {
		Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
		Return_code = RETURN_ERROR;
	}

	return Return_code;
}
void SCH_Dispatch_Tasks(void){
	int i = min_index;
	// check flag of min_index
	if (SCH_tasks_G[i].RunMe > 0) {
		for (uint8_t i = 0; i < current_index_task; i++) {
			if (i == min_index) {
				continue;
			}
			SCH_tasks_G[i].Delay -= min_delay;
		}
		find_new_min_index_task();
		(*SCH_tasks_G[i].pTask)();
		SCH_tasks_G[i].RunMe--;
		// If it's one-shot task, remove it form the array
		if (SCH_tasks_G[i].Period == 0) {
			SCH_Delete_Task(i);
		}
	}
	// Report system status
	SCH_Report_Status();
	// Refresh Watchdog
	Watchdog_Refresh();
}
uint8_t SCH_Delete_Task(const uint8_t TASK_INDEX){
	unsigned char Return_code;
	if (current_index_task < 0 || current_index_task >= SCH_MAX_TASKS) {
		// No task at this location...
		// Set the global error variable
		Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
		Return_code = RETURN_ERROR;
		return Return_code;
	} else {
		Return_code = RETURN_NORMAL;
	}
	// Shift all tasks from TASK_INDEX + 1 to the left
	for (uint8_t i = TASK_INDEX; i < current_index_task; i++) {
		swapTasks(i, i + 1);
	}
	// Remove last index task
	SCH_tasks_G[current_index_task].pTask = 0x0000 ;
	SCH_tasks_G[current_index_task].Delay = 0;
	SCH_tasks_G[current_index_task].Period = 0;
	SCH_tasks_G[current_index_task].RunMe = 0;
	current_index_task--;

	return Return_code;
}
void SCH_Report_Status(void){
#ifdef SCH_REPORT_ERRORS
	// ONLY APPLLIES IF WE ARE REPORTING ERRORS
	// Check for a new error code
	if (Error_code_G != Last_error_code_G){
		// Negative logic on LEDs assumed
		Error_port = 255 - Error_code_G;
		Last_error_code_G = Error_code_G;
		if (Error_code_G != 0){
			Error_tick_count_G = 60000;
		} else {
			Error_tick_count_G = 0;
		}
	} else {
		if (Error_tick_count_G != 0){
			if (--Error_tick_count == 0){
				Error_code_G = 0; // reset error code
			}
		}
	}
#endif
}
