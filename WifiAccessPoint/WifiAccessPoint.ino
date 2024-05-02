#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

//#define LED_BUILTIN 2

const char* ssid = "ESP_32";
const char* password = "Password";

WiFiServer server(80);
void setup() {
  //pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  Serial.println();
  Serial.println("Configuring access point...");

  if (!WiFi.softAP(ssid, password)) {
    log_e("Soft AP creation failed.");
    while (1);
  }
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  server.begin();

  Serial.println("Server started");
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    Serial.println("New Client.");
    String currentLine = "";

    while (client.connected()) {
      /*
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
    
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            */
            // Generate a random number between 0 and 299
            long randNumber = random(300);
           // uint32_t randNumber = esp_random();
            client.print("Random Number: ");
            
            client.println(randNumber);
           
           // client.print("<br>Click <a href=\"/H\">here</a> to turn ON the LED.<br>");
           // client.print("Click <a href=\"/L\">here</a> to turn OFF the LED.<br>");
  
         //  break;
       /*   } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
        */
       /*
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(LED_BUILTIN, HIGH);
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(LED_BUILTIN, LOW);
        }
        */
      //}
    }

   // client.stop();
    Serial.println("Client Disconnected.");
  }
}
