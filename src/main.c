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
  timer0_init();
  morse_init(DEFAULT_WPM);

  //if_test_mode_run_tests();

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
  OUT_VOICE_TRIGGER = 1;
  IN_TONE_DET = 1;
  IN_VOICE_ID = 1;
  IN_MORSE_ID = 1;
}

void tx_repeater_id() {
  char did_id = 0;

  IN_VOICE_ID = 1;
  IN_MORSE_ID = 1;

  while (!did_id) {
    if (IN_VOICE_ID == 0) {
      id_voice();
      did_id = 1;
    } else if (IN_MORSE_ID == 0) {
      id_morse();
      did_id = 1;
    }
  }
}

void wait_for_new_repeater_id(void) {
  // Tune for ~= 10 minutes
  delay_minutes(9);
  delay_ms(17500);
}

/* 
 * Wait for 8 seconds (160 * 50ms) without tone detection.
 * If tone is detected, restart counting.
 * Does not take microphone ptt in consideration.
 * Sampling at 50ms.
 */

void wait_until_repeater_free_to_id(void) {
  unsigned int c = 0;
  unsigned int free_to_use = FALSE;

  while (!free_to_use) {
    for (c = 0; c <= 160; c++) {
      delay_ms(50);
      if (IN_TONE_DET == 0) {
        c = 0;
      }
    }
    free_to_use = TRUE;
  } 
}

void id_voice(void) {
  OUT_VOICE_TRIGGER = 0;
  delay_ms(1000);
  OUT_VOICE_TRIGGER = 1;
}

void id_morse(void) {
  OUT_ToT_PTT = 0;
  ___
  _D _ _E
  ___
  _C _ _Q _ _0 _ _U _ _G _ _M _ _R
  ___ 
  OUT_ToT_PTT = 1;
}


