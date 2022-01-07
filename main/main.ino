#include <Servo.h>
#include "rgb_lcd.h"

int BUTTON1 = 7;
int BUTTON2 = 2;
int COMPTEUR = 5;
int SERVO1 = 4;
int SERVO2 = 3;
int SWITCH = 8;
int POT = 0;
Servo servo1;
Servo servo2;
int buttonState;
int oldbuttonState;
rgb_lcd LCD;

void setup() {
  
  pinMode(POT, INPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(SWITCH, INPUT);
  pinMode(COMPTEUR, OUTPUT);
  servo1.attach(SERVO1);
  servo2.attach(SERVO2);
  servo1.write(0);
  servo2.write(90);
  Serial.begin(9600);

  LCD.begin(16, 2);

  LCD.setRGB(0, 255, 0);

}

void loop() {
 
   if (digitalRead(SWITCH) == HIGH) {
     delay(150);
     int potValue = analogRead(POT);
     int power = map(potValue, 0, 1023, 0, 180);
     servo1.write(power);
     String str = Serial.readStringUntil('\n');
     if (str == "on") {

        servo2.write(180);

        delay(3000);
        servo1.write(0);

        delay(3000);
        servo2.write(90);
        
     }
   
   } else {
     setup();
    
     buttonState = digitalRead(BUTTON1);
     if (oldbuttonState != buttonState && buttonState == HIGH)
     {
        int potValue = analogRead(POT);
        int power = map(potValue, 0, 1023, 0, 180);
        afficherLCD("Demarrage", "sequence de tir");
        delay(2000);
        
        afficherLCD("Tension", "elastique");
        servo1.write(power);
        delay(2000);
        afficherLCD("Ouverture", "catapulte");
        servo2.write(180);
  
        delay(3000);
        afficherLCD("Desarmement", "elastique");
        servo1.write(0);
        delay(3000);
        afficherLCD("Fermeture", "catapulte");
        servo2.write(90);
  
        delay(2000);
        afficherLCD("Séquence de tir", "terminée !");
     }
     oldbuttonState = buttonState;
   
   }
   
}

void afficherLCD(String text1, String text2) {
  if (text1.length() < 16 && text2.length() < 16) {
     LCD.clear();
     LCD.setCursor(0, 0);
     LCD.print(text1);
     LCD.setCursor(0, 1);
     LCD.print(text2);
  }
  
}
