/*
* meetMINT Space 
* Bei erkannter Bewegung wird ein Text über die serielle Schnittstelle ausgegeben und eine LED angeschaltet
*
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Display
// 0x3F = Hexadresse vom Display
// 16 = Anzahl der darstellbaren Zeichen
// 2 = Zeilenanzahl
LiquidCrystal_I2C lcd(0x27, 16, 2); 

// Verwendete Pins vom Board
const int LED = 6;
const int bewegungsPin = 2;

// Variablen
int bewegungsStat = 0;
bool neueBewegung = true;

/* Initialisierungen */
void setup() {
  // Definierung der Baudrate
  Serial.begin(9600);  
  // Display-Einstellungen
  lcd.init();
  lcd.backlight();  
  // Definierung der In- und Outputs
  pinMode(LED, OUTPUT);
  pinMode(bewegungsPin, INPUT);
}

/* Programmcode */
void loop() {
  // Auf Display schreiben
  lcd.setCursor(0, 0);

  // Auslesen vom Bewegungssensor
  bewegungsStat = digitalRead(bewegungsPin); 

  if (bewegungsStat == HIGH) {
    // Wenn neue Bewegung erkannt
    if (neueBewegung) {
      neueBewegung = false;
      digitalWrite(LED, HIGH);
      Serial.println("Bewegung erkannt!");
      lcd.clear();
      lcd.print("Bewegung erkannt!");
    }
  }
  else {
    digitalWrite(LED, LOW);

    // Wenn Bewegungsstatus sich von 1 auf 0 aendert
    if (!neueBewegung) {
      neueBewegung = true;
      Serial.println("Keine Bewegung erkannt!");
      lcd.clear();
      lcd.print("Keine Bewegung");
      // In die zweite Zeile schreiben
      lcd.setCursor(0, 1); 
      lcd.print("erkannt!");
    }
  }

}
