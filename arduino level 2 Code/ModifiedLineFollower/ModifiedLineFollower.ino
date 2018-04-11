#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

int rm1=0;
int rm2=1;
int lm1=24;
int lm2=25;
int l,c1,c2,c3,r;
int i;
int tdelay=1100;
int fdelay=400;
int count=0;
unsigned long time;
unsigned long time2;
int k=0;
int z=1;

void Stop()
{
    digitalWrite(lm1,0);
    digitalWrite(lm2,0);
    digitalWrite(rm1,0);
    digitalWrite(rm2,0);
}

void forward()
{
    digitalWrite(lm1,1);
    digitalWrite(lm2,0);
    digitalWrite(rm1,1);
    digitalWrite(rm2,0);
}

void right()
{
    digitalWrite(lm1,1);
    digitalWrite(lm2,0);
    digitalWrite(rm1,0);
    digitalWrite(rm2,1);
}

void left()
{
    digitalWrite(lm1,0);
    digitalWrite(lm2,1);
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

void smallleft()
{
    digitalWrite(lm1,0);
    digitalWrite(lm2,0);
    digitalWrite(rm1,1);
    digitalWrite(rm2,0);
}


void readsens()
{
    l=digitalRead(26);
    c1=digitalRead(27);
    c2=digitalRead(28);
    c3=digitalRead(29);
    r=digitalRead(30);
    lcd.print(l);
    lcd.print("--");
    lcd.print(c1);
    lcd.print("--");
    lcd.print(c2);
    lcd.print("--");
    lcd.print(c3);
    lcd.print("--");
    lcd.print(r);
    lcd.print("--");
    delay(10);
}

void inch()
{
    lcd.print("Inch Function");
    Stop();
    delay(100);
    forward();
    delay(700) ;
    Stop();
    delay(100);
    lcd.clear();
    readsens();
}

void inch2()
{
    lcd.print("Inch Function");
    Stop();
    delay(100);
    forward();
    delay(900) ;
    Stop();
    delay(100);
    lcd.clear();
    readsens();
}

int eosens()
{
    readsens();
    if(((c1+c2+c3)==1)||((c1+c2+c3)==2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void align()
{
    Stop();
    delay(300);
    forward();
    delay(30);
    lcd.clear();
    readsens();
}


void setup()
{
    Serial.begin(9600);
    lcd.begin(16,2);
    lcd.print("Line Follower");
    delay(500);
    lcd.clear();
    i=0;
    pinMode(lm1,OUTPUT);
    pinMode(lm2,OUTPUT);
    pinMode(rm1,OUTPUT);
    pinMode(rm2,OUTPUT);
    pinMode(26,INPUT);
    pinMode(27,INPUT);
    pinMode(28,INPUT);
    pinMode(29,INPUT);
    pinMode(30,INPUT);
}

void loop()
{
    time = millis();
    lcd.clear();
    readsens();
    lcd.clear();
    
    char c = Serial.read();
  
    Serial.println();
    
    if(c=='n')
    {
        z=0;
    }
    if(c=='m')
    {
        z=1;
    }
    
    if(z==1)
    {
    //FOUR LINE FOLLOWING CASES
    if((l==1)&&(c1==1)&&(c2==0)&&(c3==1)&&(r==1))                                                                //ideal straight
    {
        lcd.print("Forward");
        forward();
    }
    else if(((l==1)&&(c1==0)&&(c2==1)&&(c3==1)&&(r==1))||((l==1)&&(c1==0)&&(c2==0)&&(c3==1)&&(r==1)))            //small left
    {
        lcd.print("Left");
        smallleft();
    }
    else if(((l==1)&&(c1==1)&&(c2==1)&&(c3==0)&&(r==1))||((l==1)&&(c1==1)&&(c2==0)&&(c3==0)&&(r==1)))              //small right
    {
        lcd.print("Right");
        smallright();
    }
    
    else if(((l==0)&&(c1==0))||((c3==0)&&(r==0)))            //align FOR LINE FOLLOWING CASE
    {
      align();
        
            //rightonly and rightstraight 
        if(((l==1)&&(c1==1)&&(c2==0)&&(c3==0)&&(r==0))||((l==1)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==0)))    //S,R                    
        {
            lcd.print("RT/Strt n rt?");
            inch();
                //after inch
            if((l==1)&&(c1==1)&&(c2==1)&&(c3==1)&&(r==1))                                                                  //5  
            {
                lcd.print("Right");
                right();
                delay(tdelay);
            }
            else if((l==1)&&(r==1)&&(eosens()==1))                                                                          //6
            {
                lcd.print("Straight");
                forward();
                delay(fdelay);
            }
            /*else if((l+c1+c2+c3+r)==4)
            {
                lcd.print("Right");
                right();
                delay(tdelay-200);
            }*/
                
        }
              //leftonly and leftstraight
        else if(((l==0)&&(c1==0)&&(c2==0)&&(c3==1)&&(r==1))||((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==1)))    //S,L                
        {
            lcd.print("Left/str n lft?");
            inch();
                //after inch
            if(((l==1)&&(c1==1)&&(c2==1)&&(c3==1)&&(r==1))||(l+c1+c2+c3+r==1))                                                                      //7
            {
                lcd.print("Left");
                left();
                delay(tdelay);
            }
            else if((l==1)&&(r==1)&&(eosens()==1))                                                                            //8
            {
                lcd.print("Straight");
                forward();
                delay(fdelay);
            }
            /*else if((l+c1+c2+c3+r)==4)
            {
                lcd.print("Left");
                right();
                delay(tdelay-200);
            }*/
        }
        
        else if((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==0))
        {
            if(count==2)
            {
                inch2();
            }
            else
            {
                 inch();
            }
            if((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==0))
            {
                while(1)
                {
                    Stop();
                    lcd.clear();
                    lcd.print(count+2);
                    lcd.print(" ");
                    if(k==0)
                    {
                        time2=time;
                        k++;
                    }
                    lcd.print(time2);
                  
               }
            }
            else
            {    
                count++;
                forward();
                delay(fdelay);
            }
        }
    }
    }
    else
    {
        Stop();
    }
}
    
    
