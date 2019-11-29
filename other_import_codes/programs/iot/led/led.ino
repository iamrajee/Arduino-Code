void setup() 
{
  pinMode(16, OUTPUT);  // Declare pin number 16 as output pin
  Serial.begin(115200);
}

void loop()             // put your main code here, to run repeatedly: 
{
  digitalWrite(16, HIGH);        //Write pin 16 as Low to make LED glow
  Serial.println("LED ON");     //Print on the serial monitor that LED is ON
}
