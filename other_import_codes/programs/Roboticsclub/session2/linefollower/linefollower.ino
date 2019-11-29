//---------------Global declaration---------------------------------------//
//motor
int lm_pin=5;//right motor
int rm_pin=2;//left motor
int ls_pin=3;//right sensor
int rs_pin=4;//left sensor

//sensor
int rs_value;
int ls_value;




//--------------function defination------------------------------------------//
void read_sen_value()
{
  rs_value = digitalRead(rs_pin);
  ls_value = digitalRead(ls_pin);
}

void check_direction_move()
{
  if(ls_value == 0 && rs_value == 0) //WW
  {
    forward();//forward
  }
  else if(ls_value == 0 && rs_value == 1)//WB
  {
    right();//right
  }
  else if(ls_value == 1 && rs_value == 0)//BW
  {
    left();//left
  }
  else if(ls_value == 1 && rs_value == 1)//BB
  {
    STOP();//STOP
  }
  
}

void forward()
{
  digitalWrite(lm_pin, 1); //both high
  digitalWrite(rm_pin, 1);
}
void left()
{
  digitalWrite(lm_pin, 0); 
  digitalWrite(rm_pin, 1);//right high
}
void right()
{
  digitalWrite(lm_pin, 1); //left high
  digitalWrite(rm_pin, 0);
}
void STOP()
{
  digitalWrite(lm_pin, 0);//both low
  digitalWrite(rm_pin, 0);
}

//----------------setup-------------------------------------------------------//
void setup() {
  Serial.begin(9600);

  delay(2000);
    
  pinMode(rm_pin, OUTPUT);//output
  pinMode(lm_pin, OUTPUT);
  pinMode(rs_pin, INPUT);//input
  pinMode(ls_pin, INPUT);
}


//-----------------loop-------------------------------------------------------//
void loop() {
  read_sen_value();

  check_direction_move();
}
