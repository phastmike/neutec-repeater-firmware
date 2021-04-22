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
  io_init_defaults();
  HW_ENABLE_ALL_INTERRUPTS;
  timer_init();
  morse_init(DEFAULT_WPM);

  if_test_mode_run_tests();

  while(1) {
    tx_repeater_id();
    wait_for_new_repeater_id();
    wait_until_repeater_free_to_id();
  }
}

/*****************************************************************************/

void io_init_defaults(void) {
  /* P1 and P3 default as 0xFF */

  OUT_ToT_PTT = 1;
  OUT_MORSE = 0;
  OUT_ID_INHIBIT = 0;
  OUT_VOICE_TRIGGER = 1;
}

void tx_repeater_id() {
  OUT_ToT_PTT = 0;

  if (IN_ID_TYPE) {
    id_voice();
  } else {
    id_morse();
  }

  OUT_ToT_PTT = 1;
}

void wait_for_new_repeater_id(void) {
  //delay(2000);
  delay_minutes(1);
}

void wait_until_repeater_free_to_id(void) {
  if (IN_PTT != 1) {
    OUT_ID_INHIBIT = 1;

    while (IN_PTT != 1) {
      delay(100);
    }
    
    OUT_ID_INHIBIT = 0;
    delay(500);
  }
}

void id_voice(void) {
  OUT_VOICE_TRIGGER = 0;
  delay(10000);
  OUT_VOICE_TRIGGER = 1;
}

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


