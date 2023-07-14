#include<Wire.h>
#include <LiquidCrystal_I2C.h>
#include<Adafruit_Sensor.h>
#include<DHT.h>


LiquidCrystal_I2C lcd(0x3F, 16, 2);
DHT dht(23,DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
lcd.init();
lcd.backlight();
dht.begin();


}

void loop() {
   int t;
  int h;
  int s=analogRead(34);
  s=map(s,0,4095,0,255);
  Serial.println(s);
  t=dht.readTemperature();
  h=dht.readHumidity();
  Serial.println(t);
  Serial.println(h);
  lcd.setCursor(0,0);
  lcd.print("Plant Watering");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("System...");
  delay(1000);
  lcd.clear();
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("T : ");
  lcd.print(t);
  lcd.print("C");
  lcd.setCursor(0,1);
 lcd.print("H : ");
  lcd.print(h);
  lcd.print("%");
     delay(2000); 
     lcd.clear();
     lcd.setCursor(0,0);
  lcd.print("Soil Mositure");
  lcd.setCursor(0,1);
  lcd.print("Level: ");
    if(s==255){
      lcd.print("Very Low");
      blynk.logEvent("Alert Moisture");
    } if(s<255&&s>200){
      lcd.print("Moderate");
      
    } if(s<=170){
      lcd.print("Very High");
      
    }

    delay(3000);
    lcd.clear();
  
}
