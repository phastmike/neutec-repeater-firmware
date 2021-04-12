/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 expandtab : */

/*
 * MORSE MACROS
 * Depend on the functions within the macros!
 *
 * Syntax is simple, underscore preceeds the chars/number
 * Special chars avoid chars for readability
 *
 * Define more macros as needed.
 *
 * Already defined:
 * CHARS:
 *    A..Z (_A thru _Z)
 * NUMBERS:
 *    0..9 (_0 thru _9)
 * SPECIAL CHARS
 *    SPACE (___)
 *    QUESTION MARK (_x_)
 *
 */

#ifndef _MORSE_MACROS_H
#define _MORSE_MACROS_H

/******************************************************************************
 * MORSE CHARS
 *****************************************************************************/

#define _A \
  dih(); \
  intra_duration_char(); \
  dah();

#define _B \
  dah(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char();

#define _C \
  dah(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dih();

#define _D \
  dah(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih();

#define _E \
  dih(); 

#define _F \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dih(); \

#define _G \
  dah(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dih();

#define _H \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih();

#define _I \
  dih(); \
  intra_duration_char(); \
  dih();

#define _J \
  dih(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dah(); 

#define _K \
  dah(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dah();

#define _L \
  dih(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih();

#define _M \
  dah(); \
  intra_duration_char(); \
  dah();

#define _N \
  dah(); \
  intra_duration_char(); \
  dih();

#define _O \
  dah(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dah();

#define _P \
  dih(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dih();

#define _Q \
  dah(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dah();

#define _R \
  dih(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dih();

#define _S \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih();

#define _T \
  dah();

#define _U \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dah();

#define _V \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dah();

#define _W \
  dih(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dah();

#define _X \
  dah(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dah();

#define _Y \
  dah(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dah();

#define _Z \
  dah(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih();

/******************************************************************************
 * MORSE NUMBERS
 *****************************************************************************/

#define _1 \
  dih(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dah();

#define _2 \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dah();

#define _3 \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dah();

#define _4 \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dah();

#define _5 \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih();

#define _6 \
  dah(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih();

#define _7 \
  dah(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih();

#define _8 \
  dah(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih();

#define _9 \
  dah(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dih();

#define _0 \
  dah(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dah();

/******************************************************************************
 * SPECIAL CHARS
 *****************************************************************************/

#define _ intra_duration_chars();

/* SPACE */

#define ___ intra_duration_words(); 

/* QUESTION MARK */

#define _x_ \
  dih(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dah(); \
  intra_duration_char(); \
  dih(); \
  intra_duration_char(); \
  dih();
  

#endif
