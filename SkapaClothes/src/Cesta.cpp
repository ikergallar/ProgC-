#include "Cesta.h"
#include <iostream>
#include <string.h>

using namespace std;

Cesta::Cesta(){
	this->p = p;
	this->cant = 0;
}

Cesta::Cesta(Producto* p, int cant){
	this->p = p;
	this->cant = cant;
}

Cesta::Cesta(Cesta & c){
	this->p = c.p;
	this->cant = c.cant;
}

Cesta::~Cesta(){
	delete []this->p;
}

void Cesta::setProducto (Producto* p){
	this->p = p;
}
void Cesta::setCant (int cant){
	this->cant = cant;
}
