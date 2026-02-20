`// Parte 2 - Semáforo interativo
// "Nomeando" as portas
int verdeCar = 10;
int amareloCar = 9;
int vermelhoCar = 8;
int verdePed = 7;
int vermelhoPed = 6;`

`int botao = 5;`

`void setup() {
// Indicando para o arduíno os tipos das portas
pinMode(verdeCar, OUTPUT);
pinMode(amareloCar, OUTPUT);
pinMode(vermelhoCar, OUTPUT);
pinMode(verdePed, OUTPUT);
pinMode(vermelhoPed, OUTPUT);
pinMode(botao, INPUT_PULLUP);
}`

`void loop() {
digitalWrite(verdeCar, HIGH);
digitalWrite(vermelhoPed, HIGH);`

`if (digitalRead(botao)== 0){
delay(2000);
digitalWrite(verdeCar, LOW);
digitalWrite(vermelhoCar, LOW);
digitalWrite(amareloCar, HIGH);
delay(1000);
digitalWrite(amareloCar, LOW);
digitalWrite(vermelhoCar, HIGH);
delay(500);`

```arduino
digitalWrite(vermelhoPed, LOW);
digitalWrite(verdePed, HIGH);
delay(2000);
digitalWrite(verdePed, LOW);
digitalWrite(vermelhoCar, LOW);
```

`}
}`
