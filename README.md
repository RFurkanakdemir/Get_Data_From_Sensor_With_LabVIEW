# LabVIEW-ile-sensorden-veri-alma
bir sensör verisini LabVIEW a gönderme ve bu veri için arayüz oluşturma uygulaması

## Projenin Amacı
Üretilen kanatların farklı ivme ve eksen konumlarında esneklik performansını incelemek için esneklik ve gyro sensörlerini Labwiev üzerinde görselleştirmek.


## Sensörler ##
*Sensör Listesi*  | *Alınan veri*
------------- | -------------
HC-SR04 | Mesafe



## Sensör Bağlantıları ##
HC-SR04

![image](https://user-images.githubusercontent.com/101727667/172135493-fdf5222c-c977-49db-af14-450cef4b9014.png)


## Ardunio Kodu ##

ruby
int trigPin = 50; /* Sensorun trig pini Arduinonun 50 numaralı ayağına bağlandı */
int echoPin = 51;  /* Sensorun echo pini Arduinonun 51 numaralı ayağına bağlandı */

long sure;
long uzaklik;

void setup(){
  pinMode(trigPin, OUTPUT); // trig pini çıkış olarak ayarlandı 
  pinMode(echoPin,INPUT); //echo pini giriş olarak ayarlandı 
  Serial.begin(9600); //Seri haberlesme baslatildi 
}
void loop()
{
  digitalWrite(trigPin, LOW); //sensör pasif hale getirildi 
  delay(5);
  digitalWrite(trigPin, HIGH); // Sensore ses dalgasının üretmesi için emir verildi 
  delay(5);
  digitalWrite(trigPin, LOW);  // Yeni dalgaların üretilmemesi için trig pini LOW konumuna getirildi 
  sure = pulseIn(echoPin, HIGH); // ses dalgasının geri dönmesi için geçen sure ölçülüyor 
  uzaklik= sure /29.1/2; // ölçülen sure uzaklığa çevriliyor          
  if(uzaklik<100)
  {
  Serial.print("Uzaklik ");  
  Serial.print(uzaklik); // hesaplanan uzaklık bilgisayara aktarılıyor
  Serial.println(" CM olarak olculmustur.");  }
  if(uzaklik>100){
    Serial.println("Mesafe Cok fazla");
  }
  
    
  delay(500); 
}

## Labwiev Görselleri ##
*Labview Front Paneli*
![ÖN PANEL](https://user-images.githubusercontent.com/101727667/172136488-dc9d431e-07c7-48d8-85bf-fe59b9bcfa0c.PNG)

*Labview Blok Diyagramı*
![LabView Yazılım](https://user-images.githubusercontent.com/101727667/172137324-de04b349-d4e3-4559-a8de-c03135123534.PNG)

*İncelediğiniz için teşekkürler
