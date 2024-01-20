#include "bluetoothTila.h"        
void setup() 
{
Serial.begin(9600);        
}
void loop()
{
  if (bluetoothTila() == 'C')      //lukee onko serial true
  {
    while (bluetoothTila() != 'C') //jos serial on käynyt true, muuttuu serial falseksi
    {                                //luupataan niinkauan kun serial pysyy falsena,
      Serial.println("on");
      delay(1000);
    }
  }
  else
  { 
  Serial.println("of");
  delay(1000);
  }
}
