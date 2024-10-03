// Variaveis

int buzzer = 3;
 #define do 263
#define re 294
#define mi 330
#define fa 349

void setup()
{
  pinMode(buzzer, OUTPUT);
}

void loop()
{
 // A função de ligar = tone()
  tone(buzzer,do,500); // tocar dó
  delay(600); // espere 600 milisegundos
  tone(buzzer,re,500); // tocar re
  delay(600); // espere 600 milisegundos
  tone(buzzer,mi,500); // tocar mi
  delay(600); // espere 600 milisegundos
  tone(buzzer,fa,500); // tocar fa
  delay(600); // espere 600 milisegundos
  // Afunção de desligar = notone()
  
  
}