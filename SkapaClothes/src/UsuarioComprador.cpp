#include "UsuarioComprador.h"

#include "Usuario.h"

using namespace std;

UsuarioComprador::UsuarioComprador():Usuario()
{
	this->dinero = 0;
}

UsuarioComprador::UsuarioComprador(char *nombre,char* pass):Usuario(nombre,pass)
{


}

UsuarioComprador::UsuarioComprador(UsuarioComprador &u):Usuario(u)
{

}

UsuarioComprador::~UsuarioComprador()
{
}

void UsuarioComprador::setDinero(float d)
{
	this->dinero = d;
}
