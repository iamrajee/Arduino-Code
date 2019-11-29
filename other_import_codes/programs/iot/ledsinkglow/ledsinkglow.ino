int ldrPin = 15;

void setup() {
  Serial.begin(115200);
  pinMode(16, OUTPUT);
  digitalWrite(16, HIGH);
  pinMode(ldrPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(ldr));
  ldrVal = analogRead(ldr);
  if(ldrVal == 1)
  {
    digitalWrite(16, LOW);
    Serial.println("LED CONTINUOUSLY ON");
  }
  else if(digitalRead(ldr) == HIGH){
    digitalWrite(16, LOW);
    Serial.println("LED ON");
    delay(500);
    digitalWrite(16, HIGH);
    Serial.println("LED OFF");
    delay(500);
  }
}
