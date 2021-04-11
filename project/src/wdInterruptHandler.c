#include <msp430.h>
#include "stateMachines.h"

char trackState;

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */

  switch(trackState){
  case 1:
    break;
  default:
    break;

  }
}


