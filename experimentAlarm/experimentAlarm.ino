/*
* meetMINT Space 
* Erster Versuch mit dem Arduino Uno eine LED anzusteuern.
*
*/

const int LED = 6;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  delay(500);
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
}
