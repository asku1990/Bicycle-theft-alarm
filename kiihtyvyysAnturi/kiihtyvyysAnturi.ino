/* 3.4-2021 klo.13.20 Aki Kuivas. kiihtyvyysanturi pääohjelma joka ensin antaa aikaa käynnisty,
ja kutsuu sitten kiihtyvyys aliohjelmaa ja alkaa printtaan tuloksia X Y Z*/

#include "kiihtyvyysAnturi.h"

int X, Y, Z;

void setup() 
{
Serial.begin(9600);
}

void loop() 
{

// tulosta asteet  
kiihtyvyys(&X, &Y, &Z);
  
Serial.print(X);
Serial.print(" ; ");
  
Serial.print(Y);
Serial.print(" ; ");
 
Serial.println(Z);      // rivinvaihto lopuksi
}
