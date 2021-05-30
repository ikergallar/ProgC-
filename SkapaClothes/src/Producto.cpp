#include "iostream"
#include <stdlib.h>
#include <cstring>
#include "Producto.h"

using namespace std;

Producto::Producto(char *nombre, char *tipo, char *descripcion, float precio)
{
	this->nombre = new char [strlen(nombre) + 1];
	strcpy(this->nombre, nombre);

	this->tipo = new char [strlen(tipo) + 1];
	strcpy(this->tipo, tipo);

	this->descripcion = new char [strlen(descripcion) + 1];
	strcpy(this->descripcion, descripcion);

	this->precio = precio;
}

Producto::Producto()
{
    nombre = new char[20];
    tipo = new char[20];
    descripcion = new char[20];
    precio = 0;

}

Producto::Producto(Producto & p)
{
	this->nombre = new char [strlen(p.nombre) + 1];
	strcpy(this->nombre, p.nombre);

	this->tipo = new char [strlen(p.tipo) + 1];
	strcpy(this->tipo, p.tipo);

	this->descripcion = new char [strlen(p.descripcion) + 1];
	strcpy(this->descripcion, p.descripcion);

	this->precio = p.precio;
}

Producto::~Producto()
{
	delete this;
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

void Producto::setTipo(char *t)
{
	this->tipo = new char [strlen(tipo) + 1];
	strcpy(this->tipo, t);
}

void Producto::setDescripcion(char *d)
{
	this->descripcion = new char [strlen(descripcion) + 1];
	strcpy(this->descripcion, d);
}

void Producto::setPrecio(float p)
{
	this->precio = p;
}
