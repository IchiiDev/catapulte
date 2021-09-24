#include <Servo.h>

int BUTTON = 7;
int SERVO = 4;
int POT = 8;
Servo servo;
int buttonState;
int oldbuttonState;

void setup() {
  
  pinMode(POT, INPUT);
  pinMode(BUTTON, INPUT);
  servo.attach(SERVO);
  Serial.begin(9600);

}

void loop() {
  
   buttonState = digitalRead(BUTTON);
   if (oldbuttonState != buttonState && buttonState == HIGH)
   {
      int power = map(analogRead(POT), 0 , 1023, 0, 180);
      Serial.println(power);
      servo.write(power);
      delay(2000);
      servo.write(0);
   }
   oldbuttonState = buttonState;
}
