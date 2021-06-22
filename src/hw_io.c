/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 expandtab : */

#include "hw_io.h"

void hwio_init(void) {
  /* P1 and P3 default as 0xFF */

  HWIO_OUT_MORSE = 0;
  HWIO_OUT_ID_PTT = 1;

  if (HWIO_IN_ISD_TYPE == 1) {
    HWIO_OUT_ISD_PLAY = 0;
  } else {
    HWIO_OUT_ISD_PLAY = 1;
  }
}
