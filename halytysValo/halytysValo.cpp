/*31.3-21 klo.11.30 Aki Kuivas. ohjelma toistaa ledit peräjälkeen*/

#include "halytysValo.h"
#include <Arduino.h>

  int led1 = 2;
  int led2 = 3;
  int led3 = 4;
  
void halytysValo() 
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  digitalWrite(led1, HIGH);
  delay(50);
  digitalWrite(led1, LOW);
  delay(50);

  digitalWrite(led2, HIGH);
  delay(50);
  digitalWrite(led2, LOW);
  delay(50);
  
  digitalWrite(led3, HIGH);
  delay(50);
  digitalWrite(led3, LOW);
  delay(50);
}
