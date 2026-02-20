// "Nomeando" as portas
int verdeCar = 10;
int amareloCar = 9;
int vermelhoCar = 8;
int verdePed = 7;
int vermelhoPed = 6;
int botao = 5;
int buzzer = 4;

void setup() {
  // Indicando para o Arduino os tipos das portas
  pinMode(verdeCar, OUTPUT);
  pinMode(amareloCar, OUTPUT);
  pinMode(vermelhoCar, OUTPUT);
  pinMode(verdePed, OUTPUT);
  pinMode(vermelhoPed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop() {
  // Semáforo para carros
  digitalWrite(verdeCar, HIGH);
  digitalWrite(amareloCar, LOW);
  digitalWrite(vermelhoCar, LOW);
  
  // Semáforo pedestres
  digitalWrite(verdePed, LOW);
  digitalWrite(vermelhoPed, HIGH);
  
  if (digitalRead(botao) == 0) {
    // Buzzer apita continuamente enquanto o sinal está fechado
    tone(buzzer, 1400);
    delay(3000);  // Espera antes de trocar sinal
    digitalWrite(verdeCar, LOW);
    digitalWrite(amareloCar, HIGH);
    delay(4000);  // Tempo do amarelo
    
    digitalWrite(amareloCar, LOW);
    digitalWrite(vermelhoCar, HIGH);
    delay(2500);  // Tempo para os carros pararem

    // Abrindo o semáforo para pedestres
    digitalWrite(vermelhoPed, LOW); 
    digitalWrite(verdePed, HIGH);
    
    // Buzzer apitando devagar enquanto pedestres podem atravessar
    for (int i = 0; i < 8; i++) {
      tone(buzzer, 1000);  // Frequência do buzzer durante o sinal aberto
      delay(500);          // Intervalo lento enquanto o pedestre atravessa
      noTone(buzzer);      // Pausa o som
      delay(500);
    }
    
    // Sinal começa a fechar (LED verde piscando e buzzer apitando mais rápido)
    for (int i = 0; i < 4; i++) {	
      digitalWrite(verdePed, !digitalRead(verdePed)); // Pisca o LED verde
      tone(buzzer, 2000);  // Frequência mais alta para o aviso
      delay(250);          // Intervalo mais rápido no fechamento
      noTone(buzzer);
      delay(250);
    }

    // Finalizando o ciclo, desligando o semáforo de pedestres
    digitalWrite(verdePed, LOW);  // Desliga o LED verde dos pedestres
    delay(500);                   // Pequeno intervalo antes de voltar ao ciclo normal
  }
}
