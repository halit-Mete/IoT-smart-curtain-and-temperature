#define BLYNK_TEMPLATE_ID "TMPL6VyofHFss" // blynkideki şablonun idsi
#define BLYNK_TEMPLATE_NAME "Sicaklik" // blynkideki şablonun adı
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "gyWRZDpY74c3493i1z6vvEk4_J1Pv6Si"; // blynk token
char ssid[] = "Belesnet"; // wifi adı
char pass[] = "123456785500"; // wifi şifresi

BlynkTimer timer;

void myTimerEvent() {
  int sensorValue = analogRead(A0); // LM35 sensöründen analog okuma

  // LM35'in çıkış gerilimini sıcaklığa dönüştürme
  float temperature = (sensorValue * 0.05) + 20; // 10 mV/°C, bu nedenle doğrudan çıkış gerilimi 100 mV/°C olacak
  
  Blynk.virtualWrite(V1, temperature); // Sıcaklık değerini Blynk'e gönderme
}

void setup() {
  Serial.begin(9600); // Nodemcunun baud hızını seri başlangıç olarak veriyoruz
  Blynk.begin(auth, ssid, pass); // Blynk bağlantısını başlatma
  timer.setInterval(1000L, myTimerEvent); // Her 1 saniyede bir myTimerEvent fonksiyonunu çağırma
}

void loop() {
  Blynk.run();
  timer.run();
}
