/*7.4.2021 klo.00.20 Aki Kuivas. ohjelma soittaa kaksi eritaajuista
piippausta.*/

#include "halytysSireeni.h"
#include <Arduino.h>

void halytysSireeni()
{
  int kajari = 5;
  
  tone(kajari, 800, 1000); //pinni,taajuus ja äänen pituus.
  delay (250);
  tone(kajari, 500, 1000);
}
