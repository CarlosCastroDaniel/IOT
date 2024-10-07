// include a biblioteca
#include <AccelStepper.h>
// conversão de graus para steps
// 360°= 1024
//180° = 512
//90° = 256
//60° = 170
//45° = 128
//30° = 85
//15° = 28

// variavel objeto controlar as voltas do motor
#define Voltas = 1024

//criando objeto para controlar o motor 
AccelStepper motor (AccelStepper::FULL4WIRE,8,10,9,11)

void setup(){
  // definir a velocidade maxima do motor 
 motor.setMaxSpeed(1000);
 // definir aceleração maxima do motor

}

void loop(){
// habilitar as portas de contrle do motor no arduino
motor.run();
// fazer o motor de movimentara a 360/1024 passos
motor.moveTO(Voltas);

}