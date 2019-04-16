#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "libTimer.h"
#include "buzzer.h"
#include "state_machine.h"

char switch_state_down, switch_state_changed;
char speed;
short note;


static char switch_update_interrupt_sense(){
  char p2 = P2IN;
  P2IES |= (p2 & SWITCHES); //if switch up, sense down
  P2IES &= (p2 | ~SWITCHES); //if switch down, sense up
  return p2;
}

void switch_init(){ 
  //buzzer_set_period(0);
  //switch_state_changed = 1;
  P2REN |= SWITCHES; //Resistor
  P2IE = SWITCHES; //Interrrupts
  P2OUT |= SWITCHES; //Push up 
  P2DIR &= ~SWITCHES; //Sets bits
  switch_update_interrupt_sense();
  switch1_interrupt_handler();
  led_update();
}

void switch1_interrupt_handler(){
  char p2 = switch_update_interrupt_sense();

  char b1 = (p2 & SW1) ? 0:1;
  char b2 = (p2 & SW2) ? 0:1;
  char b3 = (p2 & SW3) ? 0:1;
  char b4 = (p2 & SW4) ? 0:1;

  if(b1){
    note = 11111;
    switch_state_down = b1;
    speed = 40;
    led_update();
  }

  if(b2){
    note = 10000;
    speed = 26;
    switch_state_down = b2;
    led_update();
  }

  if(b3){
    note = 1010;
    speed = 30;
    switch_state_down = b3;
    led_update();

  }

  if(b4){
    note = 1111;
    speed = 10;
    switch_state_down = b4;
    led_update();
  }

  // switch(switch_state_down){
  //   case 0:
  //     //Does Nothing since button is up
  //   case 1:
  //     perform_switch1();
  //     break;
  // }

  // switch(switch2_state_down){
  //   case 0:
  //     //Does Nothing since button is up
  //   case 1:
  //     perform_switch2();
  //     break;
  // }

  // switch(switch3_state_down){
  //   case 0:
  //     //Does Nothing since button is up
  //   case 1:
  //     perform_switch3();
  //     break;
  // }

  // switch(switch4_state_down){
  //   case 0:
  //     //Does Nothing since button is up
  //   case 1:
  //     perform_switch4();
  //     break;
  // }
}

// void perform_switch1(){
//   switch_state_changed = 1;
//   led_blinky = 0;
//   if(light == 2){
//     light = 3;
//     switch_state_changed = 1;
//     led_update();
//   }
//   else{
//     light = 2;
//   }
//   led_update();
//   buzzer_set_period(2000);

// }

// void perform_switch2(){
//   switch_state_changed = 1;
//   led_blinky = 0;
//   if(light == 1){
//     light = 3;
//     switch_state_changed = 1;
//     led_update();
//   }
//   else{
//     light = 1;
//   }
//   led_update();
//   buzzer_set_period(2700);
// }


// void perform_switch3(){
//   switch_state_changed = 1;
//   led_blinky = 0;
//   if(light == 0){
//     light = 3;
//     switch_state_changed = 1;
//     led_update();
//   }
//   else{
//     light = 0;
//   }
//   led_update();
//   buzzer_set_period(2500);
// }

// void perform_switch4(){
//   switch_state_changed = 1;
//   led_blinky = 0;
//   led_update();
//   buzzer_set_period(2000);

  
// }


