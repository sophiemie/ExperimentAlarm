/*
* meetMINT Space 
* Bei erkannter Bewegung wird ein Text über die serielle Schnittstelle ausgegeben und eine LED angeschaltet
*
*/

// Verwendete Pins vom Board
const int LED = 6;
const int bewegungsPin = 2;

// Variablen
int bewegungsStat = 0;
bool neueBewegung = true;

/* Initialisierungen */
void setup() {
  // Definierung der In- und Outputs
  pinMode(LED, OUTPUT);
  pinMode(bewegungsPin, INPUT);
  // Definierung der Baudrate
  Serial.begin(9600);
}

/* Programmcode */
void loop() {
  // Auslesen vom Bewegungssensor
  bewegungsStat = digitalRead(bewegungsPin); 

  
  if (bewegungsStat == HIGH) {
    // Wenn neue Bewegung erkannt
    if (neueBewegung) {
      neueBewegung = false;
      digitalWrite(LED, HIGH);
      Serial.println("Bewegung erkannt!");
    }
  }
  else {
    digitalWrite(LED, LOW);

    // Wenn Bewegungsstatus sich von 1 auf 0 aendert
    if (!neueBewegung) {
      neueBewegung = true;
      Serial.println("Keine Bewegung erkannt!");
    }
  }

}
