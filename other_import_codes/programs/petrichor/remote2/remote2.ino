const int chA=11;  //Constant variables relating to pin locations
const int chB=10;
//const int chC=26;
//const int chD=28;
//const int chE=30;
//const int chF=32;
//const int chG=34;
//const int chH=36;

int ch1;  //Varibles to store and display the values of each channel
int ch2;
//int ch3;
//int ch4;
//int ch5;
//int ch6;
//int ch7;
//int ch8;


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  // Set input pins
  pinMode(chA, INPUT);
  pinMode(chB,INPUT);
//  pinMode(chC,INPUT);
//  pinMode(chD,INPUT);
//  pinMode(chE,INPUT);
//  pinMode(chF,INPUT);
//  pinMode(chG,INPUT);
//  pinMode(chH,INPUT);
}

//Main Program
void loop() {
  // read the input channels
  ch1 = pulseIn (chA,HIGH);  //Read and store channel 1
  Serial.print ("Ch1: ");  //Display text string on Serial Monitor to distinguish variables
  Serial.print(ch1);     //Print in the value of channel 1
  Serial.print ("|");
// 
  ch2 = pulseIn (chB,HIGH);
  Serial.print ("Ch2: ");
  Serial.println (ch2);
//  Serial.print ("|");
// 
//  ch3 = pulseIn (chC,HIGH);
//  Serial.print ("Ch3:");
//  Serial.print (ch3);
//  Serial.print ("|");
// 
//  ch4 = pulseIn (chD,HIGH);
//  Serial.print ("Ch4:");
//  Serial.print (ch4);
//  Serial.print ("|");
// 
//  ch5 = pulseIn (chE,HIGH);
//  Serial.print ("Ch5:");
//  Serial.print (ch5);
//  Serial.print ("|");
// 
//  ch6 = pulseIn (chF,HIGH);
//  Serial.print ("Ch6:");
//  Serial.print (ch6);
//  Serial.print ("|");
// 
//  ch7 = pulseIn (chG,HIGH);
//  Serial.print ("Ch7:");
//  Serial.print (ch7);
//  Serial.print ("|");
// 
//  ch8 = pulseIn (chH,HIGH);
//  Serial.print ("Ch8:");
//  Serial.println (ch8);

delay(50);
}
