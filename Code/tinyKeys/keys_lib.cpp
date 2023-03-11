/**
 * \copyright  Copyright 2023 juskim. All rights reserved.
 *             The code for this project follow the Apache 2.0 license and details 
 *             are provided in the LICENSE file located in the root folder of this 
 *             project. Details of SOUP used in this project can also be found in 
 *             the SOUP file located in the root folder.
 * 
 * @file       keys_lib.cpp
 * @author     juskim (GitHub: jus-kim, YouTube: @juskim)
 * @brief      Generic keyboard library.
 *
 * @internal
 * This is an internal implementation command.
 * @endinternal
 */
 
#include "keys_lib.h"


void keys_lib::init(uint16_t _t_period_ms)
{
  for (uint8_t i = 0; i < m_keys_profile.total_col; i++) {
    keys_lib::set_gpio(m_keys_profile.gpio_col[i], IN_HIGHZ);
  }

  for (uint8_t i = 0; i < m_keys_profile.total_row; i++) {
    pinMode(m_keys_profile.gpio_row[i], INPUT_PULLUP);
  }

  set_key_matrix_default();

  t_period_ms = _t_period_ms;
}


void keys_lib::set_gpio(uint8_t gpio_pin, uint8_t state)
{
  switch (state)
  {
    case OUT_LOW:
    {
      pinMode(gpio_pin, OUTPUT);
      digitalWrite(gpio_pin, LOW);
      break;
    }
    case IN_HIGHZ:
    {
      pinMode(gpio_pin, INPUT);
      break;
    }
    default:
      break;  // We shouldn't be here... :(
  }
}


bool keys_lib::get_gpio_input(uint8_t gpio_pin)
{
  return digitalRead(gpio_pin);
}


void keys_lib::set_key_matrix_default(void)
{
  for (uint8_t i_col = 0; i_col < m_keys_profile.total_col; i_col++)
  {
    for (uint8_t i_row = 0; i_row < m_keys_profile.total_row; i_row++) {
      key_matrix[i_row][i_col] = m_keys_profile.key_matrix[i_row][i_col];
    }
  }
}


uint8_t keys_lib::get_gpio_col(uint8_t col)
{
  return m_keys_profile.gpio_col[col];  
}


uint8_t keys_lib::get_gpio_row(uint8_t row)
{
  return m_keys_profile.gpio_row[row];
}


uint8_t keys_lib::get_key_char(uint8_t row, uint8_t col)
{
  return key_matrix[row][col];
}


void keys_lib::scan_matrix(void)
{
  for (uint8_t i_col = 0; i_col < KEY_COL_TOTAL; i_col++)
  {
    set_gpio(get_gpio_col(i_col), OUT_LOW);
    
    for (uint8_t i_row = 0; i_row < KEY_ROW_TOTAL; i_row++)
    {
      if (!get_gpio_input(get_gpio_row(i_row)))
      {
        key_states[i_row][i_col] += t_period_ms;
        if (key_states[i_row][i_col] > 65000) {
          key_states[i_row][i_col] = t_period_ms;
        }
      }
      else {
        key_states[i_row][i_col] = 0;
      }
    }

    set_gpio(get_gpio_col(i_col), IN_HIGHZ);
  }
}


void keys_lib::output_matrix(void)
{
  for (uint8_t i_col = 0; i_col < KEY_COL_TOTAL; i_col++)
  {
    for (uint8_t i_row = 0; i_row < KEY_ROW_TOTAL; i_row++)
    {
      if (key_states[i_row][i_col] >= t_period_ms) {
        Keyboard.press(get_key_char(i_row, i_col));
      }
      else {
        Keyboard.release(get_key_char(i_row, i_col));
      }
    }
  }
}


int8_t keys_lib::run_tasks(void)
{
  scan_matrix();
  output_matrix();
}

