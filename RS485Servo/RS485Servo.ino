#include <Servo.h> 

Servo myservo;  // creamos el objeto servo 
 
void setup() 
{ 
  Serial.begin(9600);  
  myservo.attach(9);  // asignamos el pin 9 para el servo.
  //sw.begin(9600);
} 

void loop() {
  if (Serial.available()) {
    char angulo = Serial.read(); //Leemos el dato recibido 
    int con = String(angulo).toInt();
    if(con<=180) //verificamos que sea un valor en el rango del servo
    {
      myservo.write(con*20); //movemos el servomotor al ángulo correspondiente.
      Serial.print (con*20);
    }
  }
  
}
