#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <GamePadModule.h>

int in1 = 7;
int in2 = 6;
int in3 = 5;
int in4 = 4;
int trig = 11;
int echo = 12;
float distcm;
float dist;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600);     //Enter baudrate of your bluetooth.Connect bluetooth on Bluetooth port present on evive.
  //Pinos do Motor
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  //Pinos do sensor
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

}

void loop() {
  digitalWrite(trig, LOW);
  delay(0005);// iniciar leitura de distancia

  digitalWrite(trig, HIGH);
  delay(00010);

  digitalWrite(trig, LOW);

  dist = pulseIn(echo, HIGH);
  distcm = dist/58;
  Serial.println(distcm);// contar a distancia



  
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  Serial.print("KeyPressed: ");
    if(distcm <= 5){
    parar();
    re();
    delay(10);
  }else
  if (GamePad.isUpPressed())
  {
    Serial.print("UP");
    frente();
  }else
  if (GamePad.isDownPressed())
  {
    Serial.print("DOWN");
    re();
  }else

  if (GamePad.isLeftPressed())
  {
    Serial.print("Left");
    esquerda();
  }else

  if (GamePad.isRightPressed())
  {
    Serial.print("Right");
    direita();
  }else {
    Serial.print("Stop");
    parar();
  }

  
  Serial.print('\t');

  Serial.println();
}


void re(){
    // lado direito 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // lado esquerdo
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  }

void parar(){
    // lado direito 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // lado esquerdo
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  }

void frente(){
    // lado direito 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // lado esquerdo
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  }

void esquerda(){
    // lado direito 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // lado esquerdo
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  }

void direita(){
    // lado direito 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // lado esquerdo
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  }
