#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

static unsigned int period = 4000;
static signed int rate = 200;

#define MIN_PERIOD 100
#define MAX_PERIOD 8000
void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */

    buzzer_execute_frequency();//Promotes the buzzing sound
    //buzzer_set_period(1000); /* sets the Hz */


}

void buzzer_execute_frequency(){
  period += rate;
  if((rate > 0 && (period > MAX_PERIOD))|| (rate < 0 && (period < MIN_PERIOD))){
    rate = -rate;
    period += (rate << 1);
  }
  buzzer_set_period(period);
}

void stop_buzzer(){
  buzzer_set_period(0);
}

void resume_buzzer(){
  buzzer_set_period(period);
}

void buzzer_set_period(short cycles)
{
  CCR0 = cycles; /* triggers the cycle */
  CCR1 = cycles >> 1;		/* one half cycle */
}


    
    
  

