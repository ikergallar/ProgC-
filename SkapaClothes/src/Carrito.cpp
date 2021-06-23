#include "iostream"
#include <stdlib.h>
#include "Carrito.h"

using namespace std;

Carrito::Carrito(Cesta *cesta)
{
	this->cesta = cesta;
	this->importe = 0;
}

Carrito::Carrito()
{
	this->cesta = NULL;
	this->importe = 0.0;
}

Carrito::Carrito(Carrito & p)
{
	this->cesta = p.cesta;
	this->importe = p.importe;
}

Carrito::~Carrito()
{
	delete []this->cesta;
}

void Carrito::setCesta (Cesta *c)
{
	this->cesta = c;
}

void Carrito::setImporte (float i)
{
	this->importe = i;
}

void Carrito::imprimirRecibo()
{
    system("cls");

	cout << "RECIBO DEL PEDIDO" << endl;
	cout << "_________________________________" << endl;

	float total = 0.0;
	int cant;

	for (int i = 0; i < this->cesta->getNumProductos(); i++)
    {
		float costoP;
		costoP = this->cesta->getProducto()[i]->getPrecio();

		cant = this->cesta->getCant()[i];

		total = total + (cant * costoP);

		cout << this->cesta->getProducto()[i]->getNombre();
		cout << "    " << costoP  << " Euros";
		cout << "   x" << this->cesta->getCant()[i] << endl;
	}
	this->setImporte(total);

	cout << "__________________________________" << endl;
	cout << "TOTAL: " << total << "  Euros" << endl;
}
