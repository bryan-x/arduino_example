void setup() {
  Serial1.begin(115200);
}

void loop() {
  if(Serial1.available()>0) {  
	char userInput = Serial1.read();
	Serial1.println(userInput);
	
	if(userInput >='0'&& userInput <='9') {
	  int throttle = (userInput -'0')*25;
	  analogWrite(6,throttle);
	  analogWrite(10,throttle);
	  analogWrite(9,throttle);
	  analogWrite(5,throttle);
	}
  }
}