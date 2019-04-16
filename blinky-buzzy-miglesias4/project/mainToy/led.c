#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "libTimer.h"
#include "buzzer.h"
#include "state_machine.h"

//char switch_state_changed;
//char switch_state_down;
unsigned char red_on = 0, green_on = 0;
unsigned char leds_changed = 0;
char speed;

static char redVal[] = {0,LED_RED}, greenVal[] = {0,LED_GREEN};

void led_init(){
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

// void buzzer_init(){
//   timerAUpmode();
//   P2SEL2 &= ~(BIT6 | BIT7);
//   P2SEL &= ~BIT7;
//   P2SEL |= BIT6;
//   P2DIR = BIT6;
// }

// void buzzer_set_period(short cycles){
//   CCR0 = cycles;
//   CCR1 = cycles >> 1;
// }

void led_update(){
  if(switch_state_changed == 1){
    char ledFlags = 0;
    if(speed > 1){
      ledFlags = redVal[red_on] | greenVal[green_on];
      P1OUT &= (0xff^LEDS) | ledFlags;
      P1OUT |= ledFlags;
      leds_changed = 0;
    }
    else{
      speed = 0;
      //leds_changed = 0;
    }
    buzzer_set_period(note);
  }
  // if (switch_state_changed) {
  //   char ledFlags = 0; /* by default, no LEDs on */

  //   switch(light){
  //   case 0:
  //     ledFlags = 0;
  //     ledFlags |= LED_RED;
  //     break;
  //   case 1:
  //     ledFlags = 0;
  //     ledFlags |= LED_GREEN;
  //     break;
  //   case 2:
  //     if(led_blinky)
  //     break;
  //     ledFlags = 0;
  //     ledFlags |= LED_RED | LED_GREEN;
  //     break;
  //     default:
  // ledFlags = 0;
  //     light = 2;
  // break;
  //   }
  //   //ledFlags |= switch_state_down ? LED_GREEN : 0;
  //   //ledFlags |= switch_state_down ? 0 : LED_RED;

  //   P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
  //   P1OUT |= ledFlags;         // set bits for on leds
  // }
  // switch_state_changed = 0;
}

// void led_toggle(){
//   light -= 1;
//   switch_state_changed = 1; //Toggles the led switch
// }
