#include "Usuario.h"
#include <iostream>
#include <string.h>

using namespace std;

Usuario::Usuario(){
    dni =new char[10];
	nombre =new char[20];
	pass = new char[20];
}
Usuario::Usuario(char *dni,char *nombre,char* pass){

	this->dni = new char [strlen(dni) + 1];
	strcpy(this->dni, dni);

	this->nombre = new char [strlen(nombre) + 1];
	strcpy(this->nombre, nombre);

	this->pass = new char [strlen(pass) + 1];
	strcpy(this->pass, pass);

}
Usuario::Usuario(Usuario &u){

	this->dni = new char [strlen(u.dni) + 1];
	strcpy(this->dni, u.dni);

	this->nombre = new char [strlen(u.nombre) + 1];
	strcpy(this->nombre, u.nombre);

	this->pass = new char [strlen(u.pass) + 1];
	strcpy(this->pass, u.pass);
}

Usuario::~Usuario(){
	delete[] nombre;
	delete[] dni;
	delete[] pass;
}

void Usuario::setNombre(char *n) {
 this->nombre = new char[strlen(n)+1];
 strcpy(nombre,n);
}
void Usuario::setPass(char *p) {
this->pass = new char[strlen(p)+1];
 strcpy(pass,p);
}
void Usuario::setDni(char *d) {
this->dni = new char[strlen(d)+1];
 strcpy(dni,d);
}

istream & operator>>(istream &entrada, Usuario &u){
	entrada>>u.dni;
	entrada>>u.nombre;
	entrada>>u.pass;
	return entrada;
}
ostream & operator<<(ostream &salida, const Usuario &u){
    salida<<u.dni<<" "<<u.nombre<<" "<<u.pass<<endl;
    return salida;
}

