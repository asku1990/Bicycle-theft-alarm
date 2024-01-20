/* 7.4-2021 klo.22.00 Aki Kuivas. kiihtyvyysanturi aliohjelma joka
tutkii X Y Z sensorian astearvot ja talleentaa ne pointtereihin*/

#include "kiihtyvyysAnturi.h"
#include <Arduino.h>
#include <math.h>

const int gnd = A0;
const int plus5v = A4;
const int analogInPinX = A3; // X-kanavan kytkentänapa
const int analogInPinY = A2; // Y-kanavan kytkentänapa
const int analogInPinZ = A1; // Z-kanavan kytkentänapa
int sisaanmeno = 0;  // testi ollaanko menossa sisään ohjelmaan ensimmäistä kertaa

void kiihtyvyys(int *X, int *Y, int *Z)
{
  pinMode(gnd,OUTPUT);
  digitalWrite(gnd,LOW);
  pinMode(plus5v,OUTPUT);
  digitalWrite(plus5v,HIGH);

  int sensorValueX = 0;   // X-kiihtyvyyttä vastaava sensoriarvo 10 bittisessä järjestelmässä (0 - 1023)
  int sensorValueY = 0;   // Y-kiihtyvyyttä vastaava sensoriarvo 10 bittisessä järjestelmässä (0 - 1023)
  int sensorValueZ = 0;   // Z-kiihtyvyyttä vastaava sensoriarvo 10 bittisessä järjestelmässä (0 - 1023)
  unsigned long aika = 0; // aikaleima, joka luetaan millisekunteina. Int-tyyppinen määrittely tuottaisi nopean bitti-ylivuodon.
  

  double AccX = 0.0;
  double AccY = 0.0;
  double AccZ = 0.0;

  double DegX = 0.0;
  double DegY = 0.0;
  double DegZ = 0.0;

if (sisaanmeno == 0)
  {
    delay(1000);        // Annetaan aikaa käynnistelylle
    sisaanmeno = 1;     // Vaihdetaan tunnistetieto niin tänne ei enää tulla
  }

// Luetaan kanavien antamat sensoriarvot ja aikaleima

sensorValueX = analogRead(analogInPinX);
sensorValueY = analogRead(analogInPinY);
sensorValueZ = analogRead(analogInPinZ);

aika = millis();

// Kalibrointiyhtälöt sensoriarvosta kiihtyvyydeksi (m/s^2)

AccX = 0.1431 * sensorValueX - 48.766; //Kalibrointi olisi syytä tehdä laittamalla kertoimet muuttujien kautta, mutta tämä on nyt havainnollisempi
AccY = 0.1432 * sensorValueY - 48.93;
AccZ = 0.1509 * sensorValueZ - 49.503;

// Lasketaan akselien kulmat vaakatasoon verrattuna

// Ensiksi pitää varmistaa, että kiihtyvyysarvot ei mene yli g-arvosta

AccX = min(9.81 , AccX); // Rajoitetaan maksimi jotta asin-laskun voi tehdä
AccY = min(9.81 , AccY);
AccZ = min(9.81 , AccZ);
AccX = max(-9.81 , AccX); // Rajoitetaan minimi
AccY = max(-9.81 , AccY);
AccZ = max(-9.81 , AccZ);

// Lasketaan akselien kulmat vaakatasoon nähden ja muunnetaan radiaaneista asteiksi

DegX = asin(AccX / 9.81) * 180 / 3.141593;
DegY = asin(AccY / 9.81) * 180 / 3.141593;
DegZ = asin(AccZ / 9.81) * 180 / 3.141593;

*X = DegX;
*Y = DegY;
*Z = DegZ; 

delay(2);
}
