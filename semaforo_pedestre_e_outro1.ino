#define TRIG_Azul 12
#define ECHO_Azul 13
#define TRIG_Turquesa 14
#define ECHO_Turquesa 15
#define MAX_DISTANCE 200 // Distância máxima para verificar em cm

// Pinos dos LEDs
int ledVerdeCar_1 = 6;
int ledVerdeCar_2 = 3;
int ledVerdePED_1 = 10;
int ledVerdePED_2 = 11;
int ledVermeCar_1 = 2;
int ledVermeCar_2 = 5;
int ledVermePED_1 = 9;
int ledVermePED_2 = 8;
int ledAmarCAR_1 = 4;
int ledAmarCAR_2 = 7;

bool pedestrianDetected = false;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_Azul, OUTPUT);
  pinMode(ECHO_Azul, INPUT);
  pinMode(TRIG_Turquesa, OUTPUT);
  pinMode(ECHO_Turquesa, INPUT);
  
  // LEDs
  pinMode(ledVerdeCar_1, OUTPUT);
  pinMode(ledVerdeCar_2, OUTPUT);
  pinMode(ledVerdePED_1, OUTPUT);
  pinMode(ledVerdePED_2, OUTPUT);
  pinMode(ledVermeCar_1, OUTPUT);
  pinMode(ledVermeCar_2, OUTPUT);
  pinMode(ledVermePED_1, OUTPUT);
  pinMode(ledVermePED_2, OUTPUT);
  pinMode(ledAmarCAR_1, OUTPUT);
  pinMode(ledAmarCAR_2, OUTPUT);
  
  // Inicializa os semáforos
  initializeTrafficLights();
}

void loop() {
  delay(100);

  // Medidas dos dois sensores
  long distance1 = measureDistance(TRIG_Azul, ECHO_Azul);
  long distance2 = measureDistance(TRIG_Turquesa, ECHO_Turquesa);
  
  // Verifica a presença de pedestres
  pedestrianDetected = (distance1 > 0 && distance1 <= 50) || (distance2 > 0 && distance2 <= 50);

  if (pedestrianDetected) {
    switchToPedestrianMode();
    delay(15000); // Espera por 15 segundos
  } else {
    switchToCarMode();
  }
}

// Função para medir a distância
long measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  long distance = (duration * 0.034) / 2; // Divide por 2 porque vai e volta
  
  return distance;
}

void initializeTrafficLights() {
  // Semáforos dos carros verdes no início
  digitalWrite(ledVermeCar_1, LOW);
  digitalWrite(ledVerdeCar_1, HIGH);
  digitalWrite(ledVermeCar_2, LOW);
  digitalWrite(ledVerdeCar_2, HIGH);
  digitalWrite(ledVermePED_1, HIGH);
  digitalWrite(ledVerdePED_1, LOW);
  digitalWrite(ledVermePED_2, HIGH);
  digitalWrite(ledVerdePED_2, LOW);
  digitalWrite(ledAmarCAR_1, LOW);
  digitalWrite(ledAmarCAR_2, LOW);
}

void switchToPedestrianMode() {
  // Desliga os semáforos verdes dos carros, e liga os verdes dos pedestres
  digitalWrite(ledVermeCar_1, HIGH);
  digitalWrite(ledVerdeCar_1, LOW);
  digitalWrite(ledVermeCar_2, HIGH);
  digitalWrite(ledVerdeCar_2, LOW);
  digitalWrite(ledVermePED_1, LOW);
  digitalWrite(ledVerdePED_1, HIGH);
  digitalWrite(ledVermePED_2, LOW);
  digitalWrite(ledVerdePED_2, HIGH);
  digitalWrite(ledAmarCAR_1, LOW);
  digitalWrite(ledAmarCAR_2, LOW);
}

void switchToCarMode() {
  // Restaura os semáforos dos carros
  digitalWrite(ledVermeCar_1, LOW);
  digitalWrite(ledVerdeCar_1, HIGH);
  digitalWrite(ledVermeCar_2, LOW);
  digitalWrite(ledVerdeCar_2, HIGH);
  digitalWrite(ledVermePED_1, HIGH);
  digitalWrite(ledVerdePED_1, LOW);
  digitalWrite(ledVermePED_2, HIGH);
  digitalWrite(ledVerdePED_2, LOW);
  digitalWrite(ledAmarCAR_1, LOW);
  digitalWrite(ledAmarCAR_2, LOW);
}
