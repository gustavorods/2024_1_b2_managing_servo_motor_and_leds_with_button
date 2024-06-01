#include <Servo.h>

// Pino do botão
const int pinBotao = 13; 
// Variável para armazenar o estado do botão
int estadoBotao = 0;   

// Número de LEDs
const int quantidadeLeds = 6;  
// Pinos dos LEDs
const int pinosLeds[quantidadeLeds] = {11, 10, 9, 6, 5, 4};  
// Posições do servo motor correspondentes aos LEDs
const int posicoesServo[quantidadeLeds] = {30, 60, 90, 140, 180, 0};  

Servo servoMotor;

void setup() {
  // Configurando todos os pinos dos LEDs como saídas
  for (int i = 0; i < quantidadeLeds; i++) {
    pinMode(pinosLeds[i], OUTPUT);
  }

  // Inicializando comunicação serial
  Serial.begin(9600);

  // Associando o pino ao servo motor
  servoMotor.attach(3);

  // Configurando o pino do botão como entrada
  pinMode(pinBotao, INPUT);

  // Definindo posição inicial do servo motor em 0 graus
  servoMotor.write(0);
}

void loop() {
  // Lendo o estado do botão
  estadoBotao = digitalRead(pinBotao);

  // Verificando se o botão está pressionado
  if (estadoBotao == HIGH) {
    acenderLedsEMoverServo();
  }
}

void acenderLedsEMoverServo() {
  // Loop para percorrer os LEDs
  for (int i = 0; i < quantidadeLeds; i++) {
    // Acende o LED correspondente
    digitalWrite(pinosLeds[i], HIGH);
    // Move o servo motor para a posição correspondente
    servoMotor.write(posicoesServo[i]);
    // Delay de 1 segundo para melhor visualização
    delay(1000);
    // Apaga o LED
    digitalWrite(pinosLeds[i], LOW);
  }
}
