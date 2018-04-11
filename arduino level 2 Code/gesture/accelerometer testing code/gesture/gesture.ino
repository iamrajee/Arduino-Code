int x,y;          //coordinate
int xpin = A0;    //analog pin
int ypin = A1;  //analog pin

void setup(){
  Serial.begin(9600); //baudrate for communication
  
}

void loop(){
  x = analogRead(xpin); // read the x axis value
  y = analogRead(ypin); // read the y axis value

  Serial.print(x); // print the sensor values
  Serial.print("\t"); // print a tab between values
  Serial.println(y); 
  delay(100); //delay before next reading
  
}
