/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 expandtab : */

/*
 * MORSE Functions 
 * Depends on hw_io.h for port definitions
 * 
 * Could improve by removing hw_io.c dependency
 *
 * José Miguel Fonte @2021
 */

#include "hw_io.h"

#define WPM_BASE_TIME 50

volatile unsigned int dot_duration_ms;

/* Ugly */
extern void delay(unsigned int n);  // Defined in main.c

void dot_duration(unsigned int n_times);


void morse_init(void) {
  dot_duration_ms = WPM_BASE_TIME;
}

void morse_wpm_decrease() {
  if (dot_duration_ms > 5) {
    dot_duration_ms -= 1;  
  }
}

void morse_wpm_increase() {
  if (dot_duration_ms < 250) {
    dot_duration_ms += 1;  
  }
}

void dot_duration(unsigned int n_times) {
   int n;

   if (!n_times) {
      n = 1;
   } else {
      n = n_times;
   }

   delay((dot_duration_ms * n));
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
   OUT_MORSE = 1;
   dot_duration(1);
   OUT_MORSE = 0;
}

void dah(void) {
   OUT_MORSE = 1;
   dot_duration(3);
   OUT_MORSE = 0;
}

