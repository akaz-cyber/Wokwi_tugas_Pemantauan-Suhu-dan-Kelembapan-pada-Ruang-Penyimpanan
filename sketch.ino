// Kelompok 4 - Pemantauan Suhu dan Kelembapan pada Ruang Penyimpanan
// Anggota: 
// 1.Ajri muhammad sidiq - 22552011005
// 2.Muhammad Reihan Z.A - 22552011012
// 3.Syukur Sidiq Nur Alam - 22552011021

#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTPIN 10
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHT22);

LiquidCrystal_I2C lcd(0x27,20,4);
int chk;
float hum;
float temp;

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("TUGAS PROYEK MINI");
  lcd.setCursor(2,1);
  lcd.print("SUHU & KELEMBAPAN");
  lcd.setCursor(1,2);
  lcd.print("RUANGAN PENYIMPANAN");
  lcd.setCursor(5,3);
  lcd.print("KELOMPOK 4");
  delay(3000);
  lcd.clear();
  
}

void loop() {
 
 hum = dht.readHumidity();
 temp = dht.readTemperature();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("RUANGAN PENYIMPANAN");
  lcd.setCursor(1,1);
  lcd.print("SUHU & KELEMBAPAN");

  //suhu
  lcd.setCursor(0,2);
  lcd.print("SUHU       :");
  lcd.setCursor(13,2);
  lcd.print(temp);
  lcd.setCursor(19,2);
  lcd.print("C");
  
  //kelembaban
  lcd.setCursor(0,3);
  lcd.print("KELEMBAPAN :");
  lcd.setCursor(13,3);
  lcd.print(hum);
  lcd.setCursor(19,3);
  lcd.print("%");
 
}
