#include <SoftwareSerial.h> 
SoftwareSerial sw (2,3);
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,16,2);  //
void setup() 
{ 
  Serial.begin(9600);
  sw.begin(9600);
  // Inicializar el LCD
  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();
} 
 
void loop() {

  int sen1=analogRead(A2);// Valor corriente motor
  float sen=((sen1*5.0)/1023);
  float co=sen/10;
  lcd.setCursor(0,0);
  lcd.print("ADC:");
  lcd.print(co);
  lcd.print("   ");
  delay(50);
  
  if (sw.available ()>0) {
  char c = sw.read(); 
  Serial.print (c);
  Serial.write(c); //enviamos el ángulo correspondiente
  delay(100); 
  }                       
}  
