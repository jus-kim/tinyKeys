/**
 * \copyright  Copyright 2023 juskim. All rights reserved.
 *             The code for this project follow the Apache 2.0 license and details 
 *             are provided in the LICENSE file located in the root folder of this 
 *             project. Details of SOUP used in this project can also be found in 
 *             the SOUP file located in the root folder.
 * 
 * @file       global_params.h
 * @author     juskim (GitHub: jus-kim, YouTube: @juskim)
 * @brief      Header file with global parameters.
 */

#ifndef __GLOBAL_PARAMS_H
#define __GLOBAL_PARAMS_H


#define T_TASK_LOOP_MS              10  // Super loop period in [ms]
#define KEY_NULL                    0x00
#define KEY_FN                      0x01

#define FLAG_KEYBOARD_SELECTION     KEY_PRO_ID_40_PERCENT

// NOTE: Add new flag ID for any additional keyboard layout profiles
#define KEY_PRO_ID_TESTPAD          0 
#define KEY_PRO_ID_40_PERCENT       1

#if FLAG_KEYBOARD_SELECTION == KEY_PRO_ID_TESTPAD
#include "keys_profile_testpad.h"
#elif FLAG_KEYBOARD_SELECTION == KEY_PRO_ID_40_PERCENT
#include "keys_profile_40percent.h"
#endif


#endif  // __GLOBAL_PARAMS_H
