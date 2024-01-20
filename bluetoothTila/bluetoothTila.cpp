/*1.4-21 klo.20.15 Aki Kuivas. ohjelma lukee serialilta viestin jonka on
olatava C (067)ja palauttaa true arvon kerran, muutoin ei anna mitään*/

#include "bluetoothTila.h"
#include <Arduino.h>

char bluetoothTila()
{  
  char data;
  data = '0'; 
                            
  if (Serial.available() > 0)
  {
  data = Serial.read(); 
  }
  return data;
}
