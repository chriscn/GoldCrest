// Measuring Voltage.
// Electroroute - Gold Crest
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int LEDArray[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // contains all the PINs of the LEDs you want to use as your scale.
const bool debug = true; // debug mode - probably leave this as false.

int currentValue = 0;
int previousValue = 0;
int CurrentLEDsOn[] = {};
int PreviousLEDsOn[] = {};

LiquidCrystal_I2C lcd(0x27, 16, 2); // initalise the LCD

void setup() {
  pinMode(A0, INPUT); // pin to measure the voltage
  for (int i = 0; i < sizeof(LEDArray); i++) { // turn all the LED
    pinMode(LEDArray[i], OUTPUT);
  }
  if (debug) {
    Serial.begin(9600);
  }

  lcd.begin();
  lcd.print("Electroroute");
  lcd.setCursor(0,1);
  lcd.print("Voltage: ");
}

void loop() {
  currentValue = map(analogRead(A0), 0, 1000, 0, sizeof(LEDArray) / 2);

  if (currentValue != previousValue) {
    if (currentValue < previousValue) {
      for (int i = sizeof(LEDArray) / 2; i >= currentValue; i--) {
        digitalWrite(LEDArray[i], LOW);
      }
    }
    lcd.setCursor(0, 1);
    lcd.print("Voltage: ");
    lcd.print(map(analogRead(A0), 0, 1023, 0, 500) / 100.0);
    lcd.print("V");
    for (int j = 0; j < currentValue; j++) {
      digitalWrite(LEDArray[j], HIGH);
    }

  }

  previousValue = currentValue;
  delay(20); // stability
  if (debug) {
    Serial.print(currentValue);
    Serial.print(" : ");
    Serial.println(previousValue);
  }
}
