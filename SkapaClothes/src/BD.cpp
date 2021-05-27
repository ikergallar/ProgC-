
#include "BD.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "sqlite3.h"
using namespace std;

BD::BD(char *nbd){
	nombreBD = new char[strlen(nbd)+1];
	strcpy(nombreBD, nbd);
}

void BD::crearBD()
{
	if(sqlite3_open(nombreBD, &db))
	{
		cout<<"ERROR"<<endl;

	}else
	{
		//Por cada tabla que quiera crear hago estas dos líneas de código
		char * sentencia = "CREATE TABLE USUARIO(DNI CHAR(10),NOMBRE CHAR(20), PASS CHAR(20);";
		sqlite3_exec(db, sentencia, NULL, 0, 0);//Para ejecutar una sentencia, NULL y 0, 0 siempre

	}
}
int BD::abrirBD()
{
	int resultado = sqlite3_open(nombreBD, &db);
	if(resultado!= SQLITE_OK)
		cout<<"ERROR"<<endl;

	return resultado;
}

int BD::existeUsuario(const char * dni)
{
	int resultado;
	char query[200];

	sprintf(query, "SELECT COUNT(*) FROM Usuario WHERE DNI = '%s'", dni);
	sqlite3_prepare_v2(db, query, strlen(query)+1, &stmt, NULL);//Preparar la sentencia
	sqlite3_step(stmt);//Ejecutar la sentencia
	resultado  = sqlite3_column_int(stmt, 0);//0 es el numero de la columna del dni.
	sqlite3_finalize(stmt); //Finalizar la sentencia

	return resultado;
}

void BD::insertarUsuario(char *dni, char *nombre, char *pass)
{
	char query[20];
	int resultado;

	resultado = existeUsuario(dni);

	if(resultado == 0)
	{
        sprintf(query,"INSERT INTO Usuario VALUES('%s', '%s' , '%s')", dni, nombre, pass);//Las cadenas de caracteres van entre comillas simples
		sqlite3_prepare_v2(db, query, strlen(query)+1, &stmt, NULL);//Preparar la sentencia
		sqlite3_step(stmt);//Ejecutar la sentencia
		sqlite3_finalize(stmt); //Finalizar la sentencia asi porque no devuelve nada
	}
	else cout<<"ERROR! Ya existe una persona con ese DNI"<<endl;
}

int BD::comprobarLogin(const char *nombre, const char *pass)
{
    /*Devuelve 0 si el nick es incorrecto
    Devuelve 1 si el nick es correcto pero la contraseña no
    Devuelve 2 si nick y contraseña son correctos*/

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
			char * dni = sqlite3_column_text(stmt, 0);//0 es donde está el dni
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
    delete[] nombreBD;
}
