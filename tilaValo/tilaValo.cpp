/*19.4-21 klo.12.00 Heikki Pätssi ja Aleksi Vilppola.
  tilavalot punainen ja vihreä*/

#include "tilaValo.h"
#include <Arduino.h>

  int vihrea = 2;
  int punainen = 4;

  void vihreaLedBLINK()
  {
    pinMode(vihrea, OUTPUT);
    digitalWrite(vihrea, HIGH);
    delay(10);
    
    digitalWrite(vihrea, LOW);
    delay(3000);

  }

  void punainenLedBLINK()
  {
    pinMode(punainen, OUTPUT);
    digitalWrite(punainen, HIGH);
    delay(10);
   
    digitalWrite(punainen, LOW);
    delay(1000);
  }
