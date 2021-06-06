const int fan_pin = 10;

void setup() {
  pinMode(fan_pin, OUTPUT);
}

void loop() {
  digitalWrite(fan_pin, HIGH);
  delay(10);
  digitalWrite(fan_pin, LOW);
  delay(90);
}