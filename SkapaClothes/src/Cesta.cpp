#include "Cesta.h"
#include <iostream>
#include <string.h>

using namespace std;

Cesta::Cesta()
{
	this->numProductos = 0;
    this->cant = 0;
}

Cesta::Cesta(Producto* p, int cant)
{
	this->productos[this->numProductos] = p;
	this->cant[this->numProductos] = cant;
	this->numProductos = 0;
}

Cesta::Cesta(Cesta & c)
{
	this->productos = c.productos;
    this->cant = c.cant;
	this->numProductos = 0;
}

Cesta::~Cesta()
{
	delete []this->productos;
	delete []this->cant;
}

void Cesta::setProductos(Producto* p)
{
	this->productos[this->numProductos] = p;
}

void Cesta::setNumProductos(int numProductos)
{
	this->numProductos = numProductos;
}

void Cesta::setCant(int c)
{
    this->cant[this->numProductos] = c;
}

void Cesta::anadirProducto(Producto* p,int c)
{

     if(this->numProductos==0)
    {
        this->productos = new Producto*[1];
        this->productos[0] = p;
        this->cant = new int[1];
        this->cant[0] = c;
        this->numProductos++;
    }else
    {
        //En un array auxiliar copiamos la informaci?n que hab?a en el array de productos
        Producto **aux = new Producto*[this->numProductos];
        int *auxInt = new int[this->numProductos];
        for(int i=0;i<this->numProductos;i++)
        {
            aux[i] = this->productos[i];
            auxInt[i] = this->cant[i];
        }

        delete [] this->productos;
        delete [] this->cant;

        this->productos = new Producto*[this->numProductos+1];
        for(int i=0;i<this->numProductos;i++)
        {
            this->productos[i] = aux[i];
            this->productos[this->numProductos] = p;
            this->cant[i] = auxInt[i];
            this->cant[this->numProductos] = c;

        }
        this->numProductos++;

        delete [] aux;
        delete [] auxInt;
    }

}

float Cesta::imprimir()
{

    float total = 0.0;

    if (this->numProductos == 0)
    {
		cout << "?NINGUN PRODUCTO EN SU CESTA!" << endl;

	}else
	{
		cout << "MI CESTA" << endl;
		cout << "_____________" << endl;

		int num = 1;


		for (int i = 0; i < this->numProductos; i++)
        {
			cout << num << ". " << this->productos[i]->getNombre()<<
                  "    x " << this->cant[i] << endl;
			num++;

			int cantPr = this->cant[i];
			float valorPr = this->productos[i]->getPrecio();

			total = total + (cantPr * valorPr);

		}

		cout <<"_______________________________________" << endl;
		cout << "TOTAL:         " << total  << " Euros"<< endl;
	}

	int o;
	cout << "Introduce un numero para continuar..." << endl;
	cin >> o;

	return total;
}
