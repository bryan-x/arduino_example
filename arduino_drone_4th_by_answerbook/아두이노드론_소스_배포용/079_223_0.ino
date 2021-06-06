const int LED = 17;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {  
  digitalWrite(LED, LOW);  
  digitalWrite(LED, HIGH);  
}