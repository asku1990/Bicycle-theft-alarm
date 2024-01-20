/*5.4-21 klo.23.09 Aki Kuivas. aliohjelmien esittelyt.*/

#ifndef maarittelyt
#define maarittelyt

#include <Arduino.h>

//aliohjelmien esittelyt
void tulostaValmiustilaXYZ(int X, int Y, int Z);
void tulostaHalytysXYZ(int X, int Y, int Z);
void tulostaHalytysPoisXYZ(int X, int Y, int Z);
void tulostaToleranssitXYZ(int toleranssiX1,int toleranssiX2,
                           int toleranssiY1,int toleranssiY2, 
                           int toleranssiZ1,int toleranssiZ2);

#endif
