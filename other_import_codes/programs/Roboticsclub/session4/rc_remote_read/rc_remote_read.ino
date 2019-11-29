const int ch1_pin=9;  //Constant variables relating to pin locations
int ch1_value;  //Varibles to store and display the values of each channel

void setup() {// the setup routine runs once when you press reset:
  Serial.begin(115200);// initialize serial communication at 115200 bits per second
  pinMode(ch1_pin, INPUT);// Set input pins
}

void loop() {//Main Program
  ch1_value = pulseIn (ch1_pin,HIGH);  //Read and store channel 1
  Serial.print ("Ch1_value: ");  //Display text string on Serial Monitor to distinguish variables
  Serial.println(ch1_value);     //Print in the value of channel 1
  delay(50);
}
