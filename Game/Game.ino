const int numNodes = 3;

const int node[] = {"B", "D", "E"};

int dest = 0;
bool lost = false;
int rnd = 1;
int score = 0;
bool t;

void setup() {
  Serial.begin(9600);

  // GAME SETUP
  randomSeed(analogRead(0));
}

void loop() {
  if (lost == false) {

    // Send start to destination node
    Serial.print(node[dest]);

    // Wait for response from dest with button press
    if (Serial.available() && t == true) {
      char c = Serial.read();
      if (c == node[dest]) {
        Serial.println("Button pressed");
        dest = random(numNodes);
        score += 1;
      } else {
        t = false;
      }
    }

    delay(100);
  }
}
