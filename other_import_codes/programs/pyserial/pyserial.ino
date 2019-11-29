
int led = 13;
char flag = '1';
int data = 0;
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);     
}

void loop() {
//  Serial.print("Hi ");
//  Serial.println(led);
//  if (Serial.available()){
//    flag = Serial.read();
//    Serial.print(flag);
//  }
//  ``
//  if(flag=='1'){
//    digitalWrite(led, HIGH);
//    delay(1000);
//  } else {
//    digitalWrite(led, LOW);    
//    delay(1000);
//  }
  //data = analogRead(A0);
  data = 512;
  data = map(data,0,1023,0,255);
//  if (data < 1023){
//    data = data+1;
//  }else{
//    data = 0;
//  }
  //Serial.println(data);
  
  Serial.write(data);
  delay(100);


}
