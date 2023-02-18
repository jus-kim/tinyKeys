/**
 * \copyright  Copyright 2023 juskim. All rights reserved.
 *             The code for this project follow the Apache 2.0 license and details 
 *             are provided in the LICENSE file located in the root folder of this 
 *             project. Details of SOUP used in this project can also be found in 
 *             the SOUP file located in the root folder.
 * 
 * @file       keys_profile_testpad.h
 * @author     juskim (GitHub: jus-kim, YouTube: @juskim)
 * @date       Jan 14, 2023
 * @brief      Generic keyboard library.
 */

// NOTE: Check out below link for the list of all special key character values
// https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/

#ifndef __KEYS_PROFILE_TESTPAD_H
#define __KEYS_PROFILE_TESTPAD_H

#include <Arduino.h>
#include <Keyboard.h>


// Total number of columns and rows for our matrix circuit
#define KEY_COL_TOTAL   3
#define KEY_ROW_TOTAL   3
// Keyboard matrix GPIO pins for columns
#define KEY_COL_PIN_0   A0
#define KEY_COL_PIN_1   A1
#define KEY_COL_PIN_2   A2
// Keyboard matrix GPIO pins for rows
#define KEY_ROW_PIN_0   A3
#define KEY_ROW_PIN_1   A4
#define KEY_ROW_PIN_2   A5


class keys_profile_testpad
{
  public:
    const uint8_t total_col =  KEY_COL_TOTAL;
    const uint8_t total_row = KEY_ROW_TOTAL;
    const uint8_t gpio_col[KEY_COL_TOTAL] = 
      { KEY_COL_PIN_0, KEY_COL_PIN_1, KEY_COL_PIN_2 };
    const uint8_t gpio_row[KEY_ROW_TOTAL] =
      { KEY_ROW_PIN_0, KEY_ROW_PIN_1, KEY_ROW_PIN_2 };
    uint8_t key_matrix[KEY_ROW_TOTAL][KEY_COL_TOTAL] =
      { {'7', '8', '9'}, 
        {'4', '5', '6'},
        {'1', '2', '3'} };
};


#endif  // __KEYS_PROFILE_TESTPAD_H
