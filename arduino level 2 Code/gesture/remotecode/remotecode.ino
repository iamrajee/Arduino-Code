//Remote code

const int xpin=A0; // x axis of the accelerometer
const int ypin=A1; // y axis of the accelerometer
int a,b; // a and b are global variables

void setup()
{
    Serial.begin(9600); // initialize the serial communications
}

void loop()
{
    int x=analogRead(xpin);
    int y=analogRead(ypin);
    
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
}
    

