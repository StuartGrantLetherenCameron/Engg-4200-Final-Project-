/*
 * ENGG*4200 Project
 * Whack a Mole
 * Router/Destination Node
 */

// Node indentifier
const int NI = 'B';

// Circuit parameters
const int led = 5;
const int btn = 2;
volatile byte btnState = LOW;

void setup() {
  // Hardware setup
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(btn), btnPressed, CHANGE);
  
  // Establish communication to XBee
  Serial.begin(9600);
}

void loop() {
  // Reset led to LOW
  digitalWrite(led, LOW);
  
  // If button has been pressed, transmit
  if (btnState = true) {
    Serial.write(NI);
    btnState = LOW;
  }
  
  // Check for new data on Serial
  if (Serial.available() > 0) {
    incoming = Serial.read();
    if (incoming == NI) {
      digitalWrite(led, HIGH);
    }
  }

  delay(100);
}

void btnPressed() {
  btnState = HIGH;
}

