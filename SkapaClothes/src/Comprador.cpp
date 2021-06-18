#include "Comprador.h"
#include "Usuario.h"

using namespace std;

Comprador::Comprador():Usuario()
{
}

Comprador::Comprador(char *nombre,char* pass):Usuario(nombre,pass)
{


}

Comprador::Comprador(Comprador &c):Usuario(c)
{

}

Comprador::~Comprador()
{
}

