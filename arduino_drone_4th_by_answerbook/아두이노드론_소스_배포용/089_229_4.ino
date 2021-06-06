const int LED = 17;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  for(int t_high=0;t_high<=10;t_high++) {
	int cnt=0;
	while(true) {
	  digitalWrite(LED, LOW);
	  delay(t_high);
	  digitalWrite(LED, HIGH);
	  delay(10-t_high);

	  cnt++;
	  if(cnt==10) break;
	}
  }
}