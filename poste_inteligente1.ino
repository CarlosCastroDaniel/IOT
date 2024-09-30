

// Variaveis
int led =5;
int sensorluminosidade = A0;
int luz =0;


void setup()
{
 pinMode(led,OUTPUT),// Led é de saida
  pinMode(sensorluminosidade,INPUT);
}

void loop()
{
  // Caputrar o  que o sensor leu no ambiente
  // AnalogRead é usado para leitura analogica
  
  luz = analogRead(sensorluminosidade);
  /* As portas analogicas capturam dados qu variam de 0 até 
  1023*/
  if(luz<500 & luz <900){
    digitalWrite(led,HIGH);// Ligar led
  }else{ 
    digitalWrite(led,LOW); //Desligar led
  } 
  if (luz<500){
    //Digital (led,HIGH); // LIGAR LED
    analogWrite(led,1023);
  }if(luz<500 & luz<900){
    // Passar ao led intensidade média
    analogWrite(led,500);
  }else{ // Se tiver luz
   // digitalWrite(led,LOW); // Desligar
   analogWrite(led,0);
  }
    
  
}