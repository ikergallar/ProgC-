#include "iostream"
#include <stdlib.h>
#include <cstring>
#include "Producto.h"

using namespace std;

Producto::Producto(char *nombre, char *m, char *color, float precio)
{
	this->nombre = new char [strlen(nombre) + 1];
	strcpy(this->nombre, nombre);

	this->marca = new char [strlen(m) + 1];
	strcpy(this->marca, m);

	this->color = new char [strlen(color) + 1];
	strcpy(this->color, color);

	this->precio = precio;
}

Producto::Producto()
{
    nombre = new char[25];
    marca = new char[25];
    color = new char[25];
    precio = 0;

}

Producto::Producto(Producto & p)
{
	this->nombre = new char [strlen(p.nombre) + 1];
	strcpy(this->nombre, p.nombre);

	this->marca = new char [strlen(p.marca) + 1];
	strcpy(this->marca, p.marca);

	this->color = new char [strlen(p.color) + 1];
	strcpy(this->color, p.color);

	this->precio = p.precio;
}

Producto::~Producto()
{
	delete [] this->nombre;
	delete [] this->marca;
	delete [] this->color;

}

void Producto::setId(int i)
{
	this->id = i;
}

void Producto::setNombre(char *n)
{
	this->nombre = new char [strlen(nombre) + 1];
	strcpy(this->nombre, n);
}

void Producto::setMarca(char *m)
{
	this->marca = new char [strlen(marca) + 1];
	strcpy(this->marca, m);
}

void Producto::setColor(char *d)
{
	this->color = new char [strlen(color) + 1];
	strcpy(this->color, d);
}

void Producto::setPrecio(float p)
{
	this->precio = p;
}
