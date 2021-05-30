#include "Cesta.h"

Cesta::Cesta(Producto *p, int cant){
	this->p = p;
	this->cant = cant;
}

Cesta::Cesta(){
	Producto *p = new Producto ();
	this->p = p;
	this->cant = 0;
}

Cesta::Cesta(Cesta & c){
	this->p = c.p;
	this->cant = c.cant;
}

Cesta::~Cesta(){
	delete this;
}

void Cesta::setProducto (Producto* p){
	this->p = p;
}
void Cesta::setCant (int cant){
	this->cant = cant;
}
