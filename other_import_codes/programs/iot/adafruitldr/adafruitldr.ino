#include<ESP8266WiFi.h>
#include "Adafruit_MQTT_Client.h"

#define ldr A0
#define wifi "VIRUS"
#define password "raj12345"
#define server "io.adafruit.com"
#define port 1883
#define username "i_am_rajee"
#define key "14e1d82cac804c5cbe5377905ca95a0a"

WiFiClient esp;

Adafruit_MQTT_Client mqtt(&esp,server, port, username, key);                                      //connecting Client to server //espuk :)
Adafruit_MQTT_Publish feed = Adafruit_MQTT_Publish(&mqtt, username"/feeds/ldr");              //giving location to publish data 


void setup()
{
  Serial.begin(115200);
  delay(10);
  Serial.println("Adafruit MQTT demo");
  Serial.print("Connecting to ");
  Serial.println(wifi);
  
  
  WiFi.begin(wifi,password);
  while(WiFi.status()!= WL_CONNECTED)
    {
          delay(500);
           Serial.print(".");
    }

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println("WiFi.localIP()");
  Serial.print("Connecting to MQTT");
  
  
  while(mqtt.connect())                                                 //printing while connecting
    {
          Serial.print(".");
    }

}



void loop()
{
  if(mqtt.connected())                      //only if connected
   {
         int data = analogRead(ldr);
         Serial.print("\nSending LDR val");
         Serial.print(data);
         Serial.print("...");


         if(feed.publish(data))                                                        //publish the data and checking if published or not
          {
             Serial.println("Success");
          }
         else
          {
            Serial.println("Fail!");  
        }
          delay(1101);                                                         //*************************
  }



}









/*

#include<ESP8266WebServer.h>
ESP8266WebServer server;


const char username[] = "Rajeesingh27";         //acess point const
const char password[] = "1234567890";


#define pin 16

void setup() {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  Serial.begin(115200);

  WiFi.softAP(username, password);                  //acess point
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address:");
  Serial.println(myIP);


  server.begin();
  server.on("/led", led);
  
}
void loop() {
  server.handleClient();
}

void led()
{
  String myhtml = "<html><head><title>I'M RAJEE</title></head><body   style =  \"background-color : palegreen \"><h1><center>Conect with me on following socials!!</center></h1><h5><center>wwww.wixsite.com/rajeesingh27</center></h5><form><center><button  type = \"submit\"  name = \"state\" value = \"0\">LED ON</button><button  type = \"submit\"  name = \"state\" value = \"1\">LED OFF</button></center></form></body></html>";
  
  server.send(200, "text/html", myhtml);     //send okey

  if(server.arg("state") == "1")
  {
    digitalWrite(pin, HIGH);
  }
  else
  {
    digitalWrite(pin, LOW);
  }
}
*/
