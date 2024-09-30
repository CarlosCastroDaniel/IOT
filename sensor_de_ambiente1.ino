// Biblioteca LCD com módulo I2C
#include <LiquidCrystal_I2C.h>

// Inicializar LCD
LiquidCrystal_I2C telaLcd(0x20, 16, 2);
int sensorTMP = A0;

void setup() {
  // Definir o sensor como entrada
  pinMode(sensorTMP, INPUT);
  
  // Ligar tela LCD
  telaLcd.init();
  
  // Limpar os dados que aparecem
  telaLcd.clear();
  
  // Aumentar a luminosidade do LCD
  telaLcd.backlight();
}

void loop() {
  // Captura o valor da temperatura
  int valorLido = analogRead(sensorTMP);
  
  // Converter a tensão em graus Celsius
  float tensao = (valorLido * 5.0) / 1024.0;
  
  // Converter a tensão em graus Celsius
  float temperatura = (tensao - 0.5) * 100.0;
  
  // Imprimir valor da temperatura no LCD
  telaLcd.setCursor(0, 0);
  telaLcd.print(temperatura);
  telaLcd.print(" C"); // Adiciona o símbolo de Celsius
  delay(1000); // Espera 1 segundo antes de atualizar
}
