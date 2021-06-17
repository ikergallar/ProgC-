#include "UsuarioVendedor.h"

using namespace std;

UsuarioVendedor::UsuarioVendedor():Usuario()
{
    this->PrecioProducto = 0;
}

UsuarioVendedor::UsuarioVendedor(char *nombre,char* pass):Usuario(nombre,pass)
{


}

UsuarioVendedor::UsuarioVendedor(UsuarioVendedor &uv):Usuario(uv)
{

}

UsuarioVendedor::~UsuarioVendedor()
{
    delete [] this->p;
}

void UsuarioVendedor::setProducto(Producto* p)
{
	this->p = p;
}


void UsuarioVendedor::setPrecioProducto(float pre)
{
	this->PrecioProducto = pre;
}
