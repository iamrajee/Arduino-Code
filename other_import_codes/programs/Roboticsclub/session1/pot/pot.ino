int a;
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop() {
  a = analogRead(A0);
  Serial.println(a);
//  delay(100);
}
