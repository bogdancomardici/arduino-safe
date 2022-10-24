#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>


LiquidCrystal_I2C lcd(0x27,16,2);

const int pinR = 10;
const int pinG = 11;


const uint8_t ROWS = 4;
const uint8_t COLS = 4;
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

uint8_t colPins[COLS] = { 5, 4, 3, 2 }; // Pins connected to C1, C2, C3, C4
uint8_t rowPins[ROWS] = { 9, 8, 7, 6 }; // Pins connected to R1, R2, R3, R4

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
void setup() {
  
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);

  lcd.init();                      
  
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Enter code:");

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(1, OUTPUT);
  
}

void loop() {
  String cod = "";
  String cod_salvat = "12345";

  lcd.setCursor(0,1);
  while(cod[cod.length() - 1] != '#')
  {
    char cifra = keypad.getKey();
    if(cifra >= '0' && cifra <= '9'|| cifra == '#')
    {
      lcd.print('X');
      cod += cifra;
      
    }
  }
cod[cod.length() - 1] = '\0';
cod_salvat += '\0';

lcd.setCursor(0,1);

if(cod.equals(cod_salvat))
{
  for(int i = 0; i < 16; i++)
  {
    lcd.print(".");
    delay(50);
  }
  lcd.setCursor(0,0);
  lcd.print("                  ");
  lcd.setCursor(0,1);
  lcd.print(" ACCES  GRANTED  ");

  digitalWrite(12, HIGH);
}
else
  {
  for(int i = 0; i < 16; i++)
  {
    lcd.print(".");
    delay(50);
  }
  lcd.setCursor(0,0);
  lcd.print("                  ");
  lcd.setCursor(0,1);
  lcd.print("  ACCES DENIED    ");
  digitalWrite(1, HIGH);
  while(1 == 1)
  {
    
    digitalWrite(13, HIGH);
    delay(200);
    digitalWrite(13, LOW);
    delay(200);
    

  }
  }
  

}
