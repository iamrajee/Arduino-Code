// ============================================ DECLARING ============================================//
char directions[30];
char reshortn[30];
char shortn[30];

int l,c1,c2,c3,r;
int i,j=0;
int k=0;
int objectvalue = 1;
int resetvalue = 0;
// ============================================= PIN =================================================//
int objectpin = 22;
int resetpin = 23;
int ledpin_dry = 13;
int ledpin_final = 12;

int pin_l =2;
int pin_c1=3;
int pin_c2=4;
int pin_c3=5;
int pin_r =6;

int lm1 =  50;
int lm2 =  51;
int rm1 =  52;
int rm2 = 53;



// ============================================= DELAYS =================================================//
int setup_delay   =1000;
int straight_fdelay =1;

//--------- U-TURN(inch_uturn)
int u_stop = 100;
int u_forward = 200;
int u_smallleft_delay = 100;
int u_reverse_delay = 200;

//--------- INCH
int inch_stop    = 100;
int inch_forward = 200 ;

//--------- ALIGN
int align_stop   = 1 ;
int align_forward= 1 ;

int else_forward = 50;

int inch_decide_forward = 200;
int inch_decide_stop = 500;

int object_reverse = 150;

int after_turn = 200;

//int inch_decide_2_way = 150;
//int inch_decide_3_way = 200;

//int tdelay        =275;
//int t2delay       =325;
//int dead_end_delay=900;
//-------------------------------------------------------------------------------------------------------//





// ============================ USFUL FUNCTIONS =====================================================//
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


void reverse()
{
    digitalWrite(lm1,0);
    digitalWrite(lm2,1);
    digitalWrite(rm1,0);
    digitalWrite(rm2,1);
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
    l =digitalRead(pin_l );
    c1=digitalRead(pin_c1);
    c2=digitalRead(pin_c2);
    c3=digitalRead(pin_c3);
    r =digitalRead(pin_r );

    objectvalue = digitalRead(objectpin);

    resetvalue = digitalRead(resetpin);
    
//    Serial.print(l);
//    Serial.print("\t");
//    Serial.print(c1);
//    Serial.print("\t");
//    Serial.print(c2);
//    Serial.print("\t");
//    Serial.print(c3);
//    Serial.print("\t");
//    Serial.print(r);
//    Serial.print("\n");
    
}

void inch()
{
    Stop();
    delay(inch_stop);
    forward();
    delay(inch_forward) ;
    Stop();
    delay(inch_stop);
    readsens();
}

void inch_uturn()
{

    Stop();
    delay(u_stop);
    forward();
    delay(u_forward) ;
    Stop();
    delay(u_stop);


    right();
    while(1)
    {
      readsens(); 
      if(eosens() == 1 && l == 0 && r == 0)
      {
        Stop();
        break;
      }
    }    
    
    
    smallleft();
    delay(u_smallleft_delay);
    reverse();
    delay(u_reverse_delay);
    Stop();

}




void inch_decide()
{
  int flag;
  int l_sum=0;
  int c1_sum=0;
  int c2_sum=0;
  int c3_sum=0;
  int r_sum=0;

  while(1)
  {
    forward();
    readsens();
    if((l==0 && r == 0)||((l==1)&&(c1==1)&&(c2==1)&&(c3==1)&&(r==1)))
    {
      break;
    }
    l_sum+=l;
    c1_sum+=c1;
    c2_sum+=c2;
    c3_sum+=c3;
    r_sum+=r;
  }
  forward();
  delay(inch_decide_forward); 
  Stop();
  delay(inch_decide_stop);
  if(l_sum != 0){
    l=1;
  }
  if(c1_sum != 0){
    c1=1;
  }
  if(c3_sum != 0){
    c3=1;
  }
  if(r_sum != 0){
    r=1;
  }
  c2=1;
}





void align()
{
//    Stop();
//    delay(align_stop);
    forward();
//    delay(align_forward);
//    readsens();/
}

void printing(char prtdirection[])
{
    for(i=0;prtdirection[i]!='E';i++)
    {
        Serial.print(prtdirection[i]);
        Serial.print("\t");
    }
    Serial.print(prtdirection[i]);
    Serial.print("\n");
    delay(2000);
}

void turn_eosen_right()
{
  while(1)
  {
    readsens();
    if(c1 == 0 && c2 == 0){
      break;
    }
  }
  readsens();
  while(1)
  {
//    readsens();/
    if(eosens() == 1 && l == 0 && r == 0)
    {
      Stop();
      break;
    }
  }
  delay(after_turn);
}


void turn_eosen_left()
{
  while(1)
  {
    readsens();
    if(c2 == 0 && c3 == 0){
      break;
    }
  }
  readsens();
  while(1)
  {
    if(eosens() == 1 && l == 0 && r == 0)
    {
      Stop();
      break;
    }
  }

  delay(after_turn);
}

void led_blink()
{
  digitalWrite(ledpin_dry,1);
  delay(500);
  digitalWrite(ledpin_dry,0);
  delay(500);
}


// ============================================= SETUP =================================================//
void setup()
{
    Serial.begin(9600);
    delay(setup_delay);
    i=0;

    pinMode(objectpin ,INPUT);
    pinMode(resetpin ,INPUT);

    
    pinMode( lm1 ,OUTPUT);
    pinMode( lm2 ,OUTPUT);
    pinMode( rm1 ,OUTPUT);
    pinMode( rm2 ,OUTPUT);
    pinMode(pin_l ,INPUT);
    pinMode(pin_c1,INPUT);
    pinMode(pin_c2,INPUT);
    pinMode(pin_c3,INPUT);
    pinMode(pin_r ,INPUT);
    pinMode(ledpin_dry,OUTPUT);
    pinMode(ledpin_final,OUTPUT);
}


// ============================================= LOOP =================================================//
void loop()
{
    readsens();


    if (resetvalue == 1)
    {
       Stop();
    }
    else if (objectvalue == 0)
    {
        right();
        turn_eosen_right();

        delay(1000);
        reverse();
        delay(object_reverse);
    }
    //----------------------FOUR LINE FOLLOWING CASES---------------------------------------------//
    else if((l==0)&&(c1==0)&&(c2==1)&&(c3==0)&&(r==0))
    {
        forward();// ******* ideal straight ********
//        delay(5);/
    }
    else if(((l==0)&&(c1==1)&&(c2==0)&&(c3==0)&&(r==0))||((l==0)&&(c1==1)&&(c2==1)&&(c3==0)&&(r==0)))
    {
        smallleft();//******** small left ********
//        Stop();
    }
    else if(((l==0)&&(c1==0)&&(c2==0)&&(c3==1)&&(r==0))||((l==0)&&(c1==0)&&(c2==1)&&(c3==1)&&(r==0)))
    {
        smallright();//******** small right ********
        //left();
//        Stop();/
    }
    else if((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==0))
    {
        inch_uturn();             //******** U-TURN ********
        directions[i]='U';
//        Serial.println(directions[i]);
        i++;
    }//=============================== REST ALL CASES T,E,4way,L,L-S,R,R-S ====================================//
    else if (((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==1)) != 1)// if(((l==1)&&(c1==1))||((c3==1)&&(r==1))) 
    {

//        align();//give unique delay
        inch_decide();
        //********* R , R-S ************* 
        if(((l==0)&&(c1==0)&&(c2==1)&&(c3==1)&&(r==1))||((l==0)&&(c1==1)&&(c2==1)&&(c3==1)&&(r==1)))
        {
//            inch();// Delay will change with Volt(SIMILIARLY ALL BELOW CASES)
            readsens();
            if((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==0)) // R ONLY
            {
                right();
                turn_eosen_right();
            }
            else if((l==0)&&(r==0)&&(eosens()==1))    // R-S
            {
                directions[i]='R';
//                Serial.println(directions[i]);
                i++;
                right();
                turn_eosen_right();
            }
        }
       //********* L , L-S *************
       else if(((l==1)&&(c1==1)&&(c2==1)&&(c3==0)&&(r==0))||((l==1 )&&(c1==1)&&(c2==1)&&(c3==1)&&(r==0)))             
        {
//            inch();
            readsens();
             //after inch
            if((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==0))    // L ONLY                                                       //7
            {
                left();
                turn_eosen_left();
            }
            else if((l==0)&&(r==0)&&(eosens()==1))        // L-S                                                                 //8
            {
                directions[i]='S';                       
//                Serial.println(directions[i]);
                i++;
                forward();
                delay(straight_fdelay);
            }
        }
       // ******* T , 4way, E **********
       else if((l==1)&&(c1==1)&&(c2==1)&&(c3==1)&&(r==1))                                               
        {
//            inch();
            readsens();
            //after inch
            if((l==0)&&(r==0)&&(eosens()==1))  //******* 4way *********                                                                         //9
            {
                directions[i]='R';
//                Serial.println(directions[i]);
                i++;
                right();
                turn_eosen_right();
            }
            else if((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==0))  // ******* T *******                                                               //10
            {
                directions[i]='R';
//                Serial.println(directions[i]);
                i++;
                right();
                turn_eosen_right();
            }
            else if((l==1)&&(c1==1)&&(c2==1)&&(c3==1)&&(r==1)) // ******* E *******                                                //11
            {
                directions[i]='E';
//                Serial.println(directions[i]);
//                Serial.println("directions=");
//                printing(directions);
                
                Stop();
                digitalWrite(ledpin_dry,1);
                delay(20000);
                digitalWrite(ledpin_dry,0);
                
                replacement(directions);
                               
            }
        }
    }
    else
    {
      right();
      //forward();
//      delay(else_forward);
//      Serial.println("else_forward");
    }
}


//================================ replacement ================================================//
void replacement(char shortn[])
{
    for(i=0;shortn[i]!='E';i++)
    {
        if(shortn[i]=='U')
        {
            if((shortn[i-1]=='S')&&(shortn[i+1]=='R'))            //SUR BY XXL
            {
                shortn[i-1]='x';
                shortn[i]='x';
                shortn[i+1]='L';
            }
            
            else if((shortn[i-1]=='R')&&(shortn[i+1]=='R'))       //RUR BY XXS
            {
                shortn[i-1]='x';
                shortn[i]='x';
                shortn[i+1]='S';
            }
            else if((shortn[i-1]=='R')&&(shortn[i+1]=='S'))       //RUS BY XXL
            {
                shortn[i-1]='x';
                shortn[i]='x';
                shortn[i+1]='L';
            }
            else if((shortn[i-1]=='L')&&(shortn[i+1]=='R'))      //LUR BY XXU
            {
                shortn[i-1]='x';
                shortn[i]='x';
                shortn[i+1]='U';
            }
            else if((shortn[i-1]=='R')&&(shortn[i+1]=='L'))      //RUL BY XXU
            {
                shortn[i-1]='x';
                shortn[i]='x';
                shortn[i+1]='U';
            }
            else if((shortn[i-1]=='S')&&(shortn[i+1]=='L'))      //SUL BY XXU
            {
                shortn[i-1]='x';
                shortn[i]='x';
                shortn[i+1]='U';
            }
        }
    }
    
    j=0;
    for(i=0;shortn[i]!='E';i++)
    {
        if(shortn[i]!='x')
        {
            reshortn[j]=shortn[i];
            j++;
        }
    }
    
    reshortn[j]='E';
//    printing(reshortn);
//    delay(1000);
    
    for(i=0;reshortn[i]!='E';i++)
    {
        if(reshortn[i]=='U')
        {
            replacement(reshortn);
        }
    }
//      Serial.println("reshortn=");
      printing(reshortn);
    final();
}
    


// =================================================== DECISIONS ============================================//
void decisions()                                                                                                                                //function 2 decisions
{
    
    if(reshortn[k]=='S')
    {
        forward();
        delay(straight_fdelay);
    }
    
    else if(reshortn[k]=='L')
    {
//      Serial.println("L");
        left();
        turn_eosen_left();
    }
    
    else if(reshortn[k]=='R')
    {
        right();
        turn_eosen_right();
    }
    k++;
}                                                                                                                              



// =================================================== FINAL ============================================//
void final()                                                                                                                                      //function 3 final    
{
    while(1)
    {
      readsens();

      if (resetvalue == 1)
      {
       Stop();
      }
      //----------------------FOUR LINE FOLLOWING CASES (NO DECISION REQUIRED)---------------------------------------------//
      else if((l==0)&&(c1==0)&&(c2==1)&&(c3==0)&&(r==0))
      {
        forward();// ******* ideal straight ********
      }
      else if(((l==0)&&(c1==1)&&(c2==0)&&(c3==0)&&(r==0))||((l==0)&&(c1==1)&&(c2==1)&&(c3==0)&&(r==0)))
      {
        smallleft();//******** small left ********
      }
      else if(((l==0)&&(c1==0)&&(c2==0)&&(c3==1)&&(r==0))||((l==0)&&(c1==0)&&(c2==1)&&(c3==1)&&(r==0)))
      {
        smallright();//******** small right ********
      }
//      else if((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==0)) (SHOULD WE GIVE FORWARD?)
//      {
//        inch();             //******** U-TURN ********
//        right();
//        turn_eosen();
//        Stop();
//        delay(u_stop_delay);
//        smallleft();
//        delay(u_smallleft_delay);
//        reverse();
//        delay(u_reverse_delay);
//        Stop();
//        directions[i]='U';
//        Serial.println(directions[i]);
//        i++;
//      }//=============================== REST ALL CASES T,E,4way,L,L-S,R,R-S ====================================//
      else if (((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==1)) != 1)// if(((l==1)&&(c1==1))||((c3==1)&&(r==1))) 
      {

        //align();//give unique delay
        inch_decide();
        //********* R , R-S ************* 
        if(((l==0)&&(c1==0)&&(c2==1)&&(c3==1)&&(r==1))||((l==0)&&(c1==1)&&(c2==1)&&(c3==1)&&(r==1)))
        {
            //inch();// Delay will change with Volt(SIMILIARLY ALL BELOW CASES)
            readsens();
            if((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==0)) // R ONLY
            {
                right();
                turn_eosen_right();
            }
            else if((l==0)&&(r==0)&&(eosens()==1))    // R-S
            {
                decisions();
            }
        }
       //********* L , L-S *************
       else if(((l==1)&&(c1==1)&&(c2==1)&&(c3==0)&&(r==0))||((l==1 )&&(c1==1)&&(c2==1)&&(c3==1)&&(r==0)))             
        {
//            inch();
            readsens();
             //after inch
            if((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==0))    // L ONLY                                                       //7
            {
                left();
                turn_eosen_left();
            }
            else if((l==0)&&(r==0)&&(eosens()==1))        // L-S                                                                 //8
            {
                decisions();
            }
        }
       // ******* T , 4way, E **********
       else if((l==1)&&(c1==1)&&(c2==1)&&(c3==1)&&(r==1))                                               
        {
//            inch();
            readsens();
            //after inch
            if((l==0)&&(r==0)&&(eosens()==1))  //******* 4way *********                                                                         //9
            {
                decisions();
            }
            else if((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==0))  // ******* T *******                                                               //10
            {
                decisions();
            }
            else if((l==1)&&(c1==1)&&(c2==1)&&(c3==1)&&(r==1)) // ******* E *******                                                //11
            {
                Stop();
                while(1)
                {
                   Stop();
                   led_blink();
//                   Serial.println("led_blink");
                }
                               
            }
        }
      }
      else
      {
        right();
       }
    }
}
