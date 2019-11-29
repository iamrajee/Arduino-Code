#include <SimpleDHT.h>
int DHTpin = 2;
Serial.begin(115200);
byte temperature;
byte humidity;
void loop(){
if (simple_dht11_read(DHTpin, &temperature, &humidity, NULL)) {
 
   Serial.print("Failed.");
 
}
else {
 
   Serial.print("temperature: "); Serial.print(temperature); Serial.println("ºC");
   Serial.print("Humidity: "); Serial.print(humidity); Serial.println("%");
 
}
 
delay(2000);
