/*
	Jormi_HCSR04.h
	Librería de manejo del sensor ultrasonidos HC-SR04
	v0.1	20210131	Multitask	
*/


#ifndef Jormi_HCSR04_h
#define Jormi_HCSR04_h


class Jormi_HCSR04
{
	
private:
	byte _pinEcho;					//Pin arduino del Echo (input)
	byte _pinTrigger;				//Pin arduino del Trigger (output)
	int _distancia;					//Distancia leida en cms
	
	
public:

/*
	Constructor
*/
Jormi_HCSR04(byte pinEcho, byte pinTrigger);


/*
	Distancia
	Devuelve la distancia leida
	
	return
		int cms
		-1	si error de distancia
*/
int distancia();


/*
	Update
*/
void update();


/*
	Información
	Muestra en ventana de depuración info de las variables
*/
void informacion();


};


#endif
