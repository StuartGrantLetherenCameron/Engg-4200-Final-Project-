const byte node[3] = {0xBB, 0xDD, 0xEE};

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(13, HEX);

  delay(1000);
}
