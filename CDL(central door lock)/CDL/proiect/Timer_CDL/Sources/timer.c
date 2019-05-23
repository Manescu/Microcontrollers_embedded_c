/*
 * timer.c
 *
 *  Created on: Apr 13, 2019
 *      Author: Stud
 */
#include "timer.h"
#include "mc9s08aw60.h"
void Timer_Init()
{
	TPM1SC = 0x0B; //Timer 1 intrerupts enabled
	TPM1MOD = TIMER_20MS_VALUE;
	
	//TPM1C0SC = 0x0010;
	//TPM1C0V = TIMER_10MS_VALUE;
}
