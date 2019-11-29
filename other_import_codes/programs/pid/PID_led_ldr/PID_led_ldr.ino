/********************************************************
 * PID Basic Example
 * Reading analog input 0 to control analog PWM output 3
 ********************************************************/

#include <PID_v1.h>

#define PIN_INPUT A0
#define PIN_OUTPUT 8

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
double Kp=2000, Ki=1, Kd=2000;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  Serial.begin(9600);
  //initialize the variables we're linked to
  Input = analogRead(PIN_INPUT);
  Setpoint = 210;

  //turn the PID on
  myPID.SetMode(AUTOMATIC);
  myPID.SetTunings(Kp,Ki,Kd);
}

void loop()
{
  Input = map(analogRead(PIN_INPUT),0,1023,255,0);
  myPID.Compute();
  analogWrite(PIN_OUTPUT, Output);
  Serial.print(Input);
  Serial.print(" ");
//  Serial.print(Output);
//  Serial.print(" ");
  Serial.println(Setpoint);
}


