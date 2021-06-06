void setup() {
  delay(3000);
}

void loop() {
  analogWrite( 6, 25); delay(1000);
  analogWrite(10, 25); delay(1000);
  analogWrite( 9, 25); delay(1000);
  analogWrite( 5, 25); delay(1000);
  
  analogWrite( 6, 0);  
  analogWrite(10, 0);  
  analogWrite( 9, 0);   
  analogWrite( 5, 0); 
  delay(4000);
}