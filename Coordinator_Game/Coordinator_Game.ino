/*
* ENGG*4200 Project
* Whack a Mole
* Coordinator/Base/Game Node
*/

#include <LiquidCrystal.h>

// Circuit parameters
const int numNodes = 3;
const char node[numNodes] = {'B', 'D', 'E'};
const char rcv[numNodes] = {'b', 'd', 'e'};
const int RED = 7;
const int GRN = 8;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Game parameters
bool active = true;
int dest = 0;
int prev = 0;
int score = 0;

int duration = 30;
int timer = duration * 1000;

// Communications
int incoming = 0;

void setup() {
  // Hardware setup
  pinMode(RED, OUTPUT);
  pinMode(GRN, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Whack a mole!");
  
  // Establish communication to XBee
  Serial.begin(9600);

  // Setup game
  randomSeed(analogRead(0));
  dest = random(numNodes);
}

void loop() {
  
  // Continue if game still active, else break.
  if (active == true) {
    digitalWrite(RED, LOW);
    digitalWrite(GRN, HIGH);
  } else {
    digitalWrite(RED, HIGH);
    digitalWrite(GRN, LOW);
    Serial.print('X');
    return;
  }

  // Tell current destination to output
  Serial.print(node[dest]);

  // Check for new data on Serial
  if (Serial.available() > 0) {
    incoming = Serial.read();

    // User pressed dest button
    if (incoming == rcv[dest]) {
      score = score + 1;
      lcd.setCursor(0, 1);
      lcd.print("Score: ");
      lcd.print(score);
      
      prev = dest;
      while (dest == prev) {
        duration = duration - 1;
        if (duration < 10) {
          duration = 10;
        }
        timer = duration * 1000;
        dest = random(numNodes);
      }
    }
  }

  // Break, increment timer, check if finished
  timer = timer - 100;
  if (timer <= 0) {
    active = false;
  }

  delay(100);
}
