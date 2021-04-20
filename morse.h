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

#ifndef _MORSE_H
#define _MORSE_H

#include "morse_macros.h"

#define WPM_BASE_TIME 50

void morse_init(void);
void morse_wpm_decrease();
void morse_wpm_increase();

void intra_duration_char(void);
void intra_duration_chars(void);
void intra_duration_words(void);

void dih(void);
void dah(void);

#endif /* _MORSE_H */
