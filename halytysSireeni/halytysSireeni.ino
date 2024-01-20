/*31.3-21 klo.11.30 Aki Kuivas. pääohjelma
toistaa kerran äänen ja ledit kun painaa bluethoot nappia*/

#include "halytysSireeni.h" //joka ohjelmassa sisällytetään vain .h 
                           //header tiedosto jossa on märitykset
void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  halytysSireeni();
  delay(250);
}
