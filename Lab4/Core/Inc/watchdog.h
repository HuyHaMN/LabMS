#ifndef INC_WATCHDOG_H_
#define INC_WATCHDOG_H_

extern IWDG_HandleTypeDef hiwdg;

void Watchdog_Refresh();
unsigned char Is_Watchdog_Reset(void);
void Watchdog_Counting(void);
void Reset_Watchdog_Counting(void);

#endif /* INC_WATCHDOG_H_ */
