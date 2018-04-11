//robot code

int lm1 = 24;
int lm2 = 25;
int rm1 = 0;
int rm2 = 1;
int g1 = 13;
int g2 = 14;
int a1 = 15;
int a2 = 16;

void Forward(){
  digitalWrite(lm1, 1);
  digitalWrite(lm2, 0);
  digitalWrite(rm1, 1);
  digitalWrite(rm2, 0);
}

void Backward(){
  digitalWrite(lm1, 0);
  digitalWrite(lm2, 1);
  digitalWrite(rm1, 0);
  digitalWrite(rm2, 1);
}

void Stop(){
  digitalWrite(lm1, 0);
  digitalWrite(lm2, 0);
  digitalWrite(rm1, 0);
  digitalWrite(rm2, 0);
}

void Right(){
  digitalWrite(lm1, 1);
  digitalWrite(lm2, 0);
  digitalWrite(rm1, 0);
  digitalWrite(rm2, 1);
}

void Left(){
  digitalWrite(lm1, 0);
  digitalWrite(lm2, 1);
  digitalWrite(rm1, 1);
  digitalWrite(rm2, 0);
}




void gOpen(){
  digitalWrite(g1, 1);
  digitalWrite(g2, 0);
  digitalWrite(a1, 0);
  digitalWrite(a2, 0);
}
void gClose(){
  digitalWrite(g1, 0);
  digitalWrite(g2, 1);
  digitalWrite(a1, 0);
  digitalWrite(a2, 0);

}
void aUp(){
  digitalWrite(g1, 0);
  digitalWrite(g2, 0);
  digitalWrite(a1, 1);
  digitalWrite(a2, 0);

}
void aDown(){
  digitalWrite(g1, 0);
  digitalWrite(g2, 0);
  digitalWrite(a1, 0);
  digitalWrite(a2, 1);

}
void Pause(){
  digitalWrite(g1, 0);
  digitalWrite(g2, 0);
  digitalWrite(a1, 0);
  digitalWrite(a2, 0);
}
void setup(){
  Serial.begin(9600);
 
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  
}

void loop(){
  while(!Serial.available());
  
  char c = Serial.read();
  
  Serial.println();
  
  if(c == 'f'){
    Pause();
    Forward();
  }
  
  if(c == 'b'){
    Pause();
    Backward();
  }
  
  if(c == 's'){
    Stop();
  }
  
  if(c == 'l'){
    Pause();
    Left();
  }
  
  if(c == 'r'){
    Pause();
    Right();
  }
  
  
  
  
  
  if(c == 'c'){
    Stop();
    gClose();
  }
  
  if(c == 'o'){
    Stop();
    gOpen();
  }
  
  if(c == 'u'){
    Stop();
    aUp();
  }
  
  if(c == 'd'){
    Stop();
    aDown();
  }
  
  if(c == 'p'){
    Pause();
  }
  
}


