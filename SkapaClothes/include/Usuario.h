#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

class Usuario
{
private:

    int id;
	char *nombre;
	char *pass;
	float dinero;

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

	    float getDinero() const {return dinero;}
	void setDinero(float d);
};
#endif // USUARIO_H_INCLUDED
