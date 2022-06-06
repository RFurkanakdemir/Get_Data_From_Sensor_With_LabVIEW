int trigPin = 50; /* Sensorun trig pini Arduinonun 50 numaralı ayağına bağlandı */
int echoPin = 51;  /* Sensorun echo pini Arduinonun 51 numaralı ayağına bağlandı */

long sure;
long uzaklik;

void setup(){
  pinMode(trigPin, OUTPUT); /* trig pini çıkış olarak ayarlandı */
  pinMode(echoPin,INPUT); /* echo pini giriş olarak ayarlandı */
  Serial.begin(9600); /* Seri haberlesme baslatildi */
}
void loop()
{
  digitalWrite(trigPin, LOW); /* sensör pasif hale getirildi */
  delay(5);
  digitalWrite(trigPin, HIGH); /* Sensore ses dalgasının üretmesi için emir verildi */
  delay(5);
  digitalWrite(trigPin, LOW);  /* Yeni dalgaların üretilmemesi için trig pini LOW konumuna getirildi */ 
  sure = pulseIn(echoPin, HIGH); /* ses dalgasının geri dönmesi için geçen sure ölçülüyor */
  uzaklik= sure /29.1/2; /* ölçülen sure uzaklığa çevriliyor */            
  if(uzaklik<100)
  {
  Serial.print("Uzaklik ");  
  Serial.print(uzaklik); /* hesaplanan uzaklık bilgisayara aktarılıyor */
  Serial.println(" CM olarak olculmustur.");  }
  if(uzaklik>100){
    Serial.println("Mesafe Cok fazla");
  }
  
    
  delay(500); 
}
