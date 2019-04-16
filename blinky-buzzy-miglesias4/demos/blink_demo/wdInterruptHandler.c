#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  int i=0;
  int count = 5;
  if (++blink_count == 125) {
    P1OUT |= BIT0 + BIT6; //on leds
    if(count != 0){
      P1OUT ^= BIT0 + BIT6;
      __delay_cycles(200000);
    }
    count -= 1;
    state_advance();
    blink_count = 0;
  }
}
