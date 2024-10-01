int sensorPIR = 3;
int buzzer = 5;
int led = 4;

void setup() {
  pinMode(sensorPIR, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int detectarPresenca = digitalRead(sensorPIR);
  if (detectarPresenca == 1) {  
    tone(buzzer, 244);
     digitalWrite(led, HIGH);
  } else {
    noTone(buzzer);
     digitalWrite(led, LOW);
  }
}
