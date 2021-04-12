/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 expandtab : */

#include "def.h"
#include "morse_macros.h"
#include <mcs51/at89x051.h>

/* Using 4 MHz XTAL
 *
 * 4 MHz / 12 cycles/op = 0,333 MIPS => 3 us/instruction
 *
 * 333 * 3us = 999 uS = 1ms (333 = 0x1D4 =~ 0xFFFF - 0x01D4 = 0xFEB2)
 *
 * This is the time count for 1 state 
 */

/* MACROS */

#define WPM_BASE_TIME 50

/* Function prototypes */

void id_morse(void);
void dot_duration(unsigned int n_times);
void intra_duration_char(void);
void intra_duration_chars(void);
void intra_duration_words(void);
void dih(void);
void dah(void);
void delay(unsigned int n);   //delay in milli seconds
void delay_minutes(unsigned int n);   //delay in milli seconds
void timer_init(void);


/* Global variables */

volatile int d_l; //delay latch
volatile unsigned int dot_duration_ms;

/*****************************************************************************/

void main() {

  dot_duration_ms = WPM_BASE_TIME;

  P1_0 = 0x00;

  EA  = 1; // Enable all interrupts
  //EX0 = 1; // Enable int0
  //EX1 = 1; // Enable int1

  //IT0 = 1; // Edge triggered 
  //IT1 = 1; // Edge triggered

  timer_init();

  while(1) {
    id_morse();

    delay_minutes(10);

    while (P3_2 != 1) {
    
    }
  }
}

/*****************************************************************************/

void id_morse(void) {
 ___
 _D _ _E
 ___
 _C _ _Q _ _0 _ _U _ _G _ _M _ _R

 if (P1_6 == 0) {
  ___
  _I _ _N _ _5 _ _1 _ _U _ _K
  ___ 
 }
}


void dot_duration(unsigned int n_times) {
   int n;

   if (!n_times) {
      n = 1;
   } else {
      n = n_times;
   }

   delay(dot_duration_ms * n);
}

void intra_duration_char(void) {
   dot_duration(1);   
}

void intra_duration_chars(void) {
   dot_duration(3);  
}

void intra_duration_words(void) {
   dot_duration(7);   
}

void dih(void) {
   P1_0 = 1;
   dot_duration(1);
   P1_0 = 0;
}

void dah(void) {
   P1_0 = 1;
   dot_duration(3);
   P1_0 = 0;
}

void delay_minutes(unsigned int n) {
  int i;
  for (i = 0; i <= n - 1; i++) {
    delay(60000);
  }
}

void delay(unsigned int n) {
   int i;
   for(i=0;i<=n-1;i++)   //interrupt 1KHz =1ms till your count is over. 1000 = 1000ms so 1000 interrupts should occur
   {
      d_l=1; //enable latch to lock till 1ms happens
      TH0=0xFE;  //Set the Preset value here before every timer 0 runs to get exact 1KHz interrupt
      TL0=0xB2;
      TR0=1;   // Run timer 0
      while(d_l>0); //1KHz interrupt occured so move ahead
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
  if (dot_duration_ms > 5) {
    dot_duration_ms -= 1;  
  }
}

void external_int_1 (void) __interrupt 2 __using 0 {
  if (dot_duration_ms < 250) {
    dot_duration_ms += 1;  
  }
}

