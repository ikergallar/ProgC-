#ifdef __cplusplus
extern "C" {
#include "sqlite3.h"
}
#endif
class BD{
    sqlite3 *db;
    sqlite3_stmt *stmt;
    char *nombreBD;

public :
    BD(char *nbd);
    //M�todos que tiene que haber en la base de datos
    void crearBD();
    //void insertarPersona(char *dni, int edad);
    int abrirBD();
    /*int existePersona(char *dni);//Opci�n de comprobar si existe persona o producto
    void borrarPersona(char *dni);//Opci�n de borrar usuario o producto
    void mostrarTodasLasPersonas();//Opci�n de mostrar  todos los usuarios
    void modificarEdad(char *d, int nuevaEdad);//Opci�n de hacerla con modificarPrecio*/
    virtual BD();
}
#endif



