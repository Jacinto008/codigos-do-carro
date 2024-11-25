int in1 = 7;
int in2 = 6;
int in3 = 5;
int in4 = 4;
int trig = 11;
int echo = 12;
float distcm;
float dist;
int led = 18;


void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
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

  if(distcm > 10){
    frente();
  }
  if(distcm <= 10){
    parar();
    delay(1000);
    re();
    delay(1000);
    direita();
    delay(1000);
    
  }
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
  digitalWrite(in2, LOW);
  // lado esquerdo
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  }

void direita(){
    // lado direito 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // lado esquerdo
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  }
