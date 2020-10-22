/* 
Esse código foi feito para um braço robotico com quatro servo motores com um sensor de cor, 
para identificar qual das 3 cores (verde, azul ou vermelho) o objeto pertence. Nesse sentido, 
é válido destacar, que a iluminação é um fator determinante na identificação das cores.
*/

// inclui bibilioteca do servomotor
#include <Servo.h> 

//Pinos de conexao do modulo
#define pinS0 8
#define pinS1 9
#define pinS2 12
#define pinS3 11
#define pinOut 10
#define pinLED 7

// define pinos dos servos
#define pinServ1 2
#define pinServ2 3
#define pinServ3 4
#define pinServ4 5

// nomeia os servos
Servo serv1,serv2,serv3,serv4;

// cria as variavies dos angulos de cada motor
int motor1,motor2,motor3,motor4;

// posicao
int posicao, pos;

unsigned long mostradorTimer = 1;
const unsigned long intervaloMostrador = 5000;
int tmp = 1000;

unsigned int valorVermelho = 0;
unsigned int valorVerde = 0;
unsigned int valorAzul = 0;
unsigned int valorBranco = 0;

void setup() {

  //inicia o monitor serial
  Serial.begin(9600); 

  // atribui pinos dos servos
  serv1.attach(pinServ1);
  serv2.attach(pinServ2);
  serv3.attach(pinServ3);
  serv4.attach(pinServ4);

   pinMode(pinS0, OUTPUT);
  pinMode(pinS1, OUTPUT);
  pinMode(pinS2, OUTPUT);
  pinMode(pinS3, OUTPUT);
  pinMode(pinLED, OUTPUT);
  pinMode(pinOut, INPUT);

  Serial.begin(9600);
  digitalWrite(pinS0, HIGH);
  digitalWrite(pinS1, LOW);

  delay(2000);
  //Liga LED
  digitalWrite(pinLED, HIGH);
}

void detectaCor();

void loop()
{
  //Detecta a cor
  detectaCor();

  //Mostra valores no serial monitor
  Serial.print("Vermelho :");
  Serial.print(valorVermelho);

  Serial.print(" Verde : ");
  Serial.print(valorVerde);

  Serial.print(" Azul : ");
  Serial.print(valorAzul);

  Serial.print(" Branco : ");
  Serial.print(valorBranco);
  Serial.println();

  //Verifica se a cor vermelha foi detectada
  if ((valorVermelho < valorAzul) &&
      (valorVermelho < valorVerde) &&
      (valorBranco < 100)) {
    Serial.println("Vermelho");
    pP1();
  delay(tmp);
  /*p2();*/
  for (posicao = 126; posicao <= 158; posicao++){
  serv3.write(posicao);
  delay(10);
  }
  delay(tmp);
  pP2();
  delay(tmp);
  pP3();
  delay(tmp);
  pP4();
  delay(tmp);
  pP5();
  delay(tmp);
  pP6();
  delay(tmp);
  pP7();
  delay(tmp);
  pVermelho4();
  pP8();
  delay(tmp);
  pP9();
  delay(tmp);
  pP10();
  delay(tmp);
  pP11();
  delay(tmp);
  pP12();
  delay(tmp);
  pP13();
  delay(tmp);
  pVermelho4();
  delay(tmp);
  delay(500);
  pVermelho5();
  delay(tmp);
  vP1();
  delay(tmp);
  vP2();
  delay(tmp);

  } else if ((valorAzul < valorVermelho) &&  //Verifica se a cor azul foi detectada
             (valorAzul < valorVerde) &&
             (valorBranco < 100)) {
    Serial.println("Azul");
     pP1();
  delay(tmp);
  /*p2();*/
  for (posicao = 126; posicao <= 158; posicao++){
  serv3.write(posicao);
  delay(10);
  }
  delay(tmp);
  pP2();
  delay(tmp);
  pP3();
  delay(tmp);
  pP4();
  delay(tmp);
  pP5();
  delay(tmp);
  pP6();
  delay(tmp);
  pP7();
  delay(tmp);
  pVermelho4();
  pP8();
  delay(tmp);
  pP9();
  delay(tmp);
  pP10();
  delay(tmp);
  pP11();
  delay(tmp);
  pP12();
  delay(tmp);
  pP13();
  delay(tmp);
  pAzul4();
  delay(tmp);
  pAzul5();
  delay(tmp);
  vP1();
  delay(tmp);
  vP2();
  delay(tmp);

  } else if ((valorVerde < valorVermelho) &&  //Verifica se a cor verde foi detectada
             (valorVerde < valorAzul) &&
             (valorBranco < 100)) {
    Serial.println("Verde");
     pP1();
  delay(tmp);
  /*p2();*/
  for (posicao = 126; posicao <= 158; posicao++){
  serv3.write(posicao);
  delay(10);
  }
  delay(tmp);
  pP2();
  delay(tmp);
  pP3();
  delay(tmp);
  pP4();
  delay(tmp);
  pP5();
  delay(tmp);
  pP6();
  delay(tmp);
  pP7();
  delay(tmp);
  pVermelho4();
  pP8();
  delay(tmp);
  pP9();
  delay(tmp);
  pP10();
  delay(tmp);
  pP11();
  delay(tmp);
  pP12();
  delay(tmp);
  pP13();
  delay(tmp);
  pVerde4();
  delay(tmp);
  pVerde5();
  delay(tmp);
  
  vP1();
  delay(tmp);
  vP2();
  delay(tmp);
  }
  Serial.println();

}


// *********** Função de leitura so sensor de cor ********************
void detectaCor() {
  //Vermelho
  digitalWrite(pinS2, LOW);
  digitalWrite(pinS3, LOW);
  valorVermelho = pulseIn(pinOut, digitalRead(pinOut) == HIGH ? LOW : HIGH);
  
  //Sem filtro
  digitalWrite(pinS3, LOW);
  digitalWrite(pinS2, HIGH);
  valorBranco = pulseIn(pinOut, digitalRead(pinOut) == HIGH ? LOW : HIGH);

  //Azul
  digitalWrite(pinS2, LOW);
  digitalWrite(pinS3, HIGH);
  valorAzul = pulseIn(pinOut, digitalRead(pinOut) == HIGH ? LOW : HIGH);

  //Verde
  digitalWrite(pinS2, HIGH);
  digitalWrite(pinS3, HIGH);
  valorVerde = pulseIn(pinOut, digitalRead(pinOut) == HIGH ? LOW : HIGH);
}

//Volta
void vP1(){
  serv1.write(163);
  serv2.write(0);
  serv3.write(118);
  serv4.write(169);
  }
void vP2(){
  serv1.write(104);
  serv2.write(0);
  serv3.write(118);
  serv4.write(169);
  }


//Ida 
void pP1(){
  serv1.write(94);
  serv2.write(0);
  serv3.write(126);
  serv4.write(169);
  }

void pP2(){//for de 126 a 158
  serv1.write(115);
  serv2.write(0);
  serv3.write(158);
  serv4.write(169);
  }
void pP3(){
  serv1.write(115);
  serv2.write(0);
  serv3.write(156);
  serv4.write(169);
  }
void pP4(){
  serv1.write(115);
  serv2.write(0);
  serv3.write(164);
  serv4.write(169);
  }
  void pP5(){
  serv1.write(115);
  serv2.write(24);
  serv3.write(164);
  serv4.write(169);
  }
  void pP6(){
  serv1.write(115);
  serv2.write(24);
  serv3.write(160);
  serv4.write(169);
  }
  void pP7(){
  serv1.write(109);
  serv2.write(24);
  serv3.write(160);
  serv4.write(169);
  }
  void pP8(){
  serv1.write(109);
  serv2.write(24);
  serv3.write(154);
  serv4.write(169);
  }
  void pP9(){
  serv1.write(103);
  serv2.write(24);
  serv3.write(154);
  serv4.write(169);

  }
  void pP10(){
  serv1.write(103);
  serv2.write(24);
  serv3.write(149);
  serv4.write(169);
  }
  void pP11(){
  serv1.write(95);
  serv2.write(24);
  serv3.write(149);
  serv4.write(169);
  }
  void pP12(){
  serv1.write(95);
  serv2.write(24);
  serv3.write(118);
  serv4.write(169);
  }
  void pP13(){
  serv1.write(163);
  serv2.write(24);
  serv3.write(118);
  serv4.write(169);
  }
  //VERMELHO
void pVermelho4(){
  for (pos = 169; pos <= 118; pos = pos-1){
  serv3.write(pos);
  delay(200);
 
  }
  
  }
void pVermelho5(){
  serv1.write(163);
  serv2.write(24);
  serv3.write(118);
  serv4.write(122);
  delay(1000);
  serv1.write(163);
  serv2.write(0);
  serv3.write(118);
  serv4.write(122);
  }
  
  //VERDE
  void pVerde4(){
  for (pos = 169; pos <= 23; pos = pos-1){
  serv3.write(pos);
  delay(10);
  }
  }
void pVerde5(){
  serv1.write(163);
  serv2.write(24);
  serv3.write(118);
  serv4.write(23);
  
  delay(1000);
  
  serv1.write(163);
  serv2.write(0);
  serv3.write(118);
  serv4.write(23);
  }
  //AZUL
void pAzul4(){
  for (pos = 169; pos <= 63; pos = pos-1){
  serv3.write(pos);
  delay(10);
  }
  }
void pAzul5(){
  serv1.write(166);
  serv2.write(24);
  serv3.write(124);
  serv4.write(63);
  
  delay(1000);
  serv1.write(166);
  serv2.write(0);
  serv3.write(124);
  serv4.write(63);
  }
  
