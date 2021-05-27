#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

class Usuario{
public:
    char *dni;
	char *nombre;
	char *contrasenya;

	Usuario(char *dni, char *nombre,char* contrasenya);
	Usuario(Usuario &u);
	virtual ~Usuario();

	char *getNomUsuario();
	char *getDni();
	char *getContrasenya();
	char *setNomUsuario();
	char *setDni();
	char *setContrasenya();
};

#endif // USUARIO_H_INCLUDED
