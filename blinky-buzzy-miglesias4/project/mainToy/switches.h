#ifndef switches_included
#define switches_included

#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1 | SW2 | SW3 | SW4)
//#include <msp430.h>

//unsigned int switches_read();
void switch_init(); //initialize switch
void switch1_interrupt_handler();


extern char switch_state_down, switch_state_changed;
extern short note;

#endif //included