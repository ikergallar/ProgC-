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

UsuarioComprador::UsuarioComprador(UsuarioComprador &u):Usuario(u.nombre,u.pass)
{

}

UsuarioComprador::~UsuarioComprador()
{
	delete dinero;
}
