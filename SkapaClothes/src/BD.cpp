#ifdef __cplusplus
extern "C" {
#include "sqlite3.h"
}
#endif
#include "BD.h"
#include <string.h>
#include "Usuario.h"

using namespace std;

BD::BD(char *n){
	nbd = new char[strlen(n)+1];
	strcpy(nbd, n);
}

void BD::crearBD()
{
    char * err;
	if(sqlite3_open(nbd, &db))
	{
		cout<<"ERROR AL ABRIR LA BD"<<endl;

	}else
	{
		//Por cada tabla que quiera crear hago estas dos l�neas de c�digo
		char * sentencia = "CREATE TABLE IF NOT EXISTS Usuario(dni VARCHAR(10),nombre VARCHAR(20), pass VARCHAR(20));";
		if(sqlite3_exec(db, sentencia, NULL, NULL, &err)!= SQLITE_OK){
        cout<<"ERROR CREANDO LAS TABLAS DE BD "<<err;
		}

	}
}
void BD::abrirBD()
{
	if(sqlite3_open(nbd, &db)!= SQLITE_OK)
    {
		cout<<"ERROR AL INTENTAR ABRIR LA BD"<<endl;
	}

	cout<<"BD CONECTADA"<<endl;
}

int BD::existeUsuario(const char * dni)
{
    char * err;
	int resultado;
	char query[200];

	sprintf(query, "SELECT COUNT(*) FROM Usuario WHERE dni = '%s'", dni);
    sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
    sqlite3_step(stmt);
	resultado = sqlite3_column_int(stmt, 0);//0 es el numero de la columna del dni.
    sqlite3_finalize(stmt);
	return resultado;
}

void BD::insertarUsuario(const Usuario &u)
{
	char query[200];
	int resultado;
	char *err;

	resultado = existeUsuario(u.getDni());

	if(resultado == 0)
	{
        sprintf(query,"INSERT INTO Usuario (dni,nombre,pass) VALUES('%s', '%s' , '%s')", u.getDni(), u.getNombre(), u.getPass());
        sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);

        cout << "Usuario creado correctamente\n" << endl;

	}else {cout<<"ERROR! Ya existe una persona con ese DNI"<<endl;
	}

}

int BD::comprobarLogin(const char *nombre, const char *pass)
{
    /*Devuelve 0 si el nick es incorrecto
    Devuelve 1 si el nick es correcto pero la contrase�a no
    Devuelve 2 si nick y contrase�a son correctos*/

    int resultado = 2,r;
    char query[100];
    sprintf(query,"SELECT * FROM Usuario WHERE nombre='%s'",nombre);
    sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
    r=sqlite3_step(stmt);
    if (r == SQLITE_ROW){
        char* con = (char*) sqlite3_column_text(stmt, 1);
        if(strcmp(con,pass)!=0){
            resultado = 1;
        }
    }else{
        resultado = 0;
    }
    sqlite3_finalize(stmt);
    return resultado;
}
/*Usuario BD::seleccionarUsuario(Usuario u)
{
    char query[100];
		 sprintf(query,"SELECT * FROM Usuario WHERE nombre='%s'",u.nombre);
         sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
         sqlite3_step(stmt);
         sqlite3_finalize(stmt);



	}
}
*/
/*void BD::borrarUsuario(char *dni)
{
	char query[200];
	sqrintf(query, "DELETE FROM Usuario WHERE DNI = '%s'", dni);
	sqlite3_prepare_V2(db, query,strlen(query)+ 1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);

}
*/
/*void BD::mostrarTodasLasPersonas()
{
	char query[200];
	int resul;
	sprintf(query, "SELECT * FROM Persona");
	sqlite3_prepare_V2(db, query, strlen(query)+ 1, &stmt, NULL);


	do
	{
		resul = sqlite3_step(stmt);
		if(resul == SQLITE_ROW)
		{
			char * dni = sqlite3_column_text(stmt, 0);//0 es donde est� el dni
			int edad = sqlite3_column_int(stmt, 1);
			cout<<dni<<""<<edad<<endl;
		}
	}
	while(resul == SQLITE_ROW);
	sqlite3_finalize(stmt);

}
*/
/* BD::modificarEdad(char * dni, int nuevaEdad)
{
	char query[200];
	sprintf(query, "UPDATE Persona SET EDAD %d WHERE DNI = '%s'", nuevaEdad, dni);
	sqlite3_prepare_V2(db, query, strlen(query)+1, &stmt, NULL);//Preparar la sentencia
	sqlite3_step(stmt);//Ejecutar la sentencia
	sqlite3_finalize(stmt); //Finalizar la sentencia asi porque no devuelve nada

} */

BD::~BD() {
    delete[] nbd;
}
