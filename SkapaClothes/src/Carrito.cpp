#include "iostream"
#include <stdlib.h>
#include "Carrito.h"

Carrito::Carrito(Producto *cesta, int fecha, float importe){
	this->cesta = cesta;
	this->fecha = fecha;
	this->importe = importe;
	this->cantProductos = 0;
}

Carrito::Carrito(){
	this->cesta = NULL;
	this->fecha = 0.0;
	this->importe = 0.0;
	this->cantProductos = 0;

}

Carrito::~Carrito(){
	delete this;
}

void Carrito::setCesta (Producto *cesta){
	this->cesta = cesta;
}

void Carrito::setFecha (int fecha){
	this->fecha = fecha;
}

void Carrito::setImporte (float importe){
	this->importe = importe;
}

void Carrito::setCantProductos (int cantProductos){
	this->cantProductos = cantProductos;
}
void Carrito::imprimirCesta() const{

}
