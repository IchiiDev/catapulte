#include <Servo.h>

int BUTTON = 7;
int SERVO1 = 4;
int SERVO2 = 3;
int POT = 8;
Servo servo1;
Servo servo2;
int buttonState;
int oldbuttonState;

void setup() {
  
  pinMode(POT, INPUT);
  pinMode(BUTTON, INPUT);
  servo1.attach(SERVO1);
  servo2.attach(SERVO2);
  Serial.begin(9600);

}

void loop() {
  
   buttonState = digitalRead(BUTTON);
   if (oldbuttonState != buttonState && buttonState == HIGH)
   {
      Serial.println("Démarrage de la séquence de tir...");
      delay(2000);
      
      Serial.println("Tension de l'élastique...");
      servo1.write(180);
      delay(2000);
      Serial.println("Ouverture de la catapulte...");
      servo2.write(180);

      delay(5000);
      Serial.println("Désarmement de l'élastique...");
      servo1.write(0);
      delay(3000);
      Serial.println("Fermeture de la catapulte...");
      servo2.write(0);

      delay(2000);
      Serial.println("Séquence de tir terminée !");
   }
   oldbuttonState = buttonState;
   
}
