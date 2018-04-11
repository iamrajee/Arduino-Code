#include <LiquidCrystal.h>
char directions[30];

LiquidCrystal lcd(12,11,5,4,3,2);

int rm1=0;
int rm2=1;
int lm1=24;
int lm2=25;
int l,c1,c2,c3,r;
int i;
int tdelay=1000;
int fdelay=500;

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
    delay(500) ;
    Stop();
    delay(100);
    lcd.clear();
    readsens();
}

void align()
{
    Stop();
    delay(500);
    forward();
    delay(60);
    lcd.clear();
    readsens();
}

void printing(char prtdirection[])
{
    lcd.clear();
    for(i=0;prtdirection[i]!='E';i++)
    {
        lcd.print(prtdirection[i]);
    }
    delay(2000);
}

void setup()
{
    lcd.begin(16,2);
    lcd.print("MSR with LHR");
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
    lcd.clear();
    readsens();
    lcd.clear();
    
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
    else if((l==1)&&(c1==1)&&(c2==1)&&(c3==1)&&(r==1))                                                                //dead end
    {
        lcd.print("U Turn");
        left();
        delay(2000);
        directions[i]='U';                                                                            //store in array
        i++;
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
                directions[i]='S';                        //store in array
                i++;
                forward();
                delay(fdelay);
            }
        }
              //leftonly and leftstraight
        else if(((l==0)&&(c1==0)&&(c2==0)&&(c3==1)&&(r==1))||((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==1)))    //S,L                
        {
            lcd.print("Left/str n lft?");
            inch();
                //after inch
            if((l==1)&&(c1==1)&&(c2==1)&&(c3==1)&&(r==1))                                                                      //7
            {
                lcd.print("Left");
                left();
                delay(tdelay);
            }
            else if((l==1)&&(r==1)&&(eosens()==1))                                                                            //8
            {
                lcd.print("Left");
                directions[i]='L';                        //store in array
                i++;
                left();
                delay(tdelay);
            }
        }
            //t intersection, 4way, end of the maze
        else if((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==0))            //T,E,4-W                                                  
        {
            lcd.print("T/END/4");
            inch();
                //after inch
            if((l==1)&&(r==1)&&(eosens()==1))                                                                                //9
            {
                lcd.print("4 Way");
                directions[i]='L';                        //store in array
                i++;
                left();
                delay(tdelay);
            }
            else if((l==1)&&(c1==1)&&(c2==1)&&(c3==1)&&(r==1))                                                              //10
            {
                lcd.print("T-int");
                directions[i]='L';                        //store in array
                i++;
                left();
                delay(tdelay);
            }
            else if((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==0))                                                              //11
            {
                lcd.print("End of Maze");
                directions[i]='E';                       //store in array
                printing(directions);
                while(1)
                {
                    Stop();
                }
            }
        }
    }
}
