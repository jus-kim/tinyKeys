/**
 * \copyright  Copyright 2023 juskim. All rights reserved.
 *             The code for this project follow the Apache 2.0 license and details 
 *             are provided in the LICENSE file located in the root folder of this 
 *             project. Details of SOUP used in this project can also be found in 
 *             the SOUP file located in the root folder.
 * 
 * @file       tinyKeys.ino
 * @author     juskim (GitHub: jus-kim, YouTube: @juskim)
 * @date       Jan 14, 2023
 * @brief      Main file for tinyKeys.
 */

#include <Arduino.h>
#include "global_params.h"
#include "keys_lib.h"


static volatile uint16_t t_counter_ms = 0;
static keys_lib m_keys_lib;


void setup()
{
  // Initialize serial and CLI library
  Serial.begin(9600);

  // Initialize keyboard library
  Keyboard.begin();
  m_keys_lib.init(T_TASK_LOOP_MS);

  // Initialize interrupt timer for 1 ms
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);
}


void loop()
{
  // Complete all keyboard related periodic tasks
  m_keys_lib.run_tasks();

  // Wait until next period interation to complete tasks
  while(t_counter_ms < T_TASK_LOOP_MS);
  t_counter_ms = 0;
}


SIGNAL(TIMER0_COMPA_vect)
{
  t_counter_ms++;
}


// Compilation error checks
#if (T_TASK_LOOP_MS < 0) || (T_TASK_LOOP_MS > 65535)
    #error "T_TASK_LOOP_MS must be between 0 to 65535 ms..."
#endif
