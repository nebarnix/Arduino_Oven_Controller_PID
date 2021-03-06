/*
  Control_TC_Serial
  
  Sets temperature ramp based on serial inputs.  At the very
  least, it should take 2 arguments (setpoint and slope), and
  change the temperature.

  Based on PID Relay example and TC Shield examples.
  PID Relay example is weakly commented.  Analog example
  is much better.  Minimum time is ok?
  
  // How long before integral is flushed?
  // I guess it's the "Window Size" parameter -- 5000 millis.
  
  This work is licensed under a Creative Commons Attribution-ShareAlike 3.0 Unported License.
  http://creativecommons.org/licenses/by-sa/3.0/
*/

#include "parameters.h"

void setup() {
  Serial.begin(38400);
  Serial.println("M0 Sx.x Rx.x to ramp-to-hold");
  Serial.println("M1 Sx.x to jump");
  Serial.println("M2 Sx.x Rx.x to ramp-to-kill");
  Serial.println("M3 Pause PID and Hold power");
  Serial.println("M4 Resume PID");
  TC_Relay_Init();
}

void loop() {
  get_and_do_command();
  TC_Relay_Loop();
}

