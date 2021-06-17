#include "Comprador.h"
#include "Usuario.h"

using namespace std;

Comprador::Comprador():Usuario()
{
	this->dinero = 0;
}

Comprador::Comprador(char *nombre,char* pass):Usuario(nombre,pass)
{


}

Comprador::Comprador(Comprador &c):Usuario(c)
{

}

Comprador::~Comprador()
{
}

void Comprador::setDinero(float d)
{
	this->dinero = d;
}
