/*
* meetMINT Space 
* Bei erkannter Bewegung wird ein Text über die serielle Schnittstelle ausgegeben und eine LED angeschaltet
*
*/

// Verwendete Pins vom Board
const int LED = 6;
const int pirPin = 2;

// Variablen
int pirStat = 0;

/* Initialisierungen */
void setup() {
  // Definierung der In- und Outputs
  pinMode(LED, OUTPUT);
  pinMode(pirPin, INPUT);
  // Definierung der Baudrate
  Serial.begin(9600);
}

/* Programmcode */
void loop() {
  pirStat = digitalRead(pirPin);

  if (pirStat == HIGH) {
  digitalWrite(LED, HIGH);
  Serial.println("Bewegung erkannt!"); // Aktuell wird es ganz oft ausgegeben
  }
  else {
  digitalWrite(LED, LOW);
  }

}
