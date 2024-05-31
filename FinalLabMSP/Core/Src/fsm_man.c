#include "fsm_man.h"
#include "software_timer.h"
#include "control_led.h"
#include "button.h"
int counter = 0;


void wrapAroundCounter(){
	if (counter > 9) counter=0;
	if (counter < 0) counter=9;
}

void fsm_man_run() {
	  if(timer0_flag == 1) {
		  setTimer0(100);
		  display7SEG(counter);
		  counter++;
		  if(counter>=10) {
			  counter = 0;
		  }

	  }
	  if(is_button_pressed(0) == 1 || is_long_button_flag(0) == 1) {
		  counter = 0;
	  }
	  if(is_button_pressed(1) == 1 || is_long_button_flag(1) == 1) {
		  wrapAroundCounter(++counter);
	  }
	  if(is_button_pressed(2) == 1 || is_long_button_flag(2) == 1) {
		  wrapAroundCounter(--counter);
	  }
}
