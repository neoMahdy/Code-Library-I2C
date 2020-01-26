/*
      neo Mahdy 
  Belajar LCD dengan I2C
                         */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Make custom characters:
byte Heart[] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};
byte Bell[] = {
  B00100,
  B01110,
  B01110,
  B01110,
  B11111,
  B00000,
  B00100,
  B00000
};
byte Alien[] = {
  B11111,
  B10101,
  B11111,
  B11111,
  B01110,
  B01010,
  B11011,
  B00000
};
byte Rose[] = {
  B00000,
  B00000,
  B01110,
  B11011,
  B11111,
  B01110,
  B00000,
  B00000
};
byte Speaker[] = {
  B00001,
  B00011,
  B01111,
  B01111,
  B01111,
  B00011,
  B00001,
  B00000
};
byte Sound[] = {
  B00001,
  B00011,
  B00101,
  B01001,
  B01001,
  B01011,
  B11011,
  B11000
};
byte Skull[] = {
  B00000,
  B01110,
  B10101,
  B11011,
  B01110,
  B01110,
  B00000,
  B00000
};
byte Lock[] = {
  B01110,
  B10001,
  B10001,
  B11111,
  B11011,
  B11011,
  B11111,
  B00000
};

void setup()
{
	// initialize the LCD
	lcd.begin();
  
  // Create a new characters:
  lcd.createChar(0, Heart);
  lcd.createChar(1, Bell);
  lcd.createChar(2, Alien);
  lcd.createChar(3, Rose);
  lcd.createChar(4, Speaker);
  lcd.createChar(5, Sound);
  lcd.createChar(6, Skull);
  lcd.createChar(7, Lock);
  
  // Print a message to the lcd:
  lcd.setCursor(3,0);
  lcd.print("I See You");
  delay(3000);
  lcd.setCursor(6,1);
  lcd.write(byte(3));
  lcd.setCursor(8,1);
  lcd.write(byte(0));
  delay(5000);
  
  // Clears the LCD screen:
  lcd.clear();
  
}

void loop()
{
  // Print all the custom characters:
  lcd.print("Custom Character");
  lcd.setCursor(0, 1);
  lcd.write(byte(0));
  lcd.setCursor(2, 1);
  lcd.write(byte(1));
  lcd.setCursor(4, 1);
  lcd.write(byte(2));
  lcd.setCursor(6, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  lcd.setCursor(12, 1);
  lcd.write(byte(6));
  lcd.setCursor(14, 1);
  lcd.write(byte(7));
  delay(5000);
  lcd.clear();

  // Print LCD Scroll
  lcd.scrollDisplayRight();
  lcd.setCursor(0, 0);
  for (int x = 9; x > 2; x--) {
    lcd.print(x);
    lcd.print(" ");
    delay(500);
  }
  lcd.clear();
  lcd.autoscroll();
  lcd.scrollDisplayLeft();
  lcd.setCursor(15, 1);
  for (int y = 3; y < 10; y++) {
    lcd.print(y);
    lcd.print(" ");
    delay(500);
  }
  lcd.noAutoscroll();
  lcd.clear();
}
