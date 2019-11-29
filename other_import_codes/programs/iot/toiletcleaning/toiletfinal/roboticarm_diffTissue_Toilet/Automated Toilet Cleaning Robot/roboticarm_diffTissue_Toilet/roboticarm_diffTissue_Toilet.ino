



#include <Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);


Servo myservo0;  //tissue servo // create servo object to control a servo
Servo myservo1;  //robotic arm servo // create servo object to control a servo
Servo myservo2;  //robotic arm servo // create servo object to control a servo

                                              /*              WITHOUT ROBOTIC ARM           */
char R, L;                                              


int i,j;
int flag;
int flagPos = 0;

int pos0;                    //tissue servo
int pos1;                    //robotic arm servo
int pos2;                    //robotic arm servo

int lm1=50;                                   //motors_motion
int lm2=51;
int rm1=52;
int rm2=53;

int stainm=6;                                //scrubber_stain
int wfm = 7;                                //waterfloor_stain pump
int toiletBrushM = 8;
int tissueM =9;                               //vaccumfan_tissue
int wtm = 11;                                //watertoilet_stain pump


/*
int lsVal, csVal, rsVal;                     //irsensor_stain
int lsPin = 9;
int csPin = 10;
int rsPin = 11;*/

int triggerpinR = 22;                        //TOultrasonic-R_motion
int echopinR = 23;                           //FROMultrasonic_motion


int triggerpinL = 24; //0;                   //TOultrasonic-L_motion
int echopinL = 25; //1;                     //FROMultrasonic_motion

int triggerpinUp = 26;
int echopinUp = 27; 

int stainsen1pin = 28;                             //stain sensor
int stainsen2pin = 29;
int stainsen3pin = 30;
int stainsen4pin = 31;
int stainsen5pin = 32;
//int stainsen6pin = 33;
int stainsen1Val,stainsen2Val,stainsen3Val,stainsen4Val,stainsen5Val;

int fsPin = 34;                              //frontsensor_obstacle 
int toiletPin = 35;                          //toilet ir sensor

int tissueSensor = 36;                      //tissue sensor pin1
//int tissueSensor2 = 37;                       //tissue sensor pin2
int beep = 37;






int rtdelay = 2600;
int ltdelay = 2600;
int stainfdelay = 500;
int uturnfdelay = 1500;
int smalltdelay = 1;
int tissuefdelay = 500;
int wfmdelay = 100;            //water to floor pump
int stainmdelay = 5000;                                                                  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int wtmdelay = 100;            //water to toilet pump
int toiletBrushMdelay = 5000;                                                            //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int tissueMdelay = 20000;



int triggerpin,echopin; 
unsigned long dR, d90,dL , fixdistR,fixdistL, dFloor, fixdFloor;
unsigned long duration, distance;
int ksquare = 100;

                                       //*d0=r, d180=l*
                                        
int check = 0;

                                      //motors_MOTION 
void forward(){
  //Serial.println("forward() called");
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
}

void left(){
  digitalWrite(lm1,0);
  digitalWrite(lm2,1);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
}

void right(){
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,1);
}

void backward(){
  digitalWrite(lm1,0);
  digitalWrite(lm2,1);
  digitalWrite(rm1,0);
  digitalWrite(rm2,1);
}

void  Stop(){
  digitalWrite(lm1,0);
  digitalWrite(lm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,0);
}
void smallleft()
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,0);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
} 
void smallright()
{
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,0);  
} 
                                            //
                                            
int ultraDistSide(char side)
{
         if(side == R)
         {
          triggerpin = triggerpinR;
          echopin = echopinR;
         }
         else if(side == L)
         {
          triggerpin = triggerpinL;
          echopin = echopinL;
         }
  
  digitalWrite(triggerpin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerpin, LOW);
  
  
  digitalRead(echopin);
  
    duration = pulseIn(echopin, HIGH);
  
    distance = duration*(0.034)/2;
 // Serial.print("distance:");
  //Serial.println(distance);
    return(distance);
}
                                          //
                                          
void checkDist()
{
   dR = ultraDistSide(R);
   dL = ultraDistSide(L); 
   /*
  Serial.print("checked distance:(");
  Serial.print(dR);
  Serial.print(" , ");
  Serial.print(dL); 
  Serial.println(" ) ");
  */                                                              //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
}

/*void decideDirection()
{
         if(dR <= dL )
         {
          backward();
          delay(300);
          right();
          delay(tdelay);
         }
          else
          {
          backward();
          delay(300);
          left();
          delay(tdelay);
           } 
}*/
                                          //
                                          
int stain()
{
  stainsen1Val = digitalRead(stainsen1pin);
  stainsen2Val = digitalRead(stainsen1pin);
  stainsen3Val = digitalRead(stainsen1pin);
  stainsen4Val = digitalRead(stainsen1pin);
  stainsen5Val = digitalRead(stainsen1pin);
 
if(stainsen1Val + stainsen2Val + stainsen3Val + stainsen4Val + stainsen5Val == 5)
  {
    return(0);
  }
  else
  {
   return(1); 
  }
}
                                          //

void stainCleaning()
{
 forward();
 delay(stainfdelay);                                          //change this
 Stop();
 Serial.println("stainCleaning() ");   
 digitalWrite(wfm,HIGH);
 delay(wfmdelay);
 digitalWrite(wfm,LOW);
 digitalWrite(stainm,HIGH);
 delay(stainmdelay);
 digitalWrite(stainm,LOW);
 
}

void smallLR()
{
     checkDist();

     if((dR - fixdistR)^2 <= ksquare)
     {    
          if(dR > fixdistR )
          {
           smallright();
           Serial.println("small right");
          }
            
          else if(dR < fixdistR)
          {
         // left();
          smallleft();
          Serial.println("small left");
          }
      }

       else if((dL - fixdistL)^2 <= ksquare)
       {    
           if(dL < fixdistL )
           {
           smallright();
           Serial.println("small right");
           }
           
           else if(dL > fixdistL)
           {
        // left();
           smallleft();
           Serial.println("small left");
           }
       }
        
       else
       {
           forward();  
       }       

}
                                            //
                                            
void uturnLR()
{
       backward();
      delay(200);
     if(flag == 0)
       {
        Serial.print(" U-turn left");
        left();
        delay(ltdelay);
        forward();
        delay(uturnfdelay);
        left();
        delay(ltdelay);
        flag = 1;
       }
        
      else if(flag == 1)
      {
       Serial.print(" U-turn right");
       right();
       delay(rtdelay);
       forward();
       delay(uturnfdelay);
       right();
       delay(rtdelay);
       flag = 0;
      }
       
}
                                           //
                                        
int obstacle()
{
      if(digitalRead(fsPin) == 0)
      {
       return 1;
      }
      else
      {
      return 0;
      }
}
                                              //
                                              


void toiletCleaning()                     //remaining with robotic arm
{                                                              //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  /*Serial.println("toiletCleaning() called");
  lcd.println("toiletCleaning() called");
  delay(500);
  lcd.clear();*/
  Stop();

    pos1 = 30;
    pos2 = 150;
    myservo1.write(pos1);
    myservo2.write(pos2);
    delay(2000);
    
    for(i = 0; i<150; i++)
    {
      pos1++;                                       //to 180
      pos2--;                                       // to 0
      myservo1.write(pos1);
      myservo2.write(pos2);
      Serial.println("Taking robotic arm near commod");
      delay(25);
    }
     
    delay(5000);
    
    digitalWrite(wtm,HIGH);        //water toilet pump
    delay(wtmdelay);
    digitalWrite(wtm,LOW);

    digitalWrite(toiletBrushM, HIGH);
    delay(toiletBrushMdelay);
    digitalWrite(toiletBrushM, LOW);
    
    for(j = 0; j<150; j++)
    {
      pos1--;                               //180 to 90
      pos2++;                                //0 to 90
      myservo1.write(pos1);
      myservo2.write(pos2);
      Serial.println("Taking robotic arm away from commod");
      delay(100);
    }
    delay(1000);
    backward(); 
    delay(500); 
    uturnLR();
    digitalWrite(beep,HIGH);
    delay(1000);
    digitalWrite(beep,LOW);
    
    delay(1000);
    
  
}

void tissueCleaning()
{                                                              //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  Serial.println("tissueCleaning() called");
  /*lcd.println("tissueCleaning() called");
  delay(500);
  lcd.clear();*/
  Stop();
  delay(1000);
  forward();
  delay(tissuefdelay);
  Stop();

  
  digitalWrite(tissueM, HIGH);
  delay(tissueMdelay);
  left();
  delay(500);
  right();
  delay(500);
  Stop();
  delay(100);
  digitalWrite(tissueM, LOW);
}
                                
int ultraDistUp()
{                                                              //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  /*Serial.println("ultraDistUp() called");
  lcd.println("ultraDistUp() called");
  delay(500);
  lcd.clear();*/
  digitalWrite(triggerpinUp, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerpinUp, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerpinUp, LOW);
  
  
  digitalRead(echopinUp);
  
  duration = pulseIn(echopinUp, HIGH);
  
  distance = duration*(0.034)/2;
  Serial.print("distance:");
  Serial.println(distance);
  return(distance);
}

void nextPos()
{
  if(flagPos == 0)
  {
    pos0++;
    if(pos0 == 110)
    {
      flagPos = 1;
    }
  }
  else if(flagPos == 1)
  {
    pos0--;
    if(pos0 == 70)
    {
      flagPos = 0;
    }
  }
}

int TissueDecide()
{                                                                 //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    /*Serial.println("TissueDecide() called");
    lcd.println("TissueDecide() called");
    delay(500);
    lcd.clear();*/

    if( digitalRead(tissueSensor) == 0)        //tissue detected
    {
      return(1);
    }
    else                           //no tissue                              
    {
      return(0);
    }
}

int toiletSeat()
{
 if(digitalRead(toiletPin) == 1)
 {
    return(1); 
 } 
 else
 {
  
   return(0);  
 }
}
void setup()  //*****************************************************************************************************************
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Toilet cleaning boat");
  delay(500);
  lcd.clear();

/*
  myservo0.attach(A0);               //tissue arm servo
  pinMode(A0, OUTPUT);
  pos0 = 70;
  myservo0.write(pos0);
  delay(500);
*/


  myservo1.attach(A1);              //robotic arm servo
  myservo2.attach(A2);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pos1 = 30;
  pos2 = 150;
  myservo1.write(pos1);
  myservo2.write(pos2);
  Serial.println("Taking robotic arm to 90");
  delay(2000);

  
  pinMode(triggerpinR, OUTPUT);     //TOultrasonic_motion
  pinMode(echopinR, INPUT);         //FROMultrasonic_motion

  pinMode(triggerpinL, OUTPUT);     //TOultrasonic_motion
  pinMode(echopinL, INPUT);         //FROMultrasonic_motion

  pinMode(triggerpinUp, OUTPUT);     //TOultrasonic_toilet
  pinMode(echopinUp, INPUT);         //FROMultrasonic_toilet

 
  pinMode(toiletPin, INPUT);         //toilet seat
  digitalWrite(toiletPin,LOW);        //initialize with zero

  pinMode(tissueSensor, INPUT);         //tissue ir sensor
  digitalWrite(tissueSensor,HIGH);
  //pinMode(tissueSensor2, INPUT);         //tissue ir sensor
 
  pinMode(lm1,OUTPUT);            //motors_motion
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);

  pinMode(tissueM, OUTPUT);
  pinMode(toiletBrushM, OUTPUT);

  pinMode(stainm,OUTPUT);         //scrubber_stain
  pinMode(wfm,OUTPUT);            //waterfloor_stain 

  pinMode(stainsen1pin,INPUT);           //irsensor_stain
  pinMode(stainsen2pin,INPUT);
  pinMode(stainsen3pin,INPUT);
  pinMode(stainsen4pin,INPUT);
  pinMode(stainsen5pin,INPUT);
  //pinMode(stainsen6pin,INPUT);
  
  digitalWrite(stainsen1pin,HIGH);
  digitalWrite(stainsen2pin,HIGH);
  digitalWrite(stainsen3pin,HIGH);
  digitalWrite(stainsen4pin,HIGH);
  digitalWrite(stainsen5pin,HIGH);
  
  pinMode(fsPin,INPUT);            //frontsensor_obstacle
  pinMode(beep,OUTPUT);            //beep
  digitalWrite(beep,LOW);        //beep
  


  digitalWrite(stainm,LOW);        //scrubber_stain
  digitalWrite(fsPin,HIGH);        //frontsensor_obstacle
  digitalWrite(wfm,LOW);        //water floor pump
  digitalWrite(wtm,LOW);        //water toilet pump
 
}//**********************************************************************************************************************************

void loop()//************************************************************************************************************************
{   
  //i = 0;
  //j = 0;
  while(0)
  {
    pos1 = 30;
    pos2 = 150;
    myservo1.write(pos1);
    myservo2.write(pos2);
    delay(2000);
    
    for(i = 0; i<150; i++)
    {
      pos1++;                                       //to 180
      pos2--;                                       // to 0
      myservo1.write(pos1);
      myservo2.write(pos2);
      Serial.println("Taking robotic arm near commod");
      delay(25);
    }
     
    delay(5000);
    
    //digitalWrite(wtm,HIGH);        //water toilet pump
    //delay(wtmdelay);
    //digitalWrite(wtm,LOW);

    //digitalWrite(toiletBrushM, HIGH);
    //delay(toiletBrushMdelay);
    //digitalWrite(toiletBrushM, LOW);
    
    for(j = 0; j<150; j++)
    {
      pos1--;                               //180 to 90
      pos2++;                                //0 to 90
      myservo1.write(pos1);
      myservo2.write(pos2);
      Serial.println("Taking robotic arm away from commod");
      delay(100);
    }
    delay(1000);
  }
   while(0)
   {

   
    //pos1 = 180;
    //pos2 = 0;

  
    pos1 = 90;
    pos2 = 90;
    //*
    for(i = 0; i<90; i++)
    {
      pos1++;
      pos2--;
    myservo1.write(pos1);
    myservo2.write(pos2);
    Serial.println("Taking robotic arm near commod");
    delay(25);
    }
    //*/
    ///*
   // pos1 = 90;

    delay(1000);
    for(j = 0; j<90; j++)
    {
      pos1--;
      pos2++;
    myservo1.write(pos1);
    myservo2.write(pos2);
    Serial.println("Taking robotic arm near commod");
    delay(100);
    }
    delay(1000);
    //*/
    
   }

   
   if(check == 0)
   {
    checkDist();
   
       while((dR == 0) || (dL == 0))
        {
          forward();
          checkDist();
        }
    
       if(dR>dL)                    //left
        {
          
          flag = 1;
        }
       else if(dR<dL)             //right
        {
          flag = 0;
        }
        else
        {
          forward();
          checkDist();
        }
    //Serial.print("flag:");                                                              //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    //Serial.println(flag);                                                              //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    check = 1; 
   }


                                                                                                                                                           
        checkDist();
        fixdistR = dR;
        fixdistL = dL;

        Serial.print("fixdistR:");
        Serial.println(fixdistR);
    

        Serial.print("fixdistL:");
        Serial.println(fixdistL);
    
         while(obstacle() == 0)                   //No obstacle
         {    //Serial.println("no obstacle");

              if(toiletSeat()== 1)      //toilet seat detected
              {
                 Stop();
                 /*                                                               //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^    
                 delay(2000);
                 Serial.println("N-Obs,Y-toi");
                 lcd.println("N-Obs,Y-toi");
                 delay(500);
                 lcd.clear();
                 */
                 toiletCleaning();
              }
              else                      //no toilet detected
              {

                
                if(TissueDecide() == 1)   //yes tissue
                {
                    Stop();
                    /*delay(2000);                                                              //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                    Serial.println("N-Obs,N-toi,Y-tis");
                    lcd.println("N-Obs,N-toi,Y-tis");
                    delay(500);
                    lcd.clear();*/
                    tissueCleaning();
                }
                else if(TissueDecide() == 0)       //no tissue
                {
                  
                  if(stain() == 1)
                  {
                    Stop();
                    /*delay(2000);                                                              //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                    Serial.println("N-Obs,N-toi,N-tis,Y-sta");
                    lcd.println("N-Obs,N-toi,N-tis,Y-sta");
                    delay(500);
                    lcd.clear();*/
                    stainCleaning();
                  }
                  else
                  {
                    /*Serial.println("N-Obs,N-toi,N-tis,N-sta");
                    lcd.println("N-Obs,N-toi,N-tis,N-sta");
                    delay(500);
                    lcd.clear();*/
                    forward();
                    //smallLR();
                  }
                } 
               
              }
              
         }
      
       //Serial.println("Yes obstacle");
        
       if(toiletSeat() == 1)
       {
           /*Stop();                                                              //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
           delay(2000);
           Serial.println("Y-Obs,Y-toi");
           lcd.println("Y-Obs,Y-toi");
           delay(500);
           lcd.clear();*/
           toiletCleaning();
       }
       else
       {  
          /*Stop();
          delay(2000);
          Serial.println("Y-Obs,N-toi");
          lcd.println("Y-Obs,N-toi");
          delay(500);
          lcd.clear();*/
          uturnLR();
       }
      

}   //*********************************************************************************************************************************                                              
