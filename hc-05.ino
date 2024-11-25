#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Dabble.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Dabble.processInput();
  Serial.print("tecla pressionado: ");´
  if(GamePad.isUpPressed()) {
    Serial.print("frente");
    frente();
  }
  if(GamePad.isDownPressed()){
    Serial.print("tras");
    tras();
  }
  if(GamePad.isRightPressed()){
    Serial.print("direita");
    direita();
  }
  if(GamePad.isLeftPressed()){
    Serial.print("esquerda");
    esquerda();
  }
}
