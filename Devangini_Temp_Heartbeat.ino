#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

#define Buzz 2
int S1=5;
#define Temp A1
void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(Temp, INPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(S1,INPUT_PULLUP);
  pinMode(Buzz,OUTPUT); 
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Ardiuno Based");
  lcd.setCursor(0, 1);
  lcd.print("Health Monitor");
  delay(3000);


}

int myBPM=0;
void loop() {
  int T = analogRead(Temp);
  float voltage = T * (5000 / 1024.0);
  float temperature = voltage / 10;
  if(digitalRead(S1)==0) {
     digitalWrite(Buzz,HIGH);
     delay(1000);
     digitalWrite(Buzz,LOW);
     delay(15000);
     myBPM = analogRead(A0)/10; 
    }
  lcd.clear();  
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature);
  lcd.print(" BPM:");
  lcd.print(myBPM);
  Serial.print("H ");
  Serial.print(myBPM);
  Serial.print(" T ");
  Serial.print(temperature);
  Serial.println();
  delay(1000);
  myBPM=0;
}
