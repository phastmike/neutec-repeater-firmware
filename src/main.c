/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 expandtab : */

/* Using 4 MHz XTAL
 *
 * 4 MHz / 12 cycles/op = 0,333 MIPS => 3 us/instruction
 *
 * 333 * 3us = 999 uS = 1ms (333 = 0x1D4 =~ 0xFFFF - 0x01D4 = 0xFEB2)
 *
 * This is the time count for 1 state 
 *
 * @2021 CT1ENQ - José Miguel Fonte
 */

#include "hw.h"
#include "def.h"
#include "tests.h"
#include "hw_io.h"
#include "morse.h"
#include "hw_timer0.h"
#include <mcs51/at89x051.h>

#define TEST_MODE     0
#define DEFAULT_WPM   20

/* Function prototypes */

void id_voice(void);
void id_morse(void);
void tx_repeater_id();
void io_init_defaults(void);
void wait_for_new_repeater_id(void);
void wait_until_repeater_free_to_id(void);

/* Main application entry point */

void main() {
  hwio_init();
  HW_ENABLE_ALL_INTERRUPTS;
  timer0_init();
  morse_init(DEFAULT_WPM);

  if_test_mode_run_tests();

  while(1) {
    tx_repeater_id();
    wait_for_new_repeater_id();
    wait_until_repeater_free_to_id();
  }
}

/*****************************************************************************/


void tx_repeater_id() {

  // need a loop here until we have id defined...

  if (HWIO_IN_ID_VOICE) {
    id_voice();
  } else if (HWIO_IN_ID_MORSE) {
    id_morse();
  }
}

void wait_for_new_repeater_id(void) {
  delay_ms(5000);
  //delay_minutes(1);
}

void wait_until_repeater_free_to_id(void) {
  unsigned int c = 0;
  unsigned int free_to_use = FALSE;

  while (!free_to_use) {
    for (c = 0; c <= 160; c++) {
      if (HWIO_IN_TONE == 0) {
        c = 0;
      } 
      delay_ms(50);
    }
    free_to_use = TRUE;
  } 
}

void id_voice(void) {
  // need to check waveform type

  HWIO_OUT_ISD_PLAY = 1;
  delay_ms(1000);
  HWIO_OUT_ISD_PLAY = 0;
}

void id_morse(void) {
  HWIO_OUT_ID_PTT = 0;

  ___
  _D _ _E
  ___
  _C _ _Q _ _0 _ _V _ _B _ _R _ _G
  ___ 

  /*
  _I _ _N _ _5 _ _1 _ _T _ _J
  ___
  */

  HWIO_OUT_ID_PTT = 1;
}


