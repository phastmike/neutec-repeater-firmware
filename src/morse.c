/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 expandtab : */

/*
 * MORSE Functions 
 * Depends on hw_io.h for port definitions
 * Also Depends on external delay method/function. 
 * 
 * Could improve by removing hw_io.c dependency
 *
 * @2021 CT1ENQ - José Miguel Fonte
 */

#include "hw_io.h"
#include "morse.h"

#define DEFAULT_WPM   20  /* 24 WPM = 50ms */

unsigned int morse_wpm;
unsigned int dot_duration_ms;

/* Ugly */
extern void delay_ms(unsigned int n);  // Defined in main.c

/*
 *  Local/Private function prototypes
 */

static void dot_duration(unsigned int n_times);
static void morse_out_on(void);
static void morse_out_off(void);

/*
 *  Public function prototypes
 */

void morse_init(unsigned int wpm) {
  if (!wpm) {
    morse_wpm_set(DEFAULT_WPM);
  } else {
    morse_wpm_set(wpm);
  }
}

void morse_wpm_set(unsigned int wpm) {
  if (wpm > 0 && wpm < 100) {
    morse_wpm = wpm;
    dot_duration_ms = (1200) / (wpm);
  }
}

unsigned int morse_wpm_get(void) {
  return morse_wpm;
}

void morse_wpm_decrease() {
  if (morse_wpm > 5) {
    morse_wpm_set(morse_wpm - 1);
  }
}

void morse_wpm_increase() {
  if (morse_wpm < 250) {
    morse_wpm_set(morse_wpm + 1);
  }
}

static void dot_duration(unsigned int n_times) {
   int n;

   if (!n_times) {
      n = 1;
   } else {
      n = n_times;
   }

   delay_ms((dot_duration_ms * n));
}

static void morse_out_on(void) {
  HWIO_OUT_MORSE = 1;
}

static void morse_out_off(void) {
  HWIO_OUT_MORSE = 0;
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
  morse_out_on(); 
  dot_duration(1);
  morse_out_off(); 
}

void dah(void) {
  //morse_out_on(); 
  morse_out_on(); 
  dot_duration(3);
  morse_out_off(); 
}

