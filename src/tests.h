/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 expandtab : */

/*
 * TESTS
 * Functions for testing and debugging purposes
 *
 * Project dependencies on this functions may be removed for release versions
 *
 * @2021 CT1ENQ - José Miguel Fonte
 */

#ifndef _TESTS_H
#define _TESTS_H

#define if_test_mode_run_tests() \
if (TEST_MODE) { \
    tests_run(); \
  }

void tests_run(void);

#endif /* _TESTS_H */

