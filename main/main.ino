#include <Servo.h>

int BUTTON = 7;
int SERVO = 4;
int POT = 8;
Servo servo;

void setup() {
  
  pinMod(POT, INPUT);
  pinMode(BUTTON, INPUT);
  servo.attach(SERVO);
  
}

void loop() {
  
  if (digitalRead(BUTTON) == HIGH) {
    servo.write();
  } else {
    servo.write(0);
  }

}
