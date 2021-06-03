/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 expandtab : */

/*
 * HARDWARE TIMER 0
 *
 * NOTES:
 *
 * @2021 CT1ENQ - José Miguel Fonte
 */


#ifndef _HW_TIMER0_H
#define _HW_TIMER0_H

void timer0_init(void);

void delay_ms(unsigned int n);        //delay in milli seconds
void delay_minutes(unsigned int n);   //delay in milli seconds

#endif /* HW_TIMER0_H */
