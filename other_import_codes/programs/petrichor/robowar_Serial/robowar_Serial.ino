const int ch1_pin=9; 
const int ch4_pin=10;
const int ch5_pin=11;

//motor
int lm_pin1=2;
int lm_pin2=3;
int rm_pin1=4;
int rm_pin2=5;

int weapon_pin=6;

int ch1;  
int ch4;
int ch5;

int delay_one = 50;

void forward()                      
{
  digitalWrite(lm_pin1, 1);
  digitalWrite(lm_pin2, 0);
  digitalWrite(rm_pin1, 1);
  digitalWrite(rm_pin2, 0);
  delay(delay_one);
}

void reverse()                      
{
  digitalWrite(lm_pin1, 0);
  digitalWrite(lm_pin2, 1);
  digitalWrite(rm_pin1, 0);
  digitalWrite(rm_pin2, 1);
    delay(delay_one);

}
void left()
{
  digitalWrite(lm_pin1, 0);
  digitalWrite(lm_pin2, 1);
  digitalWrite(rm_pin1, 1);
  digitalWrite(rm_pin2, 0);
    delay(delay_one);
}
void right()
{
  digitalWrite(lm_pin1, 1);
  digitalWrite(lm_pin2, 0);
  digitalWrite(rm_pin1, 0);
  digitalWrite(rm_pin2, 1);
    delay(delay_one);

}
void STOP()
{
  digitalWrite(lm_pin1, 0);
  digitalWrite(lm_pin2, 0);
  digitalWrite(rm_pin1, 0);
  digitalWrite(rm_pin2, 0);
}

void setup() {
  Serial.begin(115200);
  pinMode(ch1_pin, INPUT);
  pinMode(ch4_pin,INPUT);
  pinMode(ch5_pin,INPUT);

  pinMode(lm_pin1,OUTPUT);
  pinMode(lm_pin2,OUTPUT);
  pinMode(rm_pin1,OUTPUT);
  pinMode(rm_pin2,OUTPUT);

  pinMode(weapon_pin,OUTPUT);
}

void loop() {
  ch1 = pulseIn (ch1_pin,HIGH);
  ch4 = pulseIn (ch4_pin,HIGH);
  ch5 = pulseIn (ch5_pin,HIGH);
// Serial.println(ch4);

  //weapon , channel5
  if (ch5<1100)
  {
    digitalWrite(weapon_pin, 0);
//    Serial.println("weapon off");
  }
  else{
    digitalWrite(weapon_pin, 1);
    Serial.println("weapon on");
  }


  //stop
  if(   (ch1 < 1600 && ch1 > 1400) &&  (ch4 < 1550 && ch4 > 1400)      )
  {
    STOP();
    Serial.println("STOP");
  }
  else
  { 
    if (ch1 > 1600)
    {
      reverse();
      Serial.println("reverse");
    }
    else if (ch1 < 1300)
    {
      
      forward();
      Serial.println("forward");
    }


    if (ch4 > 1750)
    {
      right();
      Serial.println("right");
    }
    else if (ch4 < 1300)
    {
      left();
      Serial.println("left");
    }
    
  }
  
  
}
