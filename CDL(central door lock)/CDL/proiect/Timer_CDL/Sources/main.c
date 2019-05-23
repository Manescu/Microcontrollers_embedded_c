#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "CDL.h"
#include "timer.h"





void main(void) {
  EnableInterrupts;
  /* include your code here */
  initPort();
  Timer_Init();

  for(;;) 
  {
	  if(TPM1SC_TOF == 1)
	  {
		  loop();
		  TPM1SC_TOF = 0;
	  }

    __RESET_WATCHDOG();	/* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
