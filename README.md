# Jormi_HC-SR04


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
