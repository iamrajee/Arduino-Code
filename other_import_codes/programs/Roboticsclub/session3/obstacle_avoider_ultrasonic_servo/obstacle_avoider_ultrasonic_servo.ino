//----------------Libraries--------------------------------------//
#include <Servo.h>       //<-------------Changes
Servo myservo;           

//---------------Global declaration---------------------------------------//
int lm_pin1=2;                      //motor
int lm_pin2=3;
int rm_pin1=4;
int rm_pin2=5;
int turn_delay= 500;
int min_dist = 10;


int servopin = 6;                     //servo
int pos = 0; //servo position
int delay_per_degree = 15;

int triggerpin = 7;                   //ultrasonic
int echopin = 8;
int distance,t;
int f_dist,l_dist, r_dist;


//--------------function defination------------------------------------------//
void forward()
{
  digitalWrite(lm_pin1, 1);
  digitalWrite(lm_pin2, 0);
  digitalWrite(rm_pin1, 1);
  digitalWrite(rm_pin2, 0);
}
void turn_left()
{
  digitalWrite(lm_pin1, 0);
  digitalWrite(lm_pin2, 1);
  digitalWrite(rm_pin1, 1);
  digitalWrite(rm_pin2, 0);

  delay(turn_delay);
  Stop();
}
void turn_right()
{
  digitalWrite(lm_pin1, 1);
  digitalWrite(lm_pin2, 0);
  digitalWrite(rm_pin1, 0);
  digitalWrite(rm_pin2, 1);

  delay(turn_delay);
  Stop();
  
}

void Stop()
{
  digitalWrite(lm_pin1, 0);
  digitalWrite(lm_pin2, 0);
  digitalWrite(rm_pin1, 0);
  digitalWrite(rm_pin2, 0);
}
//-----------------Changes---------------------//
void move_servo(int angle1,int angle2)
{
  int temp_delay = delay_per_degree*abs(angle1-angle2);
  myservo.write(angle2);
  delay(temp_delay); 
}

int find_ultra_distance()
{

  digitalWrite(triggerpin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerpin, LOW);
  
  
  digitalRead(echopin);
  
  t = pulseIn(echopin, HIGH);
  
  distance = t*(0.034)/2;
  return distance;
}


//----------------setup-------------------------------------------------------//
void setup() {
  Serial.begin(9600);

  myservo.attach(servopin);//<-------------Changes
  myservo.write(90);
  delay(2000);
    
  pinMode(rm_pin1, OUTPUT);//motor
  pinMode(rm_pin2, OUTPUT);
  pinMode(lm_pin1, OUTPUT);
  pinMode(lm_pin2, OUTPUT);

  pinMode(triggerpin, OUTPUT); //TO ULTRA SONIC SENSOR
  pinMode(echopin, INPUT);   //FORM ULTRA SONIC SENSOR
}


//-----------------loop-------------------------------------------------------//
void loop() {
  f_dist = find_ultra_distance();
  
  if(f_dist < min_dist)
  {
    Stop();
    move_servo(90,0);
    l_dist = find_ultra_distance();
    move_servo(0,180);
    r_dist = find_ultra_distance();
    move_servo(180,90);
    if(l_dist < r_dist)
    {
      turn_right();
    }
    else
    {
      turn_left();
    }
  }
  else
  {
    forward();
  }
  
}


