#include <Servo.h>

Servo objetoservo;

// Variáveis
const int ledVerm = 2; // Pino do LED vermelho
const int servoPin = 4; 
#define TRIG_PIN 3
#define ECHO_PIN 5 // Definindo o pino para Echo

int ultimoAngulo = -1; // Variável para armazenar o último ângulo do servo

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(ledVerm, OUTPUT); // Define o pino do LED como saída
  
  // Inicializando o servo na porta digital
  objetoservo.attach(servoPin);
  objetoservo.write(0); // Posição inicial do servo
}

void loop() {
  long duration, distance;

  // Medindo a distância
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration * 0.034) / 2; // Calcula a distância em cm
  
  // Se a distância do objeto for menor ou igual a 100 cm
  if (distance <= 100) {
    digitalWrite(ledVerm, HIGH); // Acende o LED vermelho
    int anguloAleatorio;

    // Gera um novo ângulo aleatório apenas se ele for diferente do último ângulo
    do {
      anguloAleatorio = random(0, 181); // Gira para um ângulo aleatório entre 0 e 180°
    } while (anguloAleatorio == ultimoAngulo);

    objetoservo.write(anguloAleatorio);
    ultimoAngulo = anguloAleatorio; // Atualiza o último ângulo
    delay(1000); // Aguarda um segundo para o servo se mover
    digitalWrite(ledVerm, LOW); // Desliga o LED vermelho
  } else {
    digitalWrite(ledVerm, LOW); // Garante que o LED esteja desligado se a distância for maior que 100 cm
  } 

  delay(500); // Aguarda meio segundo antes de medir novamente
}
