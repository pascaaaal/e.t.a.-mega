#include <SPI.h>
#include <Ethernet2.h>
#include <ArduinoJson.h>


byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; //MAC Addres ()
char server[] = "dexnet23.ddns.net"; //Server URL (wetterstation url)
String key = "eiwruzbhnfdhgdshfgnckdfhgnckjsfdhncksdhfnkdjhgnkjfdhkghcsndkghcnskdjhcnskdghncsgc";
EthernetClient client;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting program...");

  Serial.println("Setting up Network...");

  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    //Ethernet.begin(mac, ip);
  }

  delay(500);

  Serial.println(Ethernet.localIP());

  Serial.println("Setted up Network");
  Serial.println("System ready for use!");
}

void loop() {
  //Send data
    if (client.connect(server, 80)) {
    // Make a HTTP request:
    client.print("GET /articles/list");
    client.println(" HTTP/1.1");
    client.print("Host: ");
    client.println(server);
    client.print("Content-Length: ");
    client.println(packet_length);
    client.print("Authorization: ");
    client.println("Bearer " + key);
    client.println("Content-Type: application/json\r\n");
    client.print(d);
  }else {
    Serial.println("Connecting failed!");
  }
  
  String responce = "";
  
  while(client.connected()){
    if (client.available()) {
      char c = client.read();
      responce += c;
      //Serial.print(c);
      if(c == '\n'){
        responce = "";
      }else if(c == '\r'){
        
      }else if(c == '}'){
        if(responce.indexOf("{") != -1){
          break;
        }
      }
    }
  }
  client.stop();

  char json[responce.length() + 1];
  responce.toCharArray(charBuf, responce.length() + 1);
  StaticJsonDocument<200> doc;

  DeserializationError error = deserializeJson(doc, json);
  
  if(doc["error"]) {
    Serial.println(doc["meaasage"]);
  }
  delay(60000);
}
