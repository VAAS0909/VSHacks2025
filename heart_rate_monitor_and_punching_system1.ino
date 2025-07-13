// C++ code
//
#include <Adafruit_LiquidCrystal.h>

int ir = 0;

int standBy = 0;

Adafruit_LiquidCrystal lcd_1(0);

int counter;

void setup()
{
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(11, OUTPUT);
  lcd_1.begin(16, 2);
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);

  analogWrite(3, 0);
  analogWrite(6, 0);
  analogWrite(11, 0);
  lcd_1.print("Welcome to ");
  lcd_1.setCursor(0, 1);
  lcd_1.print("HeartRate Device");
  delay(2000); // Wait for 2000 millisecond(s)
  lcd_1.clear();
  lcd_1.print("Initializing");
  for (counter = 0; counter < 4; ++counter) {
    lcd_1.print(".");
    delay(1000); // Wait for 1000 millisecond(s)
  }
  lcd_1.clear();
  standBy = 1;
  lcd_1.print("Place hand on");
  lcd_1.setCursor(0, 1);
  lcd_1.print("IR Sensor");
  delay(3000); // Wait for 3000 millisecond(s)
  lcd_1.clear();
}

void loop()
{
  ir = digitalRead(12);
  lcd_1.print(ir);
  lcd_1.print(" BPM                                                                   ");
  delay(10); // Wait for 10 millisecond(s)
  if (ir >= 120) {
    digitalWrite(13, LOW);
    digitalWrite(11, LOW);
  } else {
    digitalWrite(11, HIGH);
    delay(100); // Wait for 100 millisecond(s)
    digitalWrite(11, LOW);
    digitalWrite(13, HIGH);
    tone(10, 523, 1000); // play tone 60 (C5 = 523 Hz)
    delay(1000); // Wait for 1000 millisecond(s)
  }
}