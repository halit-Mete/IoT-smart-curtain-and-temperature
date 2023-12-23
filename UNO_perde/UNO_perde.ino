#include <Servo.h> // Servomotor kullanımı için kütüphane
Servo myservo; 
int pos = 0;
int lightPin = A1; // Veri girişi Analog 1 den

// Servonun dijital pini 9
void setup() {
  myservo.attach(9);
}


void loop()   {
  int lightLevel =analogRead(lightPin);
  lightLevel = map(lightLevel, 200, 500, 0, 360); 
  // 200-500 arasında ışık verisi değişkenine göre 0-180 derece arasında motor konum alıyor
  pos = constrain(lightLevel, 0, 360);

  myservo.write(pos);
  delay(3000); // 3 saniyede bir veri almasını sağlamak için 3000ms ayarlandı


}
