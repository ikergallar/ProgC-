#include "Usuario.h"
#include <iostream>
#include <string.h>

using namespace std;

Usuario::Usuario(char *dni,char *nombre,char* contrasenya){

	this->dni = new char [strlen(dni) + 1];
	strcpy(this->dni, dni);

	this->nombre = new char [strlen(nombre) + 1];
	strcpy(this->nombre, nombre);

	this->contrasenya = new char [strlen(contrasenya) + 1];
	strcpy(this->contrasenya, contrasenya);

}
Usuario::Usuario(Usuario &u){

	this->dni = new char [strlen(u.dni) + 1];
	strcpy(this->dni, u.dni);

	this->nombre = new char [strlen(u.nombre) + 1];
	strcpy(this->nombre, u.nombre);

	this->contrasenya = new char [strlen(u.contrasenya) + 1];
	strcpy(this->contrasenya, u.contrasenya);
}

Usuario::~Usuario(){
	delete[] nombre;
	delete[] dni;
	delete[] contrasenya;
}

char *Usuario::getNomUsuario(){
	return this->nombre;
}
char *Usuario::getDni(){
	return this->dni;
}
char *Usuario::getContrasenya() {
	return this->contrasenya;
}

char *Usuario::setNomUsuario() {
 this->nombre;
}

char *Usuario::setContrasenya() {
this->contrasenya;
}
char *Usuario::setDni() {
this->dni;
}

