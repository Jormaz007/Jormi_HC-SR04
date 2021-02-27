#include <Jormi_Depura.h>
#include <Arduino.h>
#include <Jormi_HCSR04.h>


Jormi_Depura mensaje();
Jormi_HCSR04 sensor(9, 8);

void setup() {
  Serial.begin(9600);
  
  Serial.println("Jormi_HCSR04 ejemplo");
  
  sensor.informacion();     
}

void loop() {
  
	sensor.update();
	
	Serial.print("Distancia: \t\t");
	Serial.println(sensor.distancia());
	delay(500);
}