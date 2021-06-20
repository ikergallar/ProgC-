#include "Zapatillas.h"
#include "string.h"
#include <iostream>

using namespace std;

Zapatillas::Zapatillas() :Producto()
{
    numPie = 0;
}

Zapatillas::Zapatillas(const char *nombre, const char *marca, const char *color, const float precio,int id, int numPie) :Producto(nombre,marca,color,precio,id)
{
   this->numPie = numPie;
}

Zapatillas::Zapatillas(const Zapatillas &z) :Producto(z)
{
    this->numPie = z.numPie;
}

void Zapatillas::setNumPie(int nP)
{
	this->numPie = nP;

}

void Zapatillas::imprimir()
{
    Producto::imprimir();
    cout<<"Numero de pie:  "<<this->numPie;
}

Zapatillas::~Zapatillas()
{
}
