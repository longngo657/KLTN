// Khai báo các thư viện cần thiết
#include <ArduinoJson.h>
#include <SoftwareSerial.h>

// Tạo một đối tượng JsonDocument có dung lượng 100 byte
StaticJsonDocument<100> doc;

SoftwareSerial mySerial(D2, D1); // RX | TX

void setup() {
  // Khởi tạo giao tiếp nối tiếp với tốc độ baud là 9600
  Serial.begin(9600);
  // Khởi tạo cổng nối tiếp ảo
  mySerial.begin(9600);
}

void loop() {
  String temp = "on";
  doc["tem"] = temp;
  serializeJson(doc, mySerial);
  mySerial.println();
  

  if (mySerial.available()) {
    String line = mySerial.readStringUntil('\n');
    DeserializationError error = deserializeJson(doc, line);
    String temperature = doc["tem2"];
    Serial.print(temperature);
  } 
  serializeJson(doc, Serial);
  Serial.println();
  delay(1000);
}
