#include "Usuario.h"
#include <iostream>
#include <string.h>

using namespace std;

Usuario::Usuario(){
	nombre =new char[20];
	pass = new char[20];
}
Usuario::Usuario(char *nombre,char* pass){

	this->nombre = new char [strlen(nombre) + 1];
	strcpy(this->nombre, nombre);

	this->pass = new char [strlen(pass) + 1];
	strcpy(this->pass, pass);

}
Usuario::Usuario(Usuario &u){

	this->nombre = new char [strlen(u.nombre) + 1];
	strcpy(this->nombre, u.nombre);

	this->pass = new char [strlen(u.pass) + 1];
	strcpy(this->pass, u.pass);
}

Usuario::~Usuario(){
	delete[] this;
}

void Usuario::setId(int i){
	this->id = i;
}
void Usuario::setNombre(char *n) {
 this->nombre = new char[strlen(nombre)+1];
 strcpy(nombre,n);
}
void Usuario::setPass(char *p) {
this->pass = new char[strlen(pass)+1];
 strcpy(pass,p);
}


istream & operator>>(istream &entrada, Usuario &u){
	entrada>>u.nombre;
	entrada>>u.pass;
	return entrada;
}
ostream & operator<<(ostream &salida, const Usuario &u){
    salida<<u.nombre<<" "<<u.pass<<endl;
    return salida;
}

