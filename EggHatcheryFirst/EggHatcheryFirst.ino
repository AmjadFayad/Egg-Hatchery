#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C  lcd(0x27,2,1,0,4,5,6,7);

#define DHTPIN A0
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int relay1 = 2;
int relay2 = 3;
void setup() {

      lcd.setBacklightPin(3,POSITIVE);
    lcd.setBacklight(HIGH); // NOTE: You can turn the backlight off by setting it to LOW instead of HIGH
    lcd.begin(16, 2);
    lcd.clear();
  Serial.begin(9600);
  dht.begin();
      pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);



    
}
void loop() {
   float h = dht.readHumidity();
   // Reading temperature or humidity takes about 250 milliseconds!
   float t = dht.readTemperature();
   // Read temperature as Celsius (the default)
   float f = dht.readTemperature(true);
    float fh = dht.readHumidity(true);

    lcd.print("Temp         C  ");
    lcd.setCursor(6,0);
    lcd.print(t);
    lcd.setCursor(0,1);
    lcd.println("Humid        %  ");
    lcd.setCursor(6,1);
    lcd.print(h);

      if(t<37.6 || t>37.3)
      {
       if(t>37.6)
       {
         digitalWrite(relay1, LOW);
       }
       else
       {
        if(t<37.3)
        {
          digitalWrite(relay1, HIGH);
        }
       }
      }
      else
      {

      }

      if(h<55 || h>50)
      {
       if(h>55)
       {
         digitalWrite(relay2, LOW);
       }
       else
       {
        if(h<50)
        {
          digitalWrite(relay2, HIGH);
        }
       }
      }
      else
      {
      
      }
            delay(2000);
}
