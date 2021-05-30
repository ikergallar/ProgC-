#include "iostream"
#include <stdlib.h>
#include "Carrito.h"

Carrito::Carrito(Cesta *cesta, int fecha, float importe)
{
	this->cesta = cesta;
	this->fecha = fecha;
	this->importe = importe;
	this->cantProductos = 0;
}

Carrito::Carrito()
{
	this->cesta = NULL;
	this->fecha = 0.0;
	this->importe = 0.0;
	this->cantProductos = 0;
}

Carrito::Carrito(Carrito & p)
{
	this->cesta = p.cesta;
	this->fecha = p.fecha;
	this->importe = p.importe;
	this->cantProductos = p.cantProductos;
}

Carrito::~Carrito()
{
	delete this;
}

void Carrito::setCesta (Cesta *c)
{
	this->cesta = c;
}

void Carrito::setFecha (int f)
{
	this->fecha = f;
}

void Carrito::setImporte (float i)
{
	this->importe = i;
}

void Carrito::setCantProductos (int cP)
{
	this->cantProductos = cP;
}
