int a;
void setup() {
  Serial.begin(9600);
  pinMode(13,INPUT);
}

void loop() {
  a = digitalRead(13);
  Serial.println(a);
}
