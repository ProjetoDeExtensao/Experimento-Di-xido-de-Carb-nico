#include "LiquidCrystal.h" //biblioteca do display

#define Rl 1000 //resistência interna do sensor

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //conexões que fizemos no display

void setup(){ 
  lcd.begin(16, 2); //aqui a gente coloca o tamanho do nosso display, que no caso é 16x2
  
  pinMode(6,OUTPUT); //pino 6 é definido como saída
  analogWrite(6, 90); //pino 6 é uma saída pwm com tamanho 90
  
  pinMode(A0, INPUT); ///pino A0 é definido como entrada analógica
} 
  
void loop(){   
  float Vo = analogRead(A2) * 5; ////cálculo da tensão sobre o resistor
  Vo = Vo / 1023;

  float Rs = (5 - Vo) * Rl; //valor da resistência Rs 
  
  lcd.setCursor(0,0);  //posição inicial para escrever
  lcd.print("Resistencia"); //escreve "Resistencia"(linha de cima)
  
  lcd.setCursor(0, 1); //pula a posição para uma linha abaixo
  lcd.println(Rs); //esreve o valor de Rs (linha de baixo) 
} 
