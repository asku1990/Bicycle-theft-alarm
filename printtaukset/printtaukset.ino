/*5.4-21 klo.23.10 Aki Kuivas. pääohjelma
testiohjelma printtauksille*/

#include "printtaukset.h" //joka ohjelmassa sisällytetään vain .h 
                           //header tiedosto jossa on märitykset

int X=1, Y=2, Z=3;
int toleranssiX1=-10,toleranssiX2=10;
int toleranssiY1=-10,toleranssiY2=10;
int toleranssiZ1=-10,toleranssiZ2=10;
                           
void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  tulostaValmiustilaXYZ(X,Y,Z);
  delay(1000);
  tulostaHalytysXYZ(X,Y,Z);
  delay(1000);
  tulostaHalytysPoisXYZ(X,Y,Z);
  delay(1000);
  tulostaToleranssitXYZ(toleranssiX1,toleranssiX2,
                        toleranssiY1,toleranssiY2,
                        toleranssiZ1,toleranssiZ2);
  delay(1000);
}
