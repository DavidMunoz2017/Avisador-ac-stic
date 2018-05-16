/**********************************************************************************
**                                                                               **
**                              Avisador Acústic                                 **
**                                                                               **
**                                                                               **
**********************************************************************************/

//********** Includes *************************************************************

//********** Variables ************************************************************
const int xiulet = 9;        // donar nom al pin 9 de l’Arduino
const int ldr0 = A0;         // donar nom al pin A0 de l’Arduino

int valLdr0;                 // guardar valor del ldr  
int freq;                    // freqüència del xiulet

//********** Setup ****************************************************************
void setup()
{
  pinMode(xiulet, OUTPUT);     // definir el pin 9 com una sortida

  Serial.begin (9600);
  
}

//********** Loop *****************************************************************
void loop()
{
  valLdr0 = analogRead(ldr0);   // llegir valor ldr
  Serial.println (valLdr0);
  freq = map(valLdr0, 150, 900, 200, 1000);   // mapejar valor de 0-1023 a 2000-10
  Serial.println (freq);
  tone(xiulet, 750, freq);   // xiulet de durada 100ms
  delay(2*freq);            // esperar xiulet + silenci
}

//********** Funcions *************************************************************

