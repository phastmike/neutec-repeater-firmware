/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 expandtab : */

/*
 * TESTS
 * Functions for testing and debugging purposes
 *
 * Project dependencies on this functions may be removed for release versions
 *
 * @2021 CT1ENQ - José Miguel Fonte
 */

#include "hw.h"
#include "hw_io.h"
#include "hw_timer0.h"
#include <mcs51/at89x051.h>

/* To measure on the oscilloscope */

void test_out_morse_onoff_ms_blocking(unsigned int ms) {
  while (1) {
    HWIO_OUT_MORSE = 0x1;
    delay_ms(ms);
    HWIO_OUT_MORSE = 0x0;
    delay_ms(ms);
  }
}

void test_external_interrupts(void) {
  HW_ENABLE_INT0;
  HW_ENABLE_INT1;

  HW_INT0_EDGE_TRIGGERED;
  HW_INT1_EDGE_TRIGGERED;
}

void external_int_0 (void) __interrupt 0 __using 0 {
  morse_wpm_decrease();
}

void external_int_1 (void) __interrupt 2 __using 0 {
  morse_wpm_increase();
}


void tests_run(void) {
  //test_external_interrupts();
  test_out_morse_onoff_ms_blocking(4);
}
