#ifndef BD_H_
#define BD_H_
#include "sqlite3.h"
#include "usuario.h"

class BD
{

    sqlite3 *db;
    sqlite3_stmt *stmt;
    char *nombreBD;

public :
    BD(char *nbd);
    //M�todos que tiene que haber en la base de datos
    void crearBD();
    void insertarUsuario(char *dni, char *nombre, char *pass);
    int abrirBD();
    int existeUsuario(const char *dni);
    int comprobarLogin(const char *nombre, const char *pass);
  //  void borrarUsuario(char *dni);//Opci�n de borrar usuario o producto
   // void mostrarTodasLasPersonas();//Opci�n de mostrar  todos los usuarios
    //void modificarEdad(char *d, int nuevaEdad);//Opci�n de hacerla con modificarPrecio
    virtual ~BD();
};
#endif

/* BD_H_ */



