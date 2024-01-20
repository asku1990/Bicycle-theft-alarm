/*5.4-21 klo.23.10 Aki Kuivas. Aliohjelmat serial monitorille 
tulostuksia varten.*/

#include "printtaukset.h"
#include <Arduino.h>

void tulostaValmiustilaXYZ(int X, int Y, int Z)
{
  Serial.print("Valmiustila ; ");
  Serial.print(X);
  Serial.print(" ; ");
  Serial.print(Y);
  Serial.print(" ; ");
  Serial.println(Z);
}
void tulostaHalytysXYZ(int X, int Y, int Z)
{
  Serial.print("Halytys! ; ");
  Serial.print(X);
  Serial.print(" ; ");
  Serial.print(Y);
  Serial.print(" ; ");
  Serial.println(Z);  
}
void tulostaHalytysPoisXYZ(int X, int Y, int Z)
{
  Serial.print("pois päältä ; ");
  Serial.print(X);
  Serial.print(" ; ");
  Serial.print(Y);
  Serial.print(" ; ");
  Serial.println(Z);
}
void tulostaToleranssitXYZ(int toleranssiX1,int toleranssiX2,
                           int toleranssiY1,int toleranssiY2,
                           int toleranssiZ1,int toleranssiZ2)
{
  Serial.print("X toleranssit ; ");
  Serial.print(toleranssiX1);
  Serial.print(" ; ");
  Serial.println(toleranssiX2);
  Serial.print("Y toleranssit ; ");
  Serial.print(toleranssiY1);
  Serial.print(" ; ");
  Serial.println(toleranssiY2); 
  Serial.print("Z toleranssit ; "); 
  Serial.print(toleranssiZ1);
  Serial.print(" ; ");
  Serial.println(toleranssiZ2);
}
