#define Rl 1000 //resistência interna do sensor (esse valor vem de fábrica)

void setup(){ 
  Serial.begin(9600); //inicia a comunicação serial com o computador

  pinMode(A0, INPUT); //pino A2 é definido comoe ntrada analógica, no caso o valor do sensor
} 
  
void loop(){   
  float Vo = analogRead(A0) * 5; //cálculo da tensão sobre o resistor 
  Vo = Vo / 1024; 

  float Rs = (5 - Vo) * Rl; //valor da resistência Rs
  
  Serial.println("Resistencia: " + String(round(Rs))); //mostra "Resistencia: " e o valor medido na frente 
} 
