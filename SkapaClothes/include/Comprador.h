#ifndef COMPRADOR_H_INCLUDED
#define COMPRADOR_H_INCLUDED

#include "Usuario.h"

class Comprador : public Usuario
{
private:

    float dinero;

public:

    Comprador();
	Comprador(char *nombre,char* contrasenya);
	Comprador(Comprador &u);
    virtual ~Comprador();

    float getDinero() const {return dinero;}
	void setDinero(float d);
};
#endif // COMPRADOR_H_INCLUDED
