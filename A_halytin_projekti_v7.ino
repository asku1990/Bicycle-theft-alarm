/*19.4 klo.12.00 Aki Kuivas, Heikki Pätsi, Aleksi Vilppola. pääohjelma
vihreä ledi merkitsee että virrat on päällä.
kun bluetooth lähettää merkin 'C', alustetaan hälytin kyseiseen asentoon laskemalla toleranssit asteista.
punainen ledi merkitsee että hälytin on aktivoitu ja toleranssit laskettu nykyisessä asennossa.
kun x,y tai z akselin arvot muuttuu yli toleranssin (+ - toleranssi), kytketään hälytys päälle. 
hälytystä toistetaan kunnes annetaan bluetooth käsky 'C' jolloin hälytin alustetaan uudelleen (punainen valo).
jos painat uudellen blootoohilla 'C' kytkeytyy hälytin valmiustilaan jolloin vihreä valo syttyy virran merkiksi.*/

#include  "bluetoothTila/bluetoothTila.h"        
#include  "bluetoothTila/bluetoothTila.cpp"
#include  "halytysValo/halytysValo.h"  
#include  "halytysValo/halytysValo.cpp"  
#include  "halytysSireeni/halytysSireeni.h"
#include  "halytysSireeni/halytysSireeni.cpp"
#include  "tilaValo/tilaValo.h"
#include  "tilaValo/tilavalo.cpp"
#include  "kiihtyvyysAnturi/kiihtyvyysAnturi.h"
#include  "kiihtyvyysAnturi/kiihtyvyysAnturi.cpp"
#include  "printtaukset/printtaukset.h"
#include  "printtaukset/printtaukset.cpp"

#define TOLERANSSI 15

int X, Y, Z;
int toleranssiX1 = 0, toleranssiX2 = 0;
int toleranssiY1 = 0, toleranssiY2 = 0;
int toleranssiZ1 = 0, toleranssiZ2 = 0;

int testi = 0;
  
void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  if (bluetoothTila() == 'C')
    {
      while (bluetoothTila() != 'C')
      {
        if (testi == 0)
         {
            kiihtyvyys(&X, &Y, &Z);
            delay(2);
            toleranssiX1 = X + TOLERANSSI;
            toleranssiX2 = X - TOLERANSSI;
            
            toleranssiY1 = Y + TOLERANSSI;
            toleranssiY2 = Y - TOLERANSSI;

            toleranssiZ1 = Z + TOLERANSSI;
            toleranssiZ2 = Z - TOLERANSSI;
      
            testi = 1;
            
            tulostaToleranssitXYZ(toleranssiX1,toleranssiX2,
                                  toleranssiY1,toleranssiY2,
                                  toleranssiZ1,toleranssiZ2);                
            delay(1000);
          }
            punainenLedBLINK();
            kiihtyvyys(&X, &Y, &Z);
            tulostaValmiustilaXYZ(X,Y,Z);
            delay(10);
        
          if (X > toleranssiX1 || X < toleranssiX2 ||
              Y > toleranssiY1 || Y < toleranssiY2 ||
              Z > toleranssiZ1 || Z < toleranssiZ2)
          {
            while (bluetoothTila() != 'C')
            {
              halytysValo();
              halytysSireeni();
              testi = 0;
              
              kiihtyvyys(&X, &Y, &Z);            
              tulostaHalytysXYZ(X,Y,Z);
              delay(2);
            }
          }
      }
  }
  else
  {
    vihreaLedBLINK();
    testi = 0;   

    kiihtyvyys(&X, &Y, &Z);
    tulostaHalytysPoisXYZ(X,Y,Z);
      
    delay(10);
  }
}
