// Biblioteca para cone
#include <SoftwareSerial.h>

int sensor = A0;

void setup()
{
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop()
{
  // Guarda o valor lido pelo sensor
  int umidade = analogRead(sensor);
  Serial.println("Umidade do solo:");
  Serial.println(umidade);
  delay(1000);
  
  // Corrigindo as condições if
  if (umidade >= 0 && umidade <= 300) {
    Serial.println("Seco");
  } else if (umidade > 300 && umidade <= 500) {
    Serial.println("Solo ideal");
  } else if (umidade > 500) {
    Serial.println("Solo úmido");
  }
}
