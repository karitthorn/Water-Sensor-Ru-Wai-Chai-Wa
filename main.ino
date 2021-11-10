//By Karitthorn
#include "DHT.h"
#include <LiquidCrystal_PCF8574.h>
#include <Wire.h>
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_PCF8574 lcd(0x27);
int show = -1;
int buzzer = 11;

void setup() {
   Serial.begin(9600); 
   pinMode(buzzer, OUTPUT);
   dht.begin();
   lcd.setBacklight(255);
   lcd.begin(16, 2);
   
}
void loop() {

  int sensorValur = analogRead(A0);
  Serial.print(sensorValur);
  Serial.print("\n");

   float h = dht.readHumidity();
   int hnumber = int(h);
   float t = dht.readTemperature();
   float f = dht.readTemperature(true);
   
   
   lcd.setCursor(0, 0);

   
   if( sensorValur > 400){
   lcd.clear();
   lcd.print("Alart");
   lcd.print(" | ");
   lcd.print("flood");
   digitalWrite(buzzer,1000);
   delay(2000);
   noTone(buzzer);
   return;
   }

   if( h < 50){
   lcd.clear();
   lcd.print("(^o^)");
   lcd.print(" | ");
   lcd.print("No rain");
   
   }
      if( h >= 50 ){
   lcd.clear();
   lcd.print("(-_-)");
   lcd.print(" | ");
   lcd.print("Normal");
   
   }
      if( h > 70 ){
   lcd.clear();
   lcd.print("(-o-;)");
   lcd.print(" | ");
   lcd.print("Maybe");
         }
   if(h > 90){
   lcd.clear();
   lcd.print("(>_<)");
   lcd.print(" | ");
   lcd.print("Raining");
   
    }
   lcd.setCursor(0, 1);
   lcd.print("H = "); 
   lcd.print(hnumber);
   lcd.print("\% ");
   lcd.print("T = "); 
   lcd.print(t);
//   Serial.print(" *C ");
//   Serial.print(f);
//   Serial.print(" *F\t");
//   Serial.print("\n");
   delay(2000);
   
   lcd.clear();
}
