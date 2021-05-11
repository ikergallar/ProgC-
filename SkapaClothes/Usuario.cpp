#include "Usuario.h"
#include <iostream>
#include <string.h>

using namespace std;

Usuario::Usuario(const int idUsuario, const char *nombre, const char* correo, const char* contrasenya){

	this->idUsuario=idUsuario;

	this->nombre = new char [strlen(nombre) + 1];
	strcpy(this->nombre, nombre);

	this->correo = new char [strlen(correo) + 1];
	strcpy(this->correo, correo);

	this->contrasenya = new char [strlen(contrasenya) + 1];
	strcpy(this->contrasenya, contrasenya);

}
Usuario::Usuario(Usuario &u){


	this->idUsuario=u.idUsuario;

	this->nombre = new char [strlen(u.nombre) + 1];
	strcpy(this->nombre, u.nombre);

	this->correo = new char [strlen(correo) + 1];
	strcpy(this->correo, correo);

	this->contrasenya = new char [strlen(u.contrasenya) + 1];
	strcpy(this->contrasenya, u.contrasenya);
}

Usuario::~Usuario(){
	delete[] nombre;
	delete[] correo;
	delete[] contrasenya;
}

int Usuario::getIdUsuario() const{
	return this->idUsuario;
}

char* Usuario::getNomUsuario() const{
	return this->nombre;
}
char* Usuario::getCorreo() const{
	return this->correo;
}
char* Usuario::getContrasenya() const{
	return this->contrasenya;
}


