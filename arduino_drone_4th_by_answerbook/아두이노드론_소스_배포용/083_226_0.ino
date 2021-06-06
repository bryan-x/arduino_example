const int LED = 17;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, LOW);
  delay(5);
  digitalWrite(LED, HIGH);
  delay(5);
}