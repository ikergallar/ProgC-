#include "Pantalon.h"
#include "string.h"
#include <iostream>

using namespace std;

Pantalon::Pantalon() :Producto()
{
    tipoPantalon = new char[20];
}

Pantalon::Pantalon(const char *nombre, const char *marca, const char *color, const float precio,int id, char* tipoPantalon) :Producto(nombre,marca,color,precio,id)
{
    this->tipoPantalon = new char [strlen(tipoPantalon) + 1];
	strcpy(this->tipoPantalon, tipoPantalon);
}

Pantalon::Pantalon(const Pantalon &p) :Producto(p)
{
    this->tipoPantalon = new char [strlen(tipoPantalon) + 1];
	strcpy(this->tipoPantalon, tipoPantalon);
}

void Pantalon::setTipoPantalon(char *tP)
{
	this->tipoPantalon = new char [strlen(tP) + 1];
	strcpy(this->tipoPantalon, tP);
}

void Pantalon::imprimir()
{
    Producto::imprimir();
    cout<<"Tipo de pantalon:  "<<this->tipoPantalon;
}

Pantalon::~Pantalon()
{
    delete [] this->tipoPantalon;
}
