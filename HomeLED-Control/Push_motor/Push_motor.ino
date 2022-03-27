#include <Servo.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "SK_WiFiGIGA2890"; 
const char* password = "2011084109"; 
const char* mqtt_server = "192.168.34.51"; 
const char* inTopic = "bfagr34awet3";
const char* outTopic = "mfc309m9h6";
const char* clientName = "";
char mac[20];
String sMac;
int pos;
Servo myservo;

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message:");
  String messageRelay;
  for (int i = 0; i < length; i++)
  { 
    
    messageRelay += (char)payload[i];
    if(messageRelay=="LED ON"){
      for (pos = 0; pos <= 180; pos += 1)
      {
      myservo.write(pos);
      delay(15);
      } 
      Serial.println("불을 켭니다");
   }
  }
  Serial.println("-----------------------");
}

void connectMqtt() {
  Serial.println("Connecting to MQTT...");
  client.setServer(mqtt_server,1883);
  client.setCallback(callback);
  
  while (!client.connected()) {
    if (!client.connect(clientName)) {
      Serial.print("MQTT connection failed:");
      Serial.print(client.state());
      Serial.println("Retrying...");
      delay(5000);
    }
  }

  Serial.println("MQTT connected");
  Serial.println("");
}

void setup_wifi() {
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(9600);
  myservo.attach(5);
  delay(1000);

  setup_wifi();
  connectMqtt();

  uint8_t macH[6]="";
  WiFi.macAddress(macH);
  sprintf(mac,"%02x%02x%02x%02x%02x%02x%c",macH[5], macH[4], macH[3], macH[2], macH[1], macH[0],0);
  sMac=mac;
  clientName=mac;
  Serial.println(mac);
}

void loop() {
  client.loop();
  client.subscribe("mfc309m9h6");
}
