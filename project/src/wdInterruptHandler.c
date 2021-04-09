#include <msp430.h>
#include "stateMachines.h"

char stateSwitch;

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */

  switch(stateSwitch){
  case 1:
    toggle_leds();
    break;
  default:
    break;

  }
}


