#include <ESP8266WiFi.h>
#include <PubSubClient.h>
const char* ssid = "SK_WiFiGIGA2890"; 
const char* password = "2011084109";  
const char* mqtt_server = "192.168.34.51";
const char* inTopic = "bfagr34awet3";
const char* outTopic = "mfc309m9h6";
const char* clientName = ""; 
int trigPin = D1;
int echoPin = D2;
float distance,duration;
char mac[20];
String sMac;

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message:");
  String messageRelay;
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
    messageRelay += (char)payload[i];
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
 
void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
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

void loop(){
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
  distance = (float)duration*0.017;
 
  Serial.print("DIstance:");
  Serial.print(distance);
  Serial.print("cm\n");
  
  if(distance<5){
    client.publish(outTopic, "LED ON");
    Serial.println("Send message!");
  }
  
  delay(2000);
}
