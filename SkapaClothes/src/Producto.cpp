#include "Producto.h"
#include <string.h>

using namespace std;

Producto::Producto()
{
    id = 0;
    nombre = new char[20];
    marca = new char[20];
    color = new char[20];
    precio = 0;
}

Producto::Producto(const char *nombre, const char *marca, const char *color, const float precio)
{

	this->nombre = new char [strlen(nombre) + 1];
	strcpy(this->nombre, nombre);

	this->marca = new char [strlen(marca) + 1];
	strcpy(this->marca, marca);

	this->color = new char [strlen(color) + 1];
	strcpy(this->color, color);

	this->precio = precio;
}

Producto::Producto(int id, const char *nombre, const char *marca, const char *color, const float precio)
{

    this->id = id;

	this->nombre = new char [strlen(nombre) + 1];
	strcpy(this->nombre, nombre);

	this->marca = new char [strlen(marca) + 1];
	strcpy(this->marca, marca);

	this->color = new char [strlen(color) + 1];
	strcpy(this->color, color);

	this->precio = precio;
}

Producto::Producto(const Producto & p)
{
	this->nombre = new char [strlen(p.nombre) + 1];
	strcpy(this->nombre, p.nombre);

	this->marca = new char [strlen(p.marca) + 1];
	strcpy(this->marca, p.marca);

	this->color = new char [strlen(p.color) + 1];
	strcpy(this->color, p.color);

	this->precio = p.precio;
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

Producto::~Producto()
{
	delete [] this->nombre;
	delete [] this->marca;
	delete [] this->color;
}
