// C++ code
#include <Servo.h>

/*criando objeto do tipo Servo motor
parar poder usar as funções de 
controle do equipamento (servo moto)
*/
Servo objetoservo;
//biblioteca par asalvar a port que o servo está
int servo =4; 

void setup()
{
  // Inicializaão do servo
  objetoservo.attach(servo);
}

void loop()
{
 //  Sevo rotacionando a 45°
  objetoservo.write(45);
  delay(500); 
  //  Sevo rotacionando a 90°
  objetoservo.write(90);
  delay(500); 
  //  Sevo rotacionando a 135°
  objetoservo.write(135);
  delay(500);
   //  Sevo rotacionando a 180°
  objetoservo.write(180);
  delay(500);
    //  Sevo rotacionando a 135°
  objetoservo.write(135);
  delay(500);
    //  Sevo rotacionando a 90°
  objetoservo.write(90);
  delay(500); 
  //  Sevo rotacionando a 45°
  objetoservo.write(45);
  delay(500);
    //  Sevo rotacionando a 0°
  objetoservo.write(0);
  delay(500);
  
}