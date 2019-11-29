#include<SoftwareSerial.h>

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  int b = analogRead(A0);//INPUT TO ARDUINO FROM RECEIVER MODULE
  Serial.println(b);
}
