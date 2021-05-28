#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <iostream>

using namespace std;

class Usuario{
private:

    friend istream & operator>>(istream &entrada, Usuario &u);
    friend ostream & operator<<(ostream &salida, const Usuario &u);

    char *dni;
	char *nombre;
	char *pass;
public:
    Usuario();
	Usuario(char *dni, char *nombre,char* contrasenya);
	Usuario(Usuario &u);
	char * getDni() const {return dni;}
    char * getNombre() const {return nombre;}
    char * getPass() const {return pass;}
	void setNombre(char *n);
	void setDni(char *d);
	void setPass(char *c);
	virtual ~Usuario();
};

#endif // USUARIO_H_INCLUDED
