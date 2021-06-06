#include <TimerOne.h>

const int fan_pin = 10;

void setup() {
  Timer1.initialize(); 
  Timer1.pwm(fan_pin, 0);

  Timer1.setPeriod(1000000/100); // 100Hz
  Timer1.setPwmDuty(fan_pin, 100);
}

void loop() {}