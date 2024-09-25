// variaveis dos led
int ledVermelho = 3;
int ledVerde = 1;
int ledAzul = 0;
int ledVermelho2 = 4;
int ledVerde2 = 6;
int ledAzul2 = 7;

void setup()
{
	pinMode(ledVermelho,OUTPUT);
  	pinMode(ledVerde,OUTPUT);
  	pinMode(ledAzul,OUTPUT);
  	pinMode(ledVermelho2,OUTPUT);
  	pinMode(ledVerde2,OUTPUT);
  	pinMode(ledAzul2,OUTPUT);
}

void loop()
{
  	//ligar o led verde, vermelho, azul
  
  	digitalWrite(ledVermelho,HIGH);//Ligar vermelho
  	digitalWrite(ledVermelho2,LOW);//Ligar vermelho
  	digitalWrite(ledVerde,HIGH);//desligar verde
  	digitalWrite(ledVerde2,LOW);//desligar verde2
  	digitalWrite(ledAzul,HIGH);//desligar azul
  	digitalWrite(ledAzul2,LOW);//desligar azul2
  	delay(5000);//espre 5 segundos
  
  
  	//ligar os leds 2 AZUIS E 2 VERDES
  	digitalWrite(ledVermelho,LOW);//Ligar vermelho
  	digitalWrite(ledVermelho2,LOW);//Ligar vermelho2
  	digitalWrite(ledVerde,HIGH);//desligar verde
  	digitalWrite(ledVerde2,HIGH);//desligar verde2
  	digitalWrite(ledAzul,HIGH);//desligar azul
  	digitalWrite(ledAzul2,HIGH);//desligar azul
  	delay(5000);//espere 5 segundos
  
  
 	 //1 VERDE , 2 VERMELHOS E 1 AZUL.
  	digitalWrite(ledVermelho,HIGH);//Ligar vermelho
  	digitalWrite(ledVermelho2,HIGH);//Ligar vermelho2
  	digitalWrite(ledVerde,LOW);//desligar verde
  	digitalWrite(ledVerde2,LOW);//desligar verde2
  	digitalWrite(ledAzul,HIGH);//desligar azul
  	digitalWrite(ledAzul2,LOW);//desligar azul
  	delay(10000);//espere 10 segundos
 
  
}