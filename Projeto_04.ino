#include <Servo.h>  // Inclui a biblioteca para controlar o servo motor

// Definindo os pinos dos componentes
int verdeCar = 10;
int amareloCar = 9;
int vermelhoCar = 8;
int verdePed = 7;
int vermelhoPed = 6;
int botao = 5;
int buzzer = 4;

// Cria o objeto do servo motor
Servo cancela;

void setup() {
  // Definir os pinos dos LEDs e buzzer
  pinMode(verdeCar, OUTPUT);
  pinMode(amareloCar, OUTPUT);
  pinMode(vermelhoCar, OUTPUT);
  pinMode(verdePed, OUTPUT);
  pinMode(vermelhoPed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  
  // Inicializa o servo motor no pino 11
  cancela.attach(11);
  
  // Inicializa a cancela aberta (90 graus)
  cancela.write(90);
}

void loop() {
  // Sinal para carros
  digitalWrite(verdeCar, HIGH);
  digitalWrite(amareloCar, LOW);
  digitalWrite(vermelhoCar, LOW);
  
  // Sinal para pedestres
  digitalWrite(verdePed, LOW);
  digitalWrite(vermelhoPed, HIGH);
  
  if (digitalRead(botao) == 0) {
    // Buzzer apita continuamente enquanto o sinal está fechado para pedestres
    tone(buzzer, 1400);
    delay(3000);  // Espera antes de trocar o sinal
    
    // Mudar para sinal amarelo dos carros
    digitalWrite(verdeCar, LOW);
    digitalWrite(amareloCar, HIGH);
    delay(4000);  // Tempo no amarelo

    // Mudar para vermelho para carros e fechar a cancela
    digitalWrite(amareloCar, LOW);
    digitalWrite(vermelhoCar, HIGH);
    delay(2500);  // Tempo para os carros pararem

    // Fecha a cancela (ângulo 0)
    cancela.write(0);
    
    // Abrindo sinal para pedestres
    digitalWrite(vermelhoPed, LOW); 
    digitalWrite(verdePed, HIGH);
    
    // Buzzer apitando devagar enquanto pedestres podem atravessar
    for (int i = 0; i < 8; i++) {
      tone(buzzer, 1000);  // Frequência do buzzer enquanto o pedestre atravessa
      delay(500);          // Intervalo lento
      noTone(buzzer);      // Pausa o som
      delay(500);
    }
    
    // Sinal piscando para pedestres e buzzer apitando mais rápido
    for (int i = 0; i < 4; i++) {
      digitalWrite(verdePed, !digitalRead(verdePed)); // Pisca o LED verde
      tone(buzzer, 2000);  // Frequência mais alta para o aviso
      delay(250);          // Intervalo mais rápido
      noTone(buzzer);
      delay(250);
    }

    // Finalizando o ciclo, fechando sinal dos pedestres e abrindo cancela
    digitalWrite(verdePed, LOW);  // Desliga o LED verde dos pedestres
    digitalWrite(vermelhoPed, HIGH);  // Liga o LED vermelho dos pedestres

    // Abre a cancela (ângulo 90)
    cancela.write(90);

    delay(500);  // Pequeno intervalo antes de voltar ao ciclo normal
  }
}
