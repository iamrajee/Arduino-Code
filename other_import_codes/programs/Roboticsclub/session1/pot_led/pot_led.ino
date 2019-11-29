int a;
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,OUTPUT);
}

void loop() {
  a = analogRead(A0);
  Serial.println(a);
  analogWrite(A1, a);
//  delay(1000);
}
