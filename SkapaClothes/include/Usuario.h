#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <iostream>

using namespace std;

class Usuario
{
private:

    friend istream & operator>>(istream &entrada, Usuario &u);
    friend ostream & operator<<(ostream &salida, const Usuario &u);

    int id;
	char *nombre;
	char *pass;

public:
    Usuario();
	Usuario(char *nombre,char* contrasenya);
	Usuario(Usuario &u);
    virtual ~Usuario();

	int getId() const {return id;}
    char * getNombre() const {return nombre;}
    char * getPass() const {return pass;}

    void setId(int i);
	void setNombre(char *n);
	void setPass(char *c);
};
#endif // USUARIO_H_INCLUDED
