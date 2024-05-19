#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdio.h>
#include <stdint.h>
// typedef of sTask
typedef struct {
	// Pointer to task (must be a 'void (void)' function)
	void (*pTask)(void);
	// Delay (ticks) until the function will (next) be run
	uint32_t Delay;
	// Interval (ticks) between subsequent runs.
	uint32_t Period;
	// Incremented (by scheduler) when task is due to execute
	uint8_t RunMe;
	// This is a hint to solve the question below.
	uint32_t TaskID;
} sTask;

// define some constant
// MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCH_MAX_TASKS	40
#define NO_TASK_ID		0

#define RETURN_NORMAL 0
#define RETURN_ERROR 1
#define ERROR_SCH_TOO_MANY_TASKS 2
#define ERROR_SCH_CANNOT_DELETE_TASK 3
#define ERROR_SCH_WAITING_FOR_SLAVE_TO_ACK 4
#define ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER 5
#define ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START 6
#define ERROR_SCH_LOST_SLAVE 7
#define ERROR_SCH_CAN_BUS_ERROR 8
#define ERROR_I2C_WRITE_BYTE_AT24C64 9

// declaration variable
unsigned char Error_code_G;


// declaration function
void SCH_Init(void);
void SCH_Update(void);
uint32_t SCH_Add_Task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD);
void SCH_Dispatch_Tasks(void);
uint8_t SCH_Delete_Task(const uint8_t TASK_INDEX);
void SCH_Report_Status(void);
void Watchdog();
// extra function to help SCH_Add function
void find_new_min_index_task(void);


#endif /* INC_SCHEDULER_H_ */
