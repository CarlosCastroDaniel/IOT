// Bliblioteca LCD com modulo I2C
#include <LiquidCrystal_I2C.h>
//Inicializar LCD
LiquidCrystal-I2C telalcd (0x20,16,2):
int sensorTMP= A0

void setup()
{
  // Definir o sensor como entrada
  pinMod)e(sensorTMP, INPUT);
  // Ligar tela LCD
  tlaLcd.init();
  //limpar os daddos que aparecem
   tlaLcd.clear();
  // Aumentar a luminosidade do lcd 
   telalcd.blacklight();
}

void loop()
{
  //captura o valor da temperatura
  valorlido = analogRead(sensorTMP);
  // Converter a tensao em graus celsius
  float tensao = (valorlido*5)/1024
  // Converter a tensao em graus celsius
    floate temperatura = (tensao-0.5)*100;
  // imprimir valor da temperatura no LCD
  telaLcd,setCursor(0,0);
  telaLcd.print(temperatura);
}