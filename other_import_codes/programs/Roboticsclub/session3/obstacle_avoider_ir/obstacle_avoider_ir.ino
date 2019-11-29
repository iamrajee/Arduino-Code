//---------------Global declaration---------------------------------------//
//motor
int lm_pin1=2;
int lm_pin2=3;
int rm_pin1=4;
int rm_pin2=5;

//delay
int turn_delay = 100;
int reverse_delay = 50;

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
  if(ls_value == 0 && rs_value == 0) //WW //object on both side
  {
    reverse();
    delay(reverse_delay); 
    right();                            //<-----------Changes
    delay(turn_delay*2);              
  }
  else if(ls_value == 0 && rs_value == 1)//WB           //object on left side
  {
    reverse();
    delay(reverse_delay); 
    right();//right
    delay(turn_delay);                            //<-----------Changes
  }
  else if(ls_value == 1 && rs_value == 0)//BW          //object on right side
  {
    reverse();
    delay(reverse_delay);  
    left();//left
    delay(turn_delay);                            //<-----------Changes
  }
  else if(ls_value == 1 && rs_value == 1)//BB          //no object
  {
    forward();                            //<-----------Changes
  }
  
}

void forward()
{
  digitalWrite(lm_pin1, 1);
  digitalWrite(lm_pin2, 0);
  digitalWrite(rm_pin1, 1);
  digitalWrite(rm_pin2, 0);
}

void reverse()
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

  delay(2000);
    
  pinMode(rm_pin1, OUTPUT);//motor
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
