/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 expandtab : */

/* Using 4 MHz XTAL
 *
 * 4 MHz / 12 cycles/op = 0,333 MIPS => 3 us/instruction
 *
 * 333 * 3us = 999 uS = 1ms (333 = 0x1D4 =~ 0xFFFF - 0x01D4 = 0xFEB2)
 *
 * This is the time count for 1 state 
 */

#include "def.h"
#include "hw_io.h"
#include "morse.h"
#include <mcs51/at89x051.h>

/* Function prototypes */

void id_morse(void);
void delay(unsigned int n);   //delay in milli seconds
void delay_minutes(unsigned int n);   //delay in milli seconds
void timer_init(void);


/* Global variables */

volatile int d_l; //delay latch
//volatile unsigned int dot_duration_ms;

/*****************************************************************************/

void main() {
  OUT_ToT_PTT = 1;
  OUT_MORSE = 0;
  OUT_ID_INHIBIT = 0;
  OUT_VOICE_TRIGGER = 1;
  
  morse_init(0);

  EA  = 1; // Enable all interrupts

  //EX0 = 1; // Enable int0
  //EX1 = 1; // Enable int1

  //IT0 = 1; // Edge triggered 
  //IT1 = 1; // Edge triggered

  timer_init();

  while(1) {


  // To measure on the oscilloscope
  /*
  while (1) {
    OUT_MORSE = 0x1;
    delay(4);
    OUT_MORSE = 0x0;
    delay(4);
  }
  */

    OUT_ToT_PTT = 0;

    if (IN_ID_TYPE) {
      OUT_VOICE_TRIGGER = 0;
      delay(10000);
      OUT_VOICE_TRIGGER = 1;
    } else {
      id_morse();
    }

    OUT_ToT_PTT = 1;

    delay(2000);

    while (IN_PTT != 1) {
      if (!OUT_ID_INHIBIT) {
        OUT_ID_INHIBIT = 1;
      }
      delay(100);
    }

    OUT_ID_INHIBIT = 0;
    delay(500);

    morse_wpm_increase();
  }
}

/*****************************************************************************/

void id_morse(void) {
  ___
  _D _ _E
  ___
  _C _ _Q _ _0 _ _U _ _G _ _M _ _R

  if (IN_MORSE_LENGTH == 0) {
   ___
   _I _ _N _ _5 _ _1 _ _U _ _K
  }
  ___ 
}


void delay_minutes(unsigned int n) {
  int i;
  for (i = 0; i <= n - 1; i++) {
    delay(51500);
  }
}

#define PRELOAD01  (65536 - (unsigned int) (OSC_FREQ / (OSC_PER_INST * 1020)))
#define PRELOAD01H (PRELOAD01 / 256)
#define PRELOAD01L (PRELOAD01 % 256)


void delay(unsigned int n) {
   int i;
   for(i=0;i<=n-1;i++)   //interrupt 1KHz =1ms till your count is over. 1000 = 1000ms so 1000 interrupts should occur
   {
      d_l=1; //enable latch to lock till 1ms happens
      TH0= PRELOAD01H;  //Set the Preset value here before every timer 0 runs to get exact 1KHz interrupt
      TL0= PRELOAD01L;
      TF0= 0; // needed?
      TR0= 1;   // Run timer 0
      //while(d_l>0); //1KHz interrupt occured so move ahead
      while(!TF0);
      TR0=0;   // Stop timer 0
   }
}

void timer_init(void) {
   /////////////////////////////SET UP TO CONFIGURE DELAY///////////////////
   
   //configure timer 0 interrupt 16bit:

   // Timer 0 select, 16 bit mode
   TMOD=0X01;
   // Enable Timer 0 Interrupt
   ET0=1;
   // High priority for timer 0
   PT0=1;
   //Global Interrupts Enable
   EA=1;
}


//timer 0 interrupt routine

void timer_0 (void) __interrupt 1 __using 0 {  
   d_l=0;   //1KHz interrupt happened so disable the latch to proceed
}

void external_int_0 (void) __interrupt 0 __using 0 {
  morse_wpm_decrease();
}

void external_int_1 (void) __interrupt 2 __using 0 {
  morse_wpm_increase();
}

