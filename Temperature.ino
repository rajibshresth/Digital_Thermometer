/*-----------Arduino LM35 Code-------------*/
/*-----------Digital Thermometer Using Arduino-------------*/

#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

#define sensor A0

byte degree[8] = 
              {
                0b00011,
                0b00011,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000
              };

void setup()
{
  lcd.begin(16,2);
  lcd.createChar(1, degree);
  lcd.setCursor(0,0);
  lcd.print("    Digital    ");
  lcd.setCursor(0,1);
  lcd.print("  Thermometer   ");
  delay(4000);
  lcd.clear(); 
}

void loop()
{
  /*---------Temperature-------*/
     float reading=analogRead(sensor);
     float temperature=reading*(5.0/1023.0)*100;
     delay(10);
  
  /*------Display Result------*/
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("Temperature");
    lcd.setCursor(4,1);
    lcd.print(temperature);
    lcd.write(1);
    lcd.print("C");
    delay(1000);
}
