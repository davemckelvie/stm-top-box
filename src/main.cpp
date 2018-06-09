/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include <Arduino.h>

uint16_t count = 0;

void setPwm(uint16_t value) {
   Serial.print("set value: ");
   Serial.println(value);
   pwmWrite(PA0, value);
   pwmWrite(PA1, value);
   pwmWrite(PA2, value);
   pwmWrite(PA3, value);
   pwmWrite(PB0, value);
   pwmWrite(PB1, value);
   pwmWrite(PA6, value);
   pwmWrite(PA7, value);
   pwmWrite(PB6, value);
   pwmWrite(PB7, value);
}

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(PC13, OUTPUT);
  pinMode(PA8, INPUT_PULLUP);
  pinMode(PA0, PWM);
  pinMode(PA1, PWM);
  pinMode(PA2, PWM);
  pinMode(PA3, PWM);
  pinMode(PB0, PWM);
  pinMode(PB1, PWM);
  pinMode(PA6, PWM);
  pinMode(PA7, PWM);
  pinMode(PB6, PWM);
  pinMode(PB7, PWM);

  setPwm(0x7FFF);
  Serial.begin(9600);
}

void flash(uint8_t state) {
   if (state) {
      setPwm(100);
   } else {
      setPwm(0x3FFF);
   }
}

void loop()
{
   count +=100;
   //setPwm(count);

   if (digitalRead(PA8) == HIGH) {
      flash(1);
   } else {
      flash(0);
   }
  
   // digitalWrite(PC13, HIGH);
   // flash(1);
  
   delay(100);
  
   // digitalWrite(PC13, LOW);
   // flash(0);
   // delay(100);
}