/*
* meetMINT Space 
* Bei erkannter Bewegung wird ein Text über die serielle Schnittstelle ausgegeben und eine LED angeschaltet
*
*/

// Verwendete Pins vom Board
const int LED = 6;
const int bewegungsPin = 2;
const int lautsprecherPin = 5;

// Variabeln Bewegunsmelder
int bewegungsStat = 0;
bool neueBewegung = true;

//Variabeln Lautsprecher
int tonHoehe1 = 100;
int tonHoehe2 = 200;
int sirenenInterval = 500;

//Sich ändernde Variabeln
int tonJetzt = 100;
unsigned long vorherigeMillis = 0;   // speichert wann der Lautsprecher das letzte Mal den Ton geänder hat (um delay zu umgehen)
unsigned long jetzigeMillis = 0;

/* Initialisierungen */
void setup() {
  // Definierung der In- und Outputs
  pinMode(LED, OUTPUT);
  pinMode(bewegungsPin, INPUT);
  pinMode(lautsprecherPin, OUTPUT);
  // Definierung der Baudrate
  Serial.begin(9600);
}

/* Programmcode */
void loop() {
  // Auslesen vom Bewegungssensor
  bewegungsStat = digitalRead(bewegungsPin); 
  // Auslesen der Sekunden
  jetzigeMillis = millis();

 if (bewegungsStat == HIGH) {

    // Wenn neue Bewegung erkannt
    if (neueBewegung) {
      neueBewegung = false;
      digitalWrite(LED, HIGH);
      Serial.println("Bewegung erkannt!");
    }

    sireneAbspielen();

  }

  else {
    digitalWrite(LED, LOW);
    noTone(lautsprecherPin);

    // Wenn Bewegungsstatus sich von 1 auf 0 aendert
    if (!neueBewegung) {
      neueBewegung = true;
      Serial.println("Keine Bewegung erkannt!");
    }
  }
}

void sireneAbspielen(){
  // Wenn das Intervall zum Tonwechsel vorbei ist
    if (jetzigeMillis - vorherigeMillis >= sirenenInterval) {
      
      // Wenn der Ton1 gespielt wurde, spiel den Ton2 und vice-versa:
      tonJetzt = (tonJetzt == tonHoehe1) ? tonHoehe2 : tonHoehe1;

      // spiel den Ton:
      tone(lautsprecherPin, tonJetzt);

      // speicher die letzte Zeit, die der Ton gespielt wurde
      vorherigeMillis = jetzigeMillis;
    }
}


