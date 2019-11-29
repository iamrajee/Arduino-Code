//App :  Arduino Bluetooth RC Car
//---------------Global declaration---------------------------------------//
//motor
int lm_pin1=2;
int lm_pin2=3;
int rm_pin1=4;
int rm_pin2=5;

char data = 'S'; 


//--------------function defination------------------------------------------//
void forward()
{
  digitalWrite(lm_pin1, 1);
  digitalWrite(lm_pin2, 0);
  digitalWrite(rm_pin1, 1);
  digitalWrite(rm_pin2, 0);
}
void backward()
{
  digitalWrite(lm_pin1, 0);
  digitalWrite(lm_pin2, 1);
  digitalWrite(rm_pin1, 0);
  digitalWrite(rm_pin2, 1);
}
void left()
{
  digitalWrite(lm_pin1, 0);
  digitalWrite(lm_pin2, 1);
  digitalWrite(rm_pin1, 1);
  digitalWrite(rm_pin2, 0);
}
void right()
{
  digitalWrite(lm_pin1, 1);
  digitalWrite(lm_pin2, 0);
  digitalWrite(rm_pin1, 0);
  digitalWrite(rm_pin2, 1);
}
void STOP()
{
  digitalWrite(lm_pin1, 0);
  digitalWrite(lm_pin2, 0);
  digitalWrite(rm_pin1, 0);
  digitalWrite(rm_pin2, 0);
}

//----------------setup-------------------------------------------------------//
void setup() {
  Serial.begin(9600);

  delay(500);
    
  pinMode(rm_pin1, OUTPUT);//motor
  pinMode(rm_pin2, OUTPUT);
  pinMode(lm_pin1, OUTPUT);
  pinMode(lm_pin2, OUTPUT);
}


//-----------------loop-------------------------------------------------------//
void loop()
{
  if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
      Serial.println(data);          //Print Value inside data in Serial monitor
      if(data == 'S')
         STOP();
      else if(data == 'F')
         forward();
      else if(data == 'B')
         backward();
      else if(data == 'L')
         left();
      else if(data == 'R')
         right();
   }  
}
