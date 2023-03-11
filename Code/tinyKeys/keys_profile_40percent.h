/**
 * \copyright  Copyright 2023 juskim. All rights reserved.
 *             The code for this project follow the Apache 2.0 license and details 
 *             are provided in the LICENSE file located in the root folder of this 
 *             project. Details of SOUP used in this project can also be found in 
 *             the SOUP file located in the root folder.
 * 
 * @file       keys_profile_40percent.h
 * @author     juskim (GitHub: jus-kim, YouTube: @juskim)
 * @brief      Keyboard profile for 40 percent layout.
 */

// NOTE: Check out below link for the list of all special key character values
// https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/

#ifndef __KEYS_PROFILE_40PERCENT_H
#define __KEYS_PROFILE_40PERCENT_H

#include <Arduino.h>
#include <Keyboard.h>


// Total number of columns and rows for our matrix circuit
#define KEY_COL_TOTAL   11
#define KEY_ROW_TOTAL   4
// Keyboard matrix GPIO pins for columns
#define KEY_COL_PIN_0   2
#define KEY_COL_PIN_1   3
#define KEY_COL_PIN_2   4
#define KEY_COL_PIN_3   5
#define KEY_COL_PIN_4   6
#define KEY_COL_PIN_5   7
#define KEY_COL_PIN_6   8
#define KEY_COL_PIN_7   9
#define KEY_COL_PIN_8   10
#define KEY_COL_PIN_9   11
#define KEY_COL_PIN_10  12
// Keyboard matrix GPIO pins for rows
#define KEY_ROW_PIN_0   A0
#define KEY_ROW_PIN_1   A1
#define KEY_ROW_PIN_2   A2
#define KEY_ROW_PIN_3   A3


class keys_profile_40percent
{
  public:
    const uint8_t total_col =  KEY_COL_TOTAL;
    const uint8_t total_row = KEY_ROW_TOTAL;
    const uint8_t gpio_col[KEY_COL_TOTAL] = 
      { KEY_COL_PIN_0, KEY_COL_PIN_1, KEY_COL_PIN_2, KEY_COL_PIN_3, KEY_COL_PIN_4, 
        KEY_COL_PIN_5, KEY_COL_PIN_6, KEY_COL_PIN_7, KEY_COL_PIN_8, KEY_COL_PIN_9, 
        KEY_COL_PIN_10 };
    const uint8_t gpio_row[KEY_ROW_TOTAL] =
      { KEY_ROW_PIN_0, KEY_ROW_PIN_1, KEY_ROW_PIN_2, KEY_ROW_PIN_3 };
    uint8_t key_matrix[KEY_ROW_TOTAL][KEY_COL_TOTAL] =
      { { KEY_ESC, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p' }, 
        { KEY_TAB, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';' },
        { KEY_LEFT_SHIFT, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/' }, 
        { KEY_LEFT_CTRL, KEY_LEFT_GUI, KEY_LEFT_ALT, ' ', ' ', KEY_RIGHT_ALT, KEY_RIGHT_CTRL, KEY_RIGHT_SHIFT, KEY_RETURN, KEY_BACKSPACE } };
};


#endif  // __KEYS_PROFILE_40PERCENT_H
