#ifdef __cplusplus
extern "C" {
#include "sqlite3.h"
}
#endif
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
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
		//Por cada tabla que quiera crear hago estas dos líneas de código
		char * tablaUsuario = "CREATE TABLE IF NOT EXISTS Usuario(id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,nombre VARCHAR(20) PRIMARY KEY NOT NULL, pass VARCHAR(20) NOT NULL);";
		if(sqlite3_exec(db, tablaUsuario, NULL, NULL, &err)!= SQLITE_OK){
        cout<<"ERROR CREANDO LA TABLA USUARIO "<<err;
		}

		char * tablaProducto = "CREATE TABLE IF NOT EXISTS Producto(id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,nombre VARCHAR(20) NOT NULL, tipo VARCHAR(20) NOT NULL, descripcion VARCHAR(25), precio FLOAT);";
		if(sqlite3_exec(db, tablaProducto, NULL, NULL, &err)!= SQLITE_OK){
        cout<<"ERROR CREANDO LAS TABLA PRODUCTO "<<err;
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

int BD::existeUsuario(const char *nombre)
{
    char * err;
	int resultado;
	char query[200];

	sprintf(query, "SELECT COUNT(*) FROM Usuario WHERE nombre = '%s'", nombre);
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

	resultado = existeUsuario(u.getNombre());

	if(resultado == 0)
	{
        sprintf(query,"INSERT INTO Usuario (nombre,pass) VALUES('%s' , '%s')",u.getNombre(), u.getPass());
        sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);

        cout << "Usuario creado correctamente\n" << endl;

	}else {cout<<"ERROR! Ya existe una persona con ese Nombre de usuario"<<endl;
	}

}
int BD::comprobarLogin(const char *nombre, const char *pass)
{
    /*Devuelve 0 si el nick es incorrecto
    Devuelve 1 si el nick es correcto pero la contraseña no
    Devuelve 2 si nick y contraseña son correctos*/

    int resultado = 2,r;
    char query[100];

    if(strcmp(nombre,"admin") == 0 && strcmp(pass,"admin") == 0)
    {
        resultado = 4;
    }else
    {
        sprintf(query,"SELECT * FROM Usuario WHERE nombre='%s'",nombre);
        sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
        r=sqlite3_step(stmt);
        if(r == SQLITE_ROW){
            char* con = (char*) sqlite3_column_text(stmt, 1);
            if(strcmp(con,pass)!=0){
                resultado = 1;
           }
        }else{
            resultado = 0;
        }
        sqlite3_finalize(stmt);
    }
    return resultado;
}

void BD::borrarUsuario(const Usuario u)
{
	char query[200];
    sprintf(query,"DELETE FROM Usuario WHERE nombre='%s'",u.getNombre());
	sqlite3_prepare_v2(db, query,strlen(query)+ 1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
    cout << "Su cuenta ha sido eliminada correctamente\n" << endl;

}

int BD::existeProducto(const char *nombre, const char *tipo, const char *descripcion, const float precio)
{
    char * err;
	int resultado;
	char query[200];

	sprintf(query, "SELECT COUNT(*) FROM Producto WHERE nombre = '%s' and tipo = '%s' and descripcion = '%s' and precio = '%f'", nombre,tipo,descripcion,precio);
    sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
    sqlite3_step(stmt);
	resultado = sqlite3_column_int(stmt, 0);//0 es el numero de la columna.
    sqlite3_finalize(stmt);
	return resultado;
}

void BD::insertarProducto(const Producto &p)
{
	char query[200];
	int resultado;
	char *err;

	resultado = existeProducto(p.getNombre(),p.getTipo(),p.getDescripcion(),p.getPrecio());

	if(resultado == 0)
	{
        sprintf(query,"INSERT INTO Producto (nombre,tipo,descripcion,precio) VALUES('%s','%s','%s','%f')",p.getNombre(), p.getTipo(), p.getDescripcion(), p.getPrecio());
        sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);

        cout << "\n" << endl;
        cout << "Producto anyadido correctamente\n" << endl;

	}else {
	    cout<<"ERROR! El producto introducido ya existe"<<endl;
	}

}

int BD::cantidadProducto()
{
	char query[200];
	int resultado = 0;
	char *err;

	sprintf(query, "SELECT COUNT(*) FROM Producto");
	sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
    if(sqlite3_step(stmt) == SQLITE_ROW){
        resultado = sqlite3_column_int(stmt,0);
    }

    sqlite3_finalize(stmt);

	return resultado;
}

void BD::mostrarProductos()
{
	char query[200];
	int resultado;
	int num = 0;
	int cont = 0;
	int cantProducto = cantidadProducto();

	sprintf(query, "SELECT * FROM Producto");
	sqlite3_prepare_v2(db, query, strlen(query)+ 1, &stmt, NULL);

	do
	{
		resultado = sqlite3_step(stmt);
		if(resultado == SQLITE_ROW)
		{
			char * nombre = (char *)sqlite3_column_text(stmt, 1);
			char * tipo = (char *)sqlite3_column_text(stmt, 2);
			char * descripcion = (char *)sqlite3_column_text(stmt, 3);
			float precio = (float)sqlite3_column_double(stmt, 4);

            cout<<num<< ". "<<nombre<<", "<<tipo<<", "<<descripcion<<", "<<precio<<endl;
            num++;
		}
	}
	while(resultado == SQLITE_ROW);
	sqlite3_finalize(stmt);
}

void BD::borrarProducto(const Producto &p)
{
	char query[200];
	int resultado = existeProducto(p.getNombre(),p.getTipo(),p.getDescripcion(),p.getPrecio());

	if(resultado != 0)
    {
        sprintf(query,"DELETE FROM Producto WHERE nombre='%s' and tipo='%s' and descripcion= '%s' and precio= '%f'",p.getNombre(), p.getTipo(),p.getDescripcion(),p.getPrecio());
	    sqlite3_prepare_v2(db, query,strlen(query)+ 1, &stmt, NULL);
	    sqlite3_step(stmt);
	    sqlite3_finalize(stmt);
	    cout << "\n" << endl;
        cout << "El producto ha sido eliminado correctamente correctamente\n" << endl;
    }else
    cout<<"ERROR! El producto introducido no existe"<<endl;

}

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
