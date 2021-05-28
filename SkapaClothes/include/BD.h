#ifndef BD_H_
#define BD_H_
#ifdef __cplusplus
extern "C" {
#include "sqlite3.h"
}
#endif

#include "usuario.h"

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
    int existeUsuario(const char *dni);
    int comprobarLogin(const char *nombre, const char *pass);
  //  void borrarUsuario(char *dni);//Opción de borrar usuario o producto
   // void mostrarTodasLasPersonas();//Opción de mostrar  todos los usuarios
    //void modificarEdad(char *d, int nuevaEdad);//Opción de hacerla con modificarPrecio
    virtual ~BD();
};
#endif

/* BD_H_ */



