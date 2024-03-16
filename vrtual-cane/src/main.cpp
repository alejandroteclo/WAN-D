#include <Arduino.h>

// Pinout settings
const int altavoz = 16;
const int sensor = 13;
const int Echo = 18;

// put function declarations here:
int ping(int, int);
int DistanceToHz(int);
int Hercios;

void setup() {
  // put your setup code here, to run once:
  pinMode(altavoz, OUTPUT);
  pinMode(sensor, OUTPUT);
  pinMode(Echo, INPUT);
  
  ledcSetup(0, 85, 8);
  ledcAttachPin(altavoz, 0);
  analogWrite(altavoz, 100);
}

void loop() {
  // put your main code here, to run repeatedly:

}

// put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }

int ping(int TriggerSensPin, int EchoPin) {
  long duration, distanceCm;

  digitalWrite(TriggerSensPin, LOW); // para generar un pulso limpio ponemos a LOW 4us
  delayMicroseconds(4);
  digitalWrite(TriggerSensPin, HIGH); // generamos Trigger (disparo) de 10us
  delayMicroseconds(10);
  digitalWrite(TriggerSensPin, LOW);

  duration = pulseIn(EchoPin, HIGH); // medimos el tiempo entre pulsos, en microsegundos

  distanceCm = duration * 10 / 292 / 2; // convertimos a distancia, en cm
  return distanceCm;
}

int DistanceToHz(int distanciaEnCm) {
  //max zumm 255
  //max distance 5m
  // 255/5 = 51 niveles por metro
  // 255 ----  500
  // Y   ----  100
  // X = 255-Y
  Hercios = 255 - (distanciaEnCm * 255 / 500);
  if (Hercios < 10) {
    Hercios = 10;
  }
  return Hercios;
}


