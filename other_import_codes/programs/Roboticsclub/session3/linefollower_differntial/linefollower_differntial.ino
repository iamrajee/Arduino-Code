//---------------Global declaration---------------------------------------//
//motor
int lm_pin1=2;          //<-------------------------Changes
int lm_pin2=3;
int rm_pin1=4;
int rm_pin2=5;

//sensor
int ls_pin=6;
int rs_pin=7;
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

void forward()                      //---------------changes in all below functions
{
  digitalWrite(lm_pin1, 1);
  digitalWrite(lm_pin2, 0);
  digitalWrite(rm_pin1, 1);
  digitalWrite(rm_pin2, 0);
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

  delay(2000);
    
  pinMode(rm_pin1, OUTPUT);//motor        //<---------------Changes
  pinMode(rm_pin2, OUTPUT);
  pinMode(lm_pin1, OUTPUT);
  pinMode(lm_pin2, OUTPUT);
  
  pinMode(rs_pin, INPUT);//input
  pinMode(ls_pin, INPUT);
}


//-----------------loop-------------------------------------------------------//
void loop() {
  read_sen_value();

  check_direction_move();
}
