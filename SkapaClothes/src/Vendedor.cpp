#include "Vendedor.h"

using namespace std;

Vendedor::Vendedor():Usuario()
{
}

Vendedor::Vendedor(char *nombre,char* pass):Usuario(nombre,pass)
{


}

Vendedor::Vendedor(Vendedor &v):Usuario(v)
{

}

Vendedor::~Vendedor()
{
    delete [] this->p;
}

void Vendedor::setProducto(Producto* p)
{
	this->p = p;
}
