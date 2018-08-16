
#include <LiquidCrystal.h>

#define DISPLAY_LCD 1

const uint8_t ANALOG_KEYS = A0;

#if DISPLAY_LCD
// LCD display definitions
const uint8_t LCD_ROWS = 2;
const uint8_t LCD_COLS = 16;

// LCD pin definitions
// These may change depending on your LCD display
const uint8_t LCD_RS = 8;
const uint8_t LCD_ENA = 9;
const uint8_t LCD_D4 = 4;
const uint8_t LCD_D5 = LCD_D4+1;
const uint8_t LCD_D6 = LCD_D4+2;
const uint8_t LCD_D7 = LCD_D4+3;

LiquidCrystal lcd(LCD_RS, LCD_ENA, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
#define DEVICE lcd
#else
#define DEVICE Serial
#endif

void setup() 
{ 
    Serial.begin(57600);
#if DISPLAY_LCD
  DEVICE.begin(LCD_COLS, LCD_ROWS);
  DEVICE.clear();
#else

#endif


#if DISPLAY_LCD
  DEVICE.setCursor(0,1);
#endif
  DEVICE.print("Tello:Arduino:<3");

  pinMode(ANALOG_KEYS, INPUT);
}

void loop() 
{
  uint16_t adcKeyIn;
  
  adcKeyIn = analogRead(ANALOG_KEYS);    // read the value from the port  
if (adcKeyIn <1000) { // if no button is pressed
  
  Serial.println(adcKeyIn);
}
#if DISPLAY_LCD
  DEVICE.home();
#endif
  DEVICE.print("Command = ");
  DEVICE.print(adcKeyIn);
//  Serial.println(adcKeyIn);
#if DISPLAY_LCD
  DEVICE.print("   ");
#else
  DEVICE.println();
#endif

  delay(100);
}


