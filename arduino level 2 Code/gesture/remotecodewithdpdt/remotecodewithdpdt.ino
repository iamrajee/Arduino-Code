//Remote code

const int xpin=A0; // x axis of the accelerometer
const int ypin=A1; // y axis of the accelerometer
//int a,b; // a and b are global variables
int g1 =2;
int g2 = 3;
int a1 = 4;
int a2 = 5;

void setup()
{
    Serial.begin(9600); // initialize the serial communications
    pinMode(g1, INPUT);
    pinMode(g2, INPUT);
    pinMode(a1, INPUT);
    pinMode(a2, INPUT);
}

void loop()
{
    int x = analogRead(xpin);
    int y = analogRead(ypin);
    int x1 = digitalRead(g1);
    int x2 = digitalRead(g2);
    int x3 = digitalRead(a1);
    int x4 = digitalRead(a2);
    if((x>=380)&&(y>=380)&&(x<=440)&&(y<=440))
    {
        Serial.println('s');// stop
    }
    if(y<380)
    {
        Serial.println('f');// forward
    }
    if(y>440)
    {
        Serial.println('b'); // backward
    }
    if(x<380)
    {
        Serial.println('r'); // right
    }
    if(x>440)
    {
        Serial.println('l'); // left
    }
    
    
    
    if(x1 == 0 && x2 == 0 && x3 == 0 && x4 == 0)
    {
        Serial.println('p'); // 
    }
    if(x1 == 1 && x2 == 0 && x3 == 0 && x4 == 0)
    {
        Serial.println('o'); // 
    }
    if(x1 == 0 && x2 == 1 && x3 == 0 && x4 == 0)
    {
        Serial.println('c'); // 
    }
    
    if(x1 == 0 && x2 == 0 && x3 == 1 && x4 == 0)
    {
        Serial.println('u'); // 
    }
    if(x1 == 0 && x2 == 0 && x3 == 0 && x4 == 1)
    {
        Serial.println('d'); // 
    }
    
    
    if(x1 == 1 && x2 == 0 && x3 == 1 && x4 == 0)
    {
        Serial.println('o'); //
        Serial.println('u'); 
    }
    if(x1 == 1 && x2 == 0 && x3 == 0 && x4 == 1)
    {
        Serial.println('o'); //
        Serial.println('d'); 
    }
    if(x1 == 0 && x2 == 1 && x3 == 1 && x4 == 0)
    {
        Serial.println('c'); //
        Serial.println('u'); 
    }
    if(x1 == 0 && x2 == 1 && x3 == 0 && x4 == 1)
    {
        Serial.println('c'); // 
        Serial.println('d');
    }
}
    

