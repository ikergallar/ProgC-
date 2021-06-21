#include "Cesta.h"
#include <iostream>
#include <string.h>

using namespace std;

Cesta::Cesta(){
	this->numProductos = 0;
    this->cant = 0;
}

Cesta::Cesta(Producto* p, int cant){
	this->productos[this->numProductos] = p;
	this->cant = cant;
	this->numProductos = 0;
}

Cesta::Cesta(Cesta & c){
	this->productos = c.productos;
    this->cant = c.cant;
	this->numProductos = 0;
}

Cesta::~Cesta(){
	delete []this->productos;
}

void Cesta::setProductos(Producto** p){
	this->productos = p;
}

void Cesta::setNumProductos(int numProductos){
	this->numProductos = numProductos;
}

void Cesta::setCant(int c){
	this->cant = c;
}

void Cesta::anadirProducto(Producto* p, int c)
{

	this->productos[this->numProductos] = p;
	this->cant = c;
	this->numProductos++;
}

void Cesta::imprimir()
{
    if (this->numProductos == 0)
    {
		cout << "¡NINGUN PRODUCTO EN SU CESTA!" << endl;

	}else
	{
		cout << "MI CESTA" << endl;
		cout << "_____________" << endl;

		int num = 1;
		float total = 0.0;

		for (int i = 0; i < this->numProductos; i++)
        {
			cout << num << ". " << this->productos[i]->getNombre()<<
                  "    x " << this->cant << endl;
			num++;

			int cantPr = this->cant;
			float valorPr = this->productos[i]->getPrecio();

			total = total + (cantPr * valorPr);

		}

		cout <<"_______________________________________" << endl;
		cout << "TOTAL:         " << total  << " Euros"<< endl;
	}

	int o;
	cout << "Introduce un numero para continuar..." << endl;
	cin >> o;

}

