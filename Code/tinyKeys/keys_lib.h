/**
 * \copyright  Copyright 2023 juskim. All rights reserved.
 *             The code for this project follow the Apache 2.0 license and details 
 *             are provided in the LICENSE file located in the root folder of this 
 *             project. Details of SOUP used in this project can also be found in 
 *             the SOUP file located in the root folder.
 * 
 * @file       keys_lib.h
 * @author     juskim (GitHub: jus-kim, YouTube: @juskim)
 * @brief      Generic keyboard library.
 */

#ifndef __KEYS_LIB_H
#define __KEYS_LIB_H

#include <Arduino.h>
#include <Keyboard.h>
#include "global_params.h"
#if FLAG_KEYBOARD_SELECTION == KEY_PRO_ID_TESTPAD
#include "keys_profile_testpad.h"
#elif FLAG_KEYBOARD_SELECTION == KEY_PRO_ID_40_PERCENT
#include "keys_profile_40percent.h"
#endif


/** Enum for GPIO states. */
enum gpio_state {
  OUT_LOW = 0,
  IN_HIGHZ
};


class keys_lib
{
  public:
    void init(uint16_t _t_period_ms);
    int8_t run_tasks(void);

  private:
    uint16_t t_period_ms;
    uint8_t key_matrix[KEY_ROW_TOTAL][KEY_COL_TOTAL];
    uint16_t key_states[KEY_ROW_TOTAL][KEY_COL_TOTAL] = { 0 };
    // NOTE: Add new keyboard layout profile below to macro
#if FLAG_KEYBOARD_SELECTION == KEY_PRO_ID_TESTPAD
    keys_profile_testpad m_keys_profile;
#elif FLAG_KEYBOARD_SELECTION == KEY_PRO_ID_40_PERCENT
    keys_profile_40percent m_keys_profile;
#endif

    void set_gpio(uint8_t gpio_pin, uint8_t state);
    void disable_entire_col(void);
    bool get_gpio_input(uint8_t gpio_pin);
    void set_key_matrix_default(void);
    uint8_t get_gpio_col(uint8_t col);
    uint8_t get_gpio_row(uint8_t row);
    uint8_t get_key_char(uint8_t row, uint8_t col);
    void scan_matrix(void);
    void output_matrix(void);
};


#endif  // __KEYS_LIB_H
