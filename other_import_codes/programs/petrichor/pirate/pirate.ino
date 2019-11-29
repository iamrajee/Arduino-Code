#include <Servo.h>
Servo myservo;

int pos = 0; 

const int ch1_pin=9; 
const int ch2_pin=10;
const int ch4_pin=11;
const int ch5_pin=6;


//motor
int lm_pin1=2;
int lm_pin2=5;
int rm_pin1=12;
int rm_pin2=13;

int arm_pin1=7;
int arm_pin2=8;
int servo_pin = 3;

int ch1;  
int ch2;
int ch4;
int ch5;

int delay_one = 0;
int servo_delay = 1;
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

void armup()
{
  digitalWrite(arm_pin1, 1);
  digitalWrite(arm_pin2, 0);
}

void armdown()
{
  digitalWrite(arm_pin1, 0);
  digitalWrite(arm_pin2, 1);
}
void armstop()
{
  digitalWrite(arm_pin1, 0);
  digitalWrite(arm_pin2, 0);
}

void setup() {
  Serial.begin(115200);
  myservo.attach(servo_pin);
  myservo.write(0);              
  delay(2000);
  
  pinMode(ch1_pin, INPUT);//9
  pinMode(ch2_pin,INPUT);//10
  pinMode(ch4_pin,INPUT);//11
  pinMode(ch5_pin,INPUT);//6

  pinMode(lm_pin1,OUTPUT);//2
  pinMode(lm_pin2,OUTPUT);//12
  pinMode(rm_pin1,OUTPUT);//4
  pinMode(rm_pin2,OUTPUT);//5

  pinMode(arm_pin1,OUTPUT);//6
  pinMode(arm_pin2,OUTPUT);//7
}

void loop() {
  ch1 = pulseIn (ch1_pin,HIGH);
  ch2 = pulseIn (ch2_pin,HIGH);
  ch4 = pulseIn (ch4_pin,HIGH);
  ch5 = pulseIn (ch5_pin,HIGH);
 Serial.print(ch1);
 Serial.print(",");
 Serial.println(ch2);
// Serial.println(ch4);

//-------------------------------------ARM-------------------------//
    if (ch4 > 1700)
    {
      armup();
      Serial.println("arm up");
    }
    else if (ch4 < 1300)
    {
       armdown();
       Serial.println("arm down");
    }
    else
    {
       armstop();
       Serial.println(",arm stop");
    }
//-------------------------------------SERVO-------------------------//
// Serial.println(ch5);
  //arm , channel5
  if (ch5<1100)
  {
      myservo.write(0);              
      delay(servo_delay);
      Serial.print("close,");
  }
  else if (ch5>1700){

       myservo.write(180);              
        delay(servo_delay);
      Serial.println("open");
  }

//-------------------------------------NAVIGATION-------------------------//
 if(   (ch1 < 1550 && ch1 > 1400) &&  (ch2 < 1500 && ch2 > 1350)      )
  {
    STOP();
    Serial.print("STOP");
  }
  else if(ch1 < 1300 && ch2 < 1250)
  {
    right();
    Serial.println("RIGHT");    
  }
  else if(ch1 > 1600 && ch2 > 1600)
  {
    left();
    Serial.println("LEFT");
  }
  else if(ch1 < 1300 && ch2 > 1600)
  {
    forward();
    Serial.println("FORWARD");
  }
  else if(ch1 > 1600 && ch2 < 1300)
  {
    reverse();
    Serial.println("REVERSE");
  }

}

   

