
int i =0;
int j =0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.write(0);
//  delay(1000);
//  Serial.write(2);
//  delay(1000);
//  Serial.write(4);
//  delay(1000);
  Serial.write(i);
  Serial.write(j);
  Serial.write('b');
  Serial.write('b');
  Serial.write(';');
  i++;
  j++;
  if (i == 4){
    i = 0;
  }
  if (j == 10){
    j = 0;
  }
  delay(1000);
}
