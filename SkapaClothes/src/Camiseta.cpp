#include "Camiseta.h"
#include "string.h"
#include <iostream>

using namespace std;

Camiseta::Camiseta():Producto()
{
    tipoManga = new char[20];
}

Camiseta::Camiseta(const char *nombre, const char *marca, const char *color, const float precio,int id, char* tipoManga) :Producto(nombre,marca,color,precio,id)
{
    this->tipoManga = new char [strlen(tipoManga) + 1];
	strcpy(this->tipoManga, tipoManga);
}

Camiseta::Camiseta(const Camiseta &c) :Producto(c)
{
    this->tipoManga = new char [strlen(tipoManga) + 1];
	strcpy(this->tipoManga, tipoManga);
}

void Camiseta::setTipoManga(char *tM)
{
	this->tipoManga = new char [strlen(tM) + 1];
	strcpy(this->tipoManga, tM);
}

void Camiseta::imprimir()
{
    Producto::imprimir();
    cout<<"Manga:  "<<this->tipoManga;
}

Camiseta::~Camiseta()
{
    delete [] this->tipoManga;
}
