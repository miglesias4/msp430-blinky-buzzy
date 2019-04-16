#include <msp430.h>
#include "state_machine.h"
#include "buzzer.h"
#include "state_machine.h"

void
 __interrupt_vec(WDT_VECTOR)WDT(){	/* 250 interrupts/sec */
  // static char cntr = 0;
  // static int c = 0;

  // int song[] = {500,0,500,0,150,0,350,150,0,150,0,500,500,0,150,500,350,0,650}; //implementation of an array for song
  // if(++cntr >= 0){
  //   buzzer_set_period(song[c]);
  //   c++;
  //   cntr = 0;
  // }

  static char blink_count = 0;
  if(++blink_count == speed){
    buzzer_set_period(speed);
    //led_update();
    blink_count = 0;
  }
}