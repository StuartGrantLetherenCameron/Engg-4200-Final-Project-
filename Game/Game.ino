const int numNodes = 2;
const int btn[] = {2, 3};
const int led[] = {8, 9};

bool lost = false;
int rnd = 1;
int timer = 5 * 1000;

void setup() {
  Serial.begin(9600);

  // XBEE SETUP

  // GAME SETUP
  randomSeed(analogRead(0));
  for (int i = 0; i < numNodes; i++) {
    pinMode(btn[i], INPUT);
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  if (lost == false) {
    int dest = random(numNodes);
    digitalWrite(led[dest], HIGH);

    // Send start to destination node

    // Wait for response from dest with button press

    // If response not received within timer then move on

    while (digitalRead(btn[dest]) != HIGH && timer >= 0) {
      timer = timer - 1;
      delay(1);
      Serial.println("Updating timer");
    }

    Serial.println("Button pressed or counter out");

    digitalWrite(led[dest], LOW);
  }  

//  digitalWrite(led0, HIGH);
//  digitalWrite(led1, HIGH);
//
//  Serial.print("Destination is ");
//  Serial.println(destination);
//  Serial.print("Btn0 is ");
//  Serial.println(digitalRead(n0));
//  Serial.print("Btn1 is ");
//  Serial.println(digitalRead(n1));

  timer = 5 * 1000;
  delay(1000);
}
