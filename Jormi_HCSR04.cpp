#include "Arduino.h"
#include "Jormi_HCSR04.h"


/*
	Constructor
*/
Jormi_HCSR04::Jormi_HCSR04(byte pinEcho, byte pinTrigger)
{
	_pinEcho = pinEcho;
	_pinTrigger = pinTrigger;
	_distancia = 0;
	
	pinMode(_pinTrigger, OUTPUT);
	pinMode(_pinEcho, INPUT);   
}


/*
	Distancia
	Devuelve la distancia leida
	
	return
		int cms
		-1	si error de distancia
*/
int Jormi_HCSR04::distancia()
{
	return _distancia;
}
	
	
/*
	Update
*/
void Jormi_HCSR04::update()
{	
	long duration;
   
	digitalWrite(_pinTrigger, LOW);  		//para generar un pulso limpio ponemos a LOW 4us
	delayMicroseconds(4);
	digitalWrite(_pinTrigger, HIGH);  		//generamos Trigger (disparo) de 10us
	delayMicroseconds(10);
	digitalWrite(_pinTrigger, LOW);
   
	duration = pulseIn(_pinEcho, HIGH);  	//medimos el tiempo entre pulsos, en microsegundos
   
	_distancia = duration * 10 / 292/ 2;   	//convertimos a distancia, en cm
	
	if( _distancia > 400 || _distancia < 0 )
		_distancia = -1;					//control de error, devuelve -1
}


/*
	Información
	Muestra en ventana de depuración info de las variables
*/
void Jormi_HCSR04::informacion()
{
	Serial.print("Jormi_HCSR04\t_pinEcho\t\t\t = \t");
	Serial.println(_pinEcho);						
	Serial.print("Jormi_HCSR04\t_pinTrigger\t\t\t = \t");
	Serial.println(_pinTrigger);					
	Serial.print("Jormi_HCSR04\t_distancia\t\t\t = \t");
	Serial.println(_distancia);					
		
}