int i;
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  
}

void loop() {
  i = 0;
  Serial.println("glow");
  while(i<1024)
  {
    analogWrite(A0, i);
    i=i+1;
    delay(10);
  }
  //delay(1000);
  i = 1023;
  Serial.println("fade");
  while(i>0)
  {
    analogWrite(A0, i);
    i=i-1;
    delay(100);
  }
  delay(1000);
}
