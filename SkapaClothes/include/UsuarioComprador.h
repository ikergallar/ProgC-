#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include "Usuario.h"

class UsuarioComprador : public Usuario
{
private:

    float dinero;

public:

    UsuarioComprador();
	UsuarioComprador(char *nombre,char* contrasenya);
	UsuarioComprador(UsuarioComprador &u);
    virtual ~UsuarioComprador();

    float getDinero() const {return dinero;}
	void setDinero(float d);
};
#endif // USUARIO_H_INCLUDED
