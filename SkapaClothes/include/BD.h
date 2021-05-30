#ifndef BD_H_
#define BD_H_
#ifdef __cplusplus
extern "C" {
#include "sqlite3.h"
}
#endif

#include "usuario.h"
#include "Producto.h"

using namespace std;

class BD
{
private:

    char *nbd;
    sqlite3 *db;
    sqlite3_stmt *stmt;

public :
    BD(char *nbd);
    void crearBD();
    void insertarUsuario(const Usuario &u);
    void abrirBD();
    int existeUsuario(const char *nombre);
    int comprobarLogin(const char *nombre, const char *pass);
    void borrarUsuario(const Usuario u);
    Usuario seleccionarUsuario(Usuario u);
    int existeProducto(const char *nombre, const char *tipo, const char *descripcion, float precio);
    int cantidadProducto();
    void insertarProducto(const Producto &p);
    void mostrarProductos();
    void borrarProducto(const Producto &p);
    Producto seleccionarProducto(int posicion);
    //void modificarEdad(char *d, int nuevaEdad);//Opción de hacerla con modificarPrecio
    virtual ~BD();
};
#endif

/* BD_H_ */



