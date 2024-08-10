#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa o display LCD no endereço 0x3F com 16 colunas e 2 linhas
LiquidCrystal_I2C lcd(0x27, 16, 2); // Substitua 0x27 pelo seu endereço

// Define os pinos dos LEDs
const int ledPin1 = 4;
const int ledPin2 = 5;
const int ledPin3 = 6;

// Define os pinos do sensor de ultrassom
const int trigPin = 8;
const int echoPin = 9;

// Variável para armazenar a distância medida
long duration;
int distance;

void setup() {
  // Configura os pinos dos LEDs como saída
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  // Configura os pinos do sensor de ultrassom
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Inicializa a comunicação serial para monitoramento
  Serial.begin(9600);

  // Inicializa o LCD
  lcd.init();
  lcd.backlight(); // Liga a luz de fundo do LCD
  lcd.clear(); // Limpa o LCD para garantir que não há texto residual
  lcd.setCursor(0, 0); // Posiciona o cursor na primeira linha do LCD
  lcd.print("Distance:"); // Exibe o texto fixo na primeira linha
}

void loop() {
  // Limpa o trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Configura o trigPin em HIGH por 10 microsegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Lê o echoPin, retorna o tempo de viagem do som em microsegundos
  duration = pulseIn(echoPin, HIGH);
  
  // Calcula a distância em centímetros
  distance = duration * 0.034 / 2;
  
  // Exibe a distância no LCD
  lcd.setCursor(0, 1); // Posiciona o cursor na segunda linha do LCD
  lcd.print("                "); // Limpa a linha anterior com espaços
  lcd.setCursor(0, 1); // Retorna ao início da segunda linha
  lcd.print(distance);
  lcd.print(" cm");

  // Aciona os LEDs com base na distância medida
  if (distance < 10) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
  } else if (distance < 20) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
  } else if (distance < 30) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
  } else {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }

  delay(500); // Pequeno atraso para estabilizar a leitura
}
