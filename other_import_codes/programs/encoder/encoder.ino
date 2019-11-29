/* Read Quadrature Encoder
   Connect Encoder to Pins encoder0PinA, encoder0PinB, and +5V.

   Sketch by max wolf / www.meso.net
   v. 0.1 - very basic functions - mw 20061220

*/

int val;
int encoder0PinA = 3;
int encoder0PinB = 4;
long encoder0Pos = 0;
int encoder0PinALast = LOW;
int n = LOW;
int m1=5;
int m2=6;
int T = 500;
int Speed = 0.8*T;
int SPFC = 190;
int SPBC = 160;

void setup() {
  pinMode (encoder0PinA, INPUT);
  pinMode (encoder0PinB, INPUT);
  pinMode (m1, OUTPUT);
  pinMode (m2, OUTPUT);
  Serial.begin (9600);
}

void encoder(){
  //Speed = map(encoder0Pos,0,105,500,1000)*0.001*T;
  n = digitalRead(encoder0PinA);
  if ((encoder0PinALast == LOW) && (n == HIGH)) {
    if (digitalRead(encoder0PinB) == LOW) {
      encoder0Pos--;
    } else {
      encoder0Pos++;
    }
    Serial.println (encoder0Pos);
    //Serial.println ("/");
  }
  encoder0PinALast = n;
}
void b(){
 digitalWrite(m1, 1);
  digitalWrite(m2, 0); 
}
void f(){
 digitalWrite(m1, 0);
  digitalWrite(m2, 1); 
}

void s(int d){
  encoder0Pos = 0;
  digitalWrite(m1, 0);
  digitalWrite(m2, 0);
  delay(d);
}

void fstep(int nstep){
  int t = encoder0Pos;
  f();
  while(encoder0Pos-t<nstep){
//    f();
//    delay(Speed);
//    s(T-Speed);
   encoder();
  }
}
void bstep(int nstep){
  int t = encoder0Pos;
  b();
  while(t-encoder0Pos<nstep){
//    b();
//    delay(Speed);
//    s(T-Speed);
   encoder();
  }
}

void loop() {
  fstep(1*SPFC);
  s(3000);
  bstep(1*SPBC);
  s(3000);
}
