#ifndef BD_H_
#define BD_H_

#ifdef __cplusplus
extern "C" {
	#include "sqlite3.h"
}
#endif

#include "usuario.h"
#include "Producto.h"

class BD
{
private:

    char *nbd;
    sqlite3 *db;
    sqlite3_stmt *stmt;

public :
    BD(char *nbd);
    void crearBD();
    void abrirBD();
    void cerrarBD();
    virtual ~BD();


    int existeUsuario(const char *nombre);
    void insertarUsuario(const Usuario* u);
    int comprobarLogin(const char *nombre, const char *pass);
    void mostrarUsuarios();
    void borrarUsuario(const Usuario* u);
    int cantidadUsuario();
    Usuario* seleccionarUsuario(int posicion);

    int existeProducto(const char *nombre, const char *marca, const char *descripcion, float precio);
    int cantidadProducto();
    void insertarProducto(const Producto &p);
    void mostrarProductos();
    void borrarProducto(Producto* p);
    Producto* seleccionarProducto(int posicion);
};
#endif
/* BD_H_ */
