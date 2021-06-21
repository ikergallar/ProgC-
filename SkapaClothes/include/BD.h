#ifndef BD_H_
#define BD_H_

#ifdef __cplusplus
extern "C" {
	#include "sqlite3.h"
}
#endif

#include "usuario.h"
#include "Producto.h"
#include "Comprador.h"
#include "Vendedor.h"
#include "Camiseta.h"
#include "Pantalon.h"
#include "Zapatillas.h"


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


    int existeComprador(const char *nombre);
    void insertarComprador(const Comprador* c);
    int comprobarComprador(const char *nombre, const char *pass);

    int existeVendedor(const char *nombre);
    void insertarVendedor(const Vendedor* c);
    int comprobarVendedor(const char *nombre, const char *pass);

    int existeUsuario(const char *nombre);
    void insertarUsuario(const Usuario* u);
    int comprobarLogin(const char *nombre, const char *pass);
    void mostrarUsuarios();
    void borrarUsuario(const Usuario* u);
    void editarUsuario(const Usuario* u);
    int cantidadUsuario();
    Usuario* seleccionarUsuario(int posicion);
    Usuario* seleccionarUsuarioIniciado(char *nombre);

    int existeProducto(const char *nombre, const char *marca, const char *descripcion, float precio);
    int cantidadProducto();
    void insertarProducto(const Producto &p);
    void mostrarProductos();
    void borrarProducto(Producto* p);
    void editarProducto(Producto* p);
    Producto* seleccionarProducto(int posicion);
    void mostrarProductoDeVendedor(int id);

    int existeCamiseta(const char *nombre, const char *marca,const char *color, const float precio, const char *manga);
    void insertarCamiseta(const Camiseta &c);

    int existePantalon(const char *nombre, const char *marca,const char *color, const float precio, const char *tipo);
    void insertarPantalon(const Pantalon &p);

    int existeZapatillas(const char *nombre, const char *marca,const char *color, const float precio, const int numPie);
    void insertarZapatillas(const Zapatillas &z);
};
#endif
/* BD_H_ */
