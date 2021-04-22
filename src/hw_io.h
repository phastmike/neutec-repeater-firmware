/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 expandtab : */

/*
 * HARDWARE IO
 *
 * Renaming IO ports for abstraction
 *
 * NOTES:
 * P1_0 an P1_1 need external pull-ups (10k) if used as normal GPIO
 *
 *
 * @2021 CT1ENQ - José Miguel Fonte
 */

#ifndef _HW_IO_H
#define _HW_IO_H

#include <mcs51/at89x051.h>

/* PORT 1 */

#define IN_PTT            P1_0 /* May need pull up */
#define OUT_MORSE				  P1_1 /* May need pull up */
#define OUT_ID_INHIBIT    P1_2
#define OUT_ToT_PTT			  P1_6
#define OUT_VOICE_TRIGGER	P1_5
#define IN_MORSE_LENGTH   P1_7 /* 1: Call + Locator, 0: Call */

/* PORT 3 */

#define IN_ID_TYPE			  P3_5
#define IN_ID_TRIGGER		  P3_7

#endif
