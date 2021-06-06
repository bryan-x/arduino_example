 #include <Wire.h >

 void setup() {
  Serial1.begin(115200);  

  Wire.begin();
  Wire.setClock(400000);
  
  Wire.beginTransmission(0x68);
  Wire.write(0x6b);
  Wire.write(0x0);
  Wire.endTransmission(true);
}

 int throttle =0;
 void loop() {
  Wire.beginTransmission(0x68);
  Wire.write(0x45);
  Wire.endTransmission(false);
  Wire.requestFrom(0x68,2,true);
  int16_t GyYH = Wire.read();  
  int16_t GyYL = Wire.read();
  int16_t GyY = GyYH <<8 |GyYL;

  static int32_t GyYSum =0;
  static double GyYOff =0.0;
  static int cnt_sample =1000;
  if(cnt_sample >0) {
	GyYSum += GyY;
	cnt_sample --;
	 if(cnt_sample ==0) {      
	  GyYOff = GyYSum /1000.0;
	}
	delay(1);
	 return;    
  }
  double GyYD = GyY - GyYOff;
  double GyYR = GyYD /131;

  static unsigned long t_prev =0;
  unsigned long t_now = micros();
  double dt = (t_now - t_prev)/1000000.0;
  t_prev = t_now;

  static double AngleY =0.0;
  AngleY += GyYR *dt;
  if(throttle ==0) AngleY =0.0;

  static double tAngleY =0.0;
  double eAngleY = tAngleY - AngleY;
  double Kp =1.0;
  double BalY = Kp *eAngleY;

  //지나친 회전 속도 거르기
  double Kd =1.0;
  BalY += Kd *-GyYR;
  if(throttle ==0) BalY =0.0;

  if(Serial1.available()>0) {
   while(Serial1.available()>0) {
	 char userInput = Serial1.read();
	  if(userInput >='0'&& userInput <='9') {
		throttle = (userInput -'0')*25;
	  }
	}
  }

  double speedA = throttle + BalY;  
  double speedB = throttle - BalY;  
  double speedC = throttle - BalY;
  double speedD = throttle + BalY;

  int iSpeedA = constrain((int)speedA, 0, 250);
  int iSpeedB = constrain((int)speedB, 0, 250);
  int iSpeedC = constrain((int)speedC, 0, 250);
  int iSpeedD = constrain((int)speedD, 0, 250);
  
  analogWrite(6, iSpeedA);
  analogWrite(10,iSpeedB);
  analogWrite(9, iSpeedC);
  analogWrite(5, iSpeedD);

 //  static int cnt_loop;
 //  cnt_loop ++;
 //  if(cnt_loop%100 !=0) return;
   
 //  Serial.print("GyY = "); Serial.print(GyY);
 //  Serial.print("GyYD = "); Serial.print(GyYD);
 //  Serial.print("GyYR = "); Serial.print(GyYR);
 //  Serial.print("dt = "); Serial.print(dt, 6);
 //  Serial.print("AngleY = "); Serial.print(AngleY);
 //  Serial.print(" | BalY = "); Serial.print(BalY);
 //  Serial.print("A = ");Serial.print(speedA);
 //  Serial.print(" | B = ");Serial.print(speedB);
 //  Serial.print(" | C = ");Serial.print(speedC);
 //  Serial.print(" | D = ");Serial.print(speedD);
 //  Serial.println();
}
