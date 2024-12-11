// Khai báo thư viện cần thiết
#include <ArduinoJson.h>

// Khai báo thư viện SoftwareSerial
#include <SoftwareSerial.h>

SoftwareSerial mySerial(11, 10); // RX | TX

// Tạo một đối tượng JsonDocument có dung lượng 100 byte
StaticJsonDocument<100> doc;

void setup() {
  // Khởi tạo giao tiếp nối tiếp với tốc độ baud là 9600
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  String tem2 = "off";
  doc["tem2"]=tem2;
  serializeJson(doc, mySerial);
  mySerial.println();
    
  if (mySerial.available()) {
    String line = mySerial.readStringUntil('\n');
    DeserializationError error = deserializeJson(doc, line);
    String temperature = doc["tem"];
    Serial.print(temperature);
  }
  serializeJson(doc, Serial);
  Serial.println();
  delay(1000);  
}
