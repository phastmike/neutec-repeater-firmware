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

/* PORT 1
 * P1_0 and P1_1 may need external pull up
 *
 */

#define HWIO_OUT_MORSE	  P1_1
#define HWIO_IN_TONE      P1_3
#define HWIO_IN_PTT       P1_4
#define HWIO_OUT_ISD_PLAY	P1_5
#define HWIO_OUT_ID_PTT  	P1_6

/*
 * PORT 3 
 *
 */

#define HWIO_OUT_LED      P3_0
#define HWIO_IN_ID_MORSE  P3_4
#define HWIO_IN_ID_VOICE  P3_5
#define HWIO_IN_ISD_TYPE  P3_7

/*
 *
 */

void hwio_init(void);

#endif
