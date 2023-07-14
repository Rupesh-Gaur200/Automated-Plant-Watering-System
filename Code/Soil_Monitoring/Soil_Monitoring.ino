
#define BLYNK_TEMPLATE_ID "TMPL3xblRMdbU"
#define BLYNK_TEMPLATE_NAME "plant"
#define BLYNK_AUTH_TOKEN "OJMStK2ty32hC-pNtBDo84Fa2LnAcGes"
#define BLYNK_PRINT Serial
#include<Wire.h>
#include <LiquidCrystal_I2C.h>
#include<Adafruit_Sensor.h>
#include<DHT.h>


LiquidCrystal_I2C lcd(0x3F, 16, 2);
DHT dht(23,DHT11);

#include <BlynkSimpleEsp32.h>

void setup()
{  pinMode(33,OUTPUT);
  lcd.init();
lcd.backlight();
dht.begin();
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, "JioFi3_50688C", "2u36kp9cma");
}

void loop()
{
  Blynk.run();
   int t;
  int h;
  int Touch=touchRead(T0);
  int s=analogRead(34);
  s=map(s,0,4095,255,0);
  Serial.println(s);
  t=dht.readTemperature();
  h=dht.readHumidity();
  Blynk.virtualWrite(V0,t);
  Blynk.virtualWrite(V1,h);
 Blynk.virtualWrite(V2,s);
 if(t>35){
  Blynk.logEvent("temp");
 }
  Serial.println(t);
  Serial.println(h);
  lcd.setCursor(0,0);
  lcd.print("Plant Monitring");
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
  if(Touch<30){
    Blynk.logEvent("touch");
  }
    if(s<20){
      lcd.print("Very Low");
      Blynk.logEvent("alert_moisture");
      digitalWrite(33,HIGH);
      Blynk.logEvent("waterpump");
      
    }if(s>=20&&s<=89){
       lcd.print("Moderate");
      
    }
      if(s>=90&&s<110){
      lcd.print("High");
      digitalWrite(33,LOW);
      
    } if(s>=110){
      lcd.print("Very High");
      digitalWrite(33,LOW);
     
    }

    delay(3000);
    lcd.clear();
}
