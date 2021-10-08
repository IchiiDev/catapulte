#include <Servo.h>
#include "rgb_lcd.h"

int BUTTON = 7;
int SERVO1 = 4;
int SERVO2 = 3;
int POT = 0;
Servo servo1;
Servo servo2;
int buttonState;
int oldbuttonState;
rgb_lcd LCD;

void setup() {
  
  pinMode(POT, INPUT);
  pinMode(BUTTON, INPUT);
  servo1.attach(SERVO1);
  servo2.attach(SERVO2);
  Serial.begin(9600);

  LCD.begin(16, 2);

  LCD.setRGB(0, 255, 0);
  afficherLCD("Test !");

}

void loop() {
  
   buttonState = digitalRead(BUTTON);
   if (oldbuttonState != buttonState && buttonState == HIGH)
   {
      afficherLCD("Démarrage de la séquence de tir...");
      delay(2000);
      
      afficherLCD("Tension de l'élastique...");
      servo1.write(180);
      delay(2000);
      afficherLCD("Ouverture de la catapulte...");
      servo2.write(180);

      delay(5000);
      afficherLCD("Désarmement de l'élastique...");
      servo1.write(0);
      delay(3000);
      afficherLCD("Fermeture de la catapulte...");
      servo2.write(0);

      delay(2000);
      afficherLCD("Séquence de tir terminée !");
   }
   oldbuttonState = buttonState;
   
}

void afficherLCD(String text) {
  if (text.length < 32) {
    String line1 = text.slice(
  } else {
    throw "Cannot display this."
  }
  
  LCD.setCursor(0, 0);
  LCD.print(text);
  
}

void sliceInTwo(String text) {

  List<String>

}
