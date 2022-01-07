int LED1 = 4;
int LED2 = 3;

void setup() {
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED2, HIGH);
}

void loop() {

  String str = Serial.readStringUntil('\n');
  if (str == "on") {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
  } else if (str == "off") {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
  }

}
