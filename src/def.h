/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 expandtab : */

/* 
 * Project definitions
 *
 * @2021 CT1ENQ - José Miguel Fonte
 *
 */

#ifndef _DEF_H
#define _DEF_H

//-----------------------------------------------------------------------------
// NULL definition 
//-----------------------------------------------------------------------------

#ifndef NULL
#define NULL ((void *) 0)
#endif

//-----------------------------------------------------------------------------
// BOOLEAN definitions
//-----------------------------------------------------------------------------

#define TRUE  1
#define FALSE 0

//-----------------------------------------------------------------------------
// Oscillator frequency in Hz
//-----------------------------------------------------------------------------

#define OSC_FREQ  (4000000UL)

//-----------------------------------------------------------------------------
// Oscillator cycles per instruction
//-----------------------------------------------------------------------------

#define OSC_PER_INST (12)

//-----------------------------------------------------------------------------

#endif
