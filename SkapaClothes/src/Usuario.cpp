#include "Usuario.h"
#include <string.h>

using namespace std;

Usuario::Usuario()
{
	nombre =new char[20];
	pass = new char[20];
    this->dinero = 0;

}

Usuario::Usuario(char *nombre,char* pass)
{
	this->nombre = new char [strlen(nombre) + 1];
	strcpy(this->nombre, nombre);

	this->pass = new char [strlen(pass) + 1];
	strcpy(this->pass, pass);

}

Usuario::Usuario(Usuario &u)
{
	this->nombre = new char [strlen(u.nombre) + 1];
	strcpy(this->nombre, u.nombre);

	this->pass = new char [strlen(u.pass) + 1];
	strcpy(this->pass, u.pass);
}

void Usuario::setId(int i)
{
	this->id = i;
}

void Usuario::setNombre(char *n)
{
    this->nombre = new char[strlen(nombre)+1];
    strcpy(nombre,n);
}

void Usuario::setPass(char *p)
{
    this->pass = new char[strlen(pass)+1];
    strcpy(pass,p);
}

Usuario::~Usuario()
{
	delete[] this->nombre;
	delete[] this->pass;
}

void Usuario::setDinero(float d)
{
	this->dinero = d;
}

