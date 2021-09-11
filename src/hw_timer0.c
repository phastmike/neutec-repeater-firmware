/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 expandtab : */

/*
 * HARDWARE TIMER 0
 *
 * NOTES:
 *
 * @2021 CT1ENQ - José Miguel Fonte
 */

#include <mcs51/at89x051.h>

//-----------------------------------------------------------------------------
// Oscillator frequency in Hz
//-----------------------------------------------------------------------------

#define OSC_FREQ  (24000000UL)

//-----------------------------------------------------------------------------
// Oscillator cycles per instruction
//-----------------------------------------------------------------------------

#define OSC_PER_INST (12)

//-----------------------------------------------------------------------------

#define PRELOAD01  (65536 - (unsigned int) (OSC_FREQ / (OSC_PER_INST * 1020)))
#define PRELOAD01H (PRELOAD01 / 256)
#define PRELOAD01L (PRELOAD01 % 256)

volatile int d_l; //delay latch


void timer0_init(void) {
   TMOD=0X01; // Timer 0 select, 16 bit mode
   ET0=1;     // Enable Timer 0 Interrupt
   PT0=1;     // High priority for timer 0
}

void delay_ms(unsigned int n) {
   int i;

   for(i = 0 ; i <= n-1 ; i++) {  //interrupt 1KHz =1ms till your count is over. 1000 = 1000ms so 1000 interrupts should occur
      d_l=1;                      //enable latch to lock till 1ms happens
      TH0= PRELOAD01H;            //Set the Preset value here before every timer 0 runs to get exact 1KHz interrupt
      TL0= PRELOAD01L;
      TF0= 0;                     // needed?
      TR0= 1;                     // Run timer 0
      //while(d_l>0);               //1KHz interrupt occured so move ahead
      while(!TF0);
      TR0=0;   // Stop timer 0
   }
}

void delay_minutes(unsigned int n) {
  int i;

  for (i = 0; i <= n - 1; i++) {
    delay_ms(60000);
  }
}


//timer 0 interrupt routine
void timer_0 (void) __interrupt 1 __using 0 {  
   d_l=0;
}
