const int LED = 17;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, LOW);
  delay(50);
  digitalWrite(LED, HIGH);
  delay(50);
}