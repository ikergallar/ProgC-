#ifndef COMPRADOR_H_INCLUDED
#define COMPRADOR_H_INCLUDED

#include "Usuario.h"
#include "Producto.h"
class Comprador : public Usuario
{
private:

     Producto* p;

public:

    Comprador();
	Comprador(char *nombre,char* contrasenya);
	Comprador(Comprador &u);
    virtual ~Comprador();


};
#endif // COMPRADOR_H_INCLUDED
