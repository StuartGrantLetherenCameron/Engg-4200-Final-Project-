/*
 * ENGG*4200 Project
 * Whack a Mole
 * Coordinator/Base/Game Node
 */

// Circuit parameters
const int numNodes = 3;
const char node[numNodes] = {'B', 'D', 'E'};
const int RED = 7;
const int GRN = 8;

// Game parameters
bool active = true;
int dest = 0;
int timer = 60 * 1000;
int score = 0;

// Communications
int incoming = 0;

void setup() {
  // Hardware setup
  pinMode(RED, OUTPUT);
  pinMode(GRN, OUTPUT);
  
  // Establish communication to XBee
  Serial.begin(9600);

  // Setup game
  randomSeed(analogRead(0));
  dest = random(numNodes);
}

void loop() {
  // Continue if game still active, else break.
  if (active == true) {
    digitalWrite(RED, HIGH);
    digitalWrite(GRN, LOW);
    return;
  } else {
    digitalWrite(RED, LOW);
    digitalWrite(GRN, HIGH);
  }

  // Tell current destination to output
  Serial.print(node[dest]);

  // Check for new data on Serial
  if (Serial.available() > 0) {
    incoming = Serial.read();

    // User pressed dest button
    if (incoming == node[dest]) {
      score = score + 1;
      dest = random(numNodes);
    }
  }

  // Break, increment timer, check if finished
  timer = timer - 100;
  if (timer <= 0) {
    active = false;
  }
  
  delay(100);
}
