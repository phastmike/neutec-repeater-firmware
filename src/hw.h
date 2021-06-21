/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 expandtab : */

/* 
 * HARDWARE MACROS 
 *
 * @2021 CT1ENQ - José Miguel Fonte
 *
 */

#ifndef _HW_H
#define _HW_H

#define HW_ENABLE_ALL_INTERRUPTS \
	EA  = 1;
#define HW_ENABLE_INT0 \
  EX0 = 1;
#define HW_ENABLE_INT1 \
  EX1 = 1;
#define HW_INT0_EDGE_TRIGGERED \
  IT0 = 1;
#define HW_INT1_EDGE_TRIGGERED \
  IT1 = 1;

#endif /* _HW_H */

