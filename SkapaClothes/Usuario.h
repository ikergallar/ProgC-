#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

class Usuario{
public:
	int idUsuario;
	char *nombre;
	char *correo;
	char *contrasenya;

	Usuario(const int idUsuario, const char *nombre, const char *correo, const char *contrasenya);
	Usuario(Usuario &u);
	virtual ~Usuario();

	int getIdUsuario() const;
	char* getNomUsuario() const;
	char* getCorreo() const;
	char* getContrasenya() const;
};

#endif // USUARIO_H_INCLUDED
