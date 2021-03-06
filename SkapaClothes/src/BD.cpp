#ifdef __cplusplus
extern "C" {
#include "sqlite3.h"
}
#endif
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include "BD.h"
#include <string.h>
#include "Usuario.h"

using namespace std;

BD::BD(char *n)
{
	nbd = new char[strlen(n)+1];
	strcpy(nbd, n);
}

BD::~BD()
{
    delete[] this->nbd;
}

//METODO PARA CREAR LAS TABLAS DE LA BD
void BD::crearBD()
{
    char * err;
	if(sqlite3_open(nbd, &db))
	{
		cout<<"ERROR AL ABRIR LA BD"<<endl;

	}else
	{
		char * tablaUsuario = "CREATE TABLE IF NOT EXISTS Usuario(id INTEGER PRIMARY KEY AUTOINCREMENT,nombre VARCHAR(20) UNIQUE NOT NULL, pass VARCHAR(20) NOT NULL,dinero FLOAT);";
		if(sqlite3_exec(db, tablaUsuario, NULL, NULL, &err)!= SQLITE_OK){
        cout<<"ERROR CREANDO LA TABLA USUARIO "<<err;
		}

		char * tablaProducto = "CREATE TABLE IF NOT EXISTS Producto(id INTEGER PRIMARY KEY AUTOINCREMENT,nombre VARCHAR(20) NOT NULL, marca VARCHAR(20), color VARCHAR(20), precio FLOAT, idVendedor INTEGER, FOREIGN KEY(idVendedor) REFERENCES Usuario(id));";
		if(sqlite3_exec(db, tablaProducto, NULL, NULL, &err)!= SQLITE_OK){
        cout<<"ERROR CREANDO LA TABLA PRODUCTO "<<err;
		}

		char * tablaCamiseta = "CREATE TABLE IF NOT EXISTS Camiseta(id INTEGER PRIMARY KEY AUTOINCREMENT,nombre VARCHAR(20) NOT NULL, marca VARCHAR(20), color VARCHAR(20), precio FLOAT, idVendedor INTEGER, FOREIGN KEY(idVendedor) REFERENCES Usuario(id), manga VARCHAR(20);";
		if(sqlite3_exec(db, tablaCamiseta, NULL, NULL, &err)!= SQLITE_OK){
        cout<<"ERROR CREANDO LA TABLA PRODUCTO "<<err;
		}

		char * tablaPantalon = "CREATE TABLE IF NOT EXISTS Pantalon(id INTEGER PRIMARY KEY AUTOINCREMENT,nombre VARCHAR(20) NOT NULL, marca VARCHAR(20), color VARCHAR(20), precio FLOAT, idVendedor INTEGER, FOREIGN KEY(idVendedor) REFERENCES Usuario(id), tipo VARCHAR(20);";
		if(sqlite3_exec(db, tablaPantalon, NULL, NULL, &err)!= SQLITE_OK){
        cout<<"ERROR CREANDO LA TABLA PRODUCTO "<<err;
		}

		char * tablaZapatillas = "CREATE TABLE IF NOT EXISTS Zapatillas(id INTEGER PRIMARY KEY AUTOINCREMENT,nombre VARCHAR(20) NOT NULL, marca VARCHAR(20), color VARCHAR(20), precio FLOAT, idVendedor INTEGER, FOREIGN KEY(idVendedor) REFERENCES Usuario(id), pie INTEGER);";
		if(sqlite3_exec(db, tablaZapatillas, NULL, NULL, &err)!= SQLITE_OK){
        cout<<"ERROR CREANDO LA TABLA PRODUCTO "<<err;
		}

	}
}

//METODO PARA CONECTARSE CON LA BD
void BD::abrirBD()
{
	if(sqlite3_open(nbd, &db)!= SQLITE_OK)
    {
		cout<<"ERROR AL INTENTAR ABRIR LA BD"<<endl;
	}
}

//METODO PARA DESCONECTARSE DE LA BD
void BD::cerrarBD()
{
    if(sqlite3_close(db)!=SQLITE_OK)
    {
        cout<<"Error al intentar cerrar la base de datos"<<endl;
    }
}

//METODOS DE LA TABLA USUARIO
int BD::existeUsuario(const char *nombre)
{
	int resultado;
	char query[100];

	sprintf(query, "SELECT COUNT(*) FROM Usuario WHERE nombre = '%s'", nombre);
    sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
    sqlite3_step(stmt);
	resultado = sqlite3_column_int(stmt, 0);//0 es el numero de la columna del dni.
    sqlite3_finalize(stmt);
	return resultado;
}

void BD::insertarUsuario(const Usuario* u)
{
	char query[100];
	int resultado;

	resultado = existeUsuario(u->getNombre());

	if(resultado == 0)
	{
        sprintf(query,"INSERT INTO Usuario (nombre,pass) VALUES('%s' , '%s')",u->getNombre(), u->getPass());
        sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);

        cout << "\n" << endl;
        cout << "Usuario creado correctamente\n" << endl;

	}else {cout<<"ERROR! Ya existe una persona con ese Nombre de usuario"<<endl;
	}
}

int BD::comprobarLogin(const char *nombre, const char *pass)
{
    /*Devuelve 0 si el nick es incorrecto
    Devuelve 1 si el nick es correcto pero la contrase?a no
    Devuelve 2 si nick y contrase?a son correctos
    Devuelve 4 si inicia en modo Administrador*/

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

void BD::mostrarUsuarios()
{
	char query[100];
	int resultado;
	int num = 0;

	sprintf(query, "SELECT * FROM Usuario");
	sqlite3_prepare_v2(db, query, strlen(query)+ 1, &stmt, NULL);

	do
	{
		resultado = sqlite3_step(stmt);
		if(resultado == SQLITE_ROW)
		{
			char * nombre = (char *)sqlite3_column_text(stmt, 1);
			char * pass = (char *)sqlite3_column_text(stmt, 2);

            cout<<num<< ". "<<nombre<<", "<<pass<<endl;
            num++;
		}
	}
	while(resultado == SQLITE_ROW);
	sqlite3_finalize(stmt);
}

int BD::cantidadUsuario()
{
	char query[100];
	int resultado = 0;

	sprintf(query, "SELECT COUNT(*) FROM Usuario");
	sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
    if(sqlite3_step(stmt) == SQLITE_ROW){
        resultado = sqlite3_column_int(stmt,0);
    }

    sqlite3_finalize(stmt);

	return resultado;
}

Usuario* BD::seleccionarUsuario(int posicion)
{
	char query[100];
	int resultado;
	Usuario *usuarios = new Usuario[cantidadUsuario()];
	int num = 0;

	sprintf(query, "SELECT * FROM Usuario");
	sqlite3_prepare_v2(db, query, strlen(query)+ 1, &stmt, NULL);

	do
	{
		resultado = sqlite3_step(stmt);
		if(resultado == SQLITE_ROW)
		{
            int id = sqlite3_column_int(stmt, 0);
			char *nombre = (char *)sqlite3_column_text(stmt, 1);
			char *pass = (char *)sqlite3_column_text(stmt, 2);

            usuarios[num].setId(id);
            usuarios[num].setNombre(nombre);
            usuarios[num].setPass(pass);

			num++;
		}
	}
	while(resultado == SQLITE_ROW);
	sqlite3_finalize(stmt);

	Usuario* u = new Usuario(usuarios[posicion]);

	delete [] usuarios;

	return u;
}

Usuario* BD::seleccionarUsuarioIniciado(char *nombre)
{
	char query[100];
	int resultado;
	Usuario *u = new Usuario();

	sprintf(query, "SELECT * FROM Usuario WHERE nombre = '%s'",nombre);
	sqlite3_prepare_v2(db, query, strlen(query)+ 1, &stmt, NULL);

	do
	{
		resultado = sqlite3_step(stmt);
		if(resultado == SQLITE_ROW)
		{
            int id = sqlite3_column_int(stmt, 0);
			char *nombre = (char *)sqlite3_column_text(stmt, 1);
			char *pass = (char *)sqlite3_column_text(stmt, 2);

            u->setId(id);
            u->setNombre(nombre);
            u->setPass(pass);
		}
	}
	while(resultado == SQLITE_ROW);
	sqlite3_finalize(stmt);

	return u;
}

void BD::borrarUsuario(const Usuario* u)
{
	char query[100];
    sprintf(query,"DELETE FROM Usuario WHERE nombre='%s'",u->getNombre());
	sqlite3_prepare_v2(db, query,strlen(query)+ 1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
    cout << "\n" << endl;
    cout << "La cuenta ha sido eliminada correctamente\n" << endl;

}

void BD::editarUsuario(const Usuario* u)
{
	char query[100];
    sprintf(query,"UPDATE Usuario SET pass='%s' WHERE nombre = '%s'",u->getPass(),u->getNombre());
	sqlite3_prepare_v2(db, query,strlen(query)+ 1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
    cout << "\n" << endl;
    cout << "La cuenta ha sido editada correctamente\n" << endl;
}

//METODOS DE LA TABLA PRODUCTO
int BD::existeProducto(const char *nombre, const char *marca,const char *color, const float precio)
{
	char query[200];

	sprintf(query, "SELECT COUNT(*) FROM Producto WHERE nombre = '%s' and marca= '%s' and color = '%s' and precio = '%f'", nombre,marca,color,precio);
    sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
    sqlite3_step(stmt);
	int resultado = sqlite3_column_int(stmt, 0);//0 es el numero de la columna.
    sqlite3_finalize(stmt);
	return resultado;
}

void BD::insertarProducto(const Producto &p)
{
	char query[200];
	int resultado = existeProducto(p.getNombre(),p.getMarca(),p.getColor(),p.getPrecio());

	if(resultado == 0)
	{

        sprintf(query,"INSERT INTO Producto (nombre,marca,color,precio,idVendedor) VALUES('%s','%s','%s','%f','%d')",p.getNombre(), p.getMarca(), p.getColor(), p.getPrecio(),p.getIdVendedor());

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
	char query[100];
	int resultado = 0;

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

	sprintf(query, "SELECT * FROM Producto");
	sqlite3_prepare_v2(db, query, strlen(query)+ 1, &stmt, NULL);

	do
	{
		resultado = sqlite3_step(stmt);
		if(resultado == SQLITE_ROW)
		{
			char *nombre = (char *)sqlite3_column_text(stmt, 1);
            char *marca = (char *)sqlite3_column_text(stmt, 2);
			char *color = (char *)sqlite3_column_text(stmt, 3);
			float precio = (float)sqlite3_column_double(stmt, 4);

            cout<<num<< ". "<<nombre<<", "<<marca<<", "<<color<<", "<<precio<<endl;
            num++;
		}
	}
	while(resultado == SQLITE_ROW);
	sqlite3_finalize(stmt);
}

Producto* BD::seleccionarProducto(int posicion)
{
	char query[200];
	int resultado;
	int numProducto = cantidadProducto();
	Producto **productos = new Producto*[numProducto];
	int num = 0;

	sprintf(query, "SELECT * FROM Producto");
	sqlite3_prepare_v2(db, query, strlen(query)+ 1, &stmt, NULL);

	do
	{
		resultado = sqlite3_step(stmt);
		if(resultado == SQLITE_ROW)
		{
            int id = sqlite3_column_int(stmt, 0);
			char *nombre = (char *)sqlite3_column_text(stmt, 1);
			char *marca = (char *)sqlite3_column_text(stmt, 2);
			char *color = (char *)sqlite3_column_text(stmt, 3);
			float precio = (float)sqlite3_column_double(stmt, 4);

			productos[num] = new Producto(id,nombre,marca,color,precio);

			num++;

		}
	}
	while(resultado == SQLITE_ROW);
	sqlite3_finalize(stmt);

	return productos[posicion];

}

void BD::mostrarProductoDeVendedor(int id)
{
	char query[200];
	int resultado;

	int num = 0;

	sprintf(query, "SELECT * FROM Producto WHERE idVendedor ='%d'",id);
	sqlite3_prepare_v2(db, query, strlen(query)+ 1, &stmt, NULL);

	do
	{
		resultado = sqlite3_step(stmt);
		if(resultado == SQLITE_ROW)
		{
			char *nombre = (char *)sqlite3_column_text(stmt, 1);
			char *marca = (char *)sqlite3_column_text(stmt, 2);
			char *color = (char *)sqlite3_column_text(stmt, 3);
			float precio = (float)sqlite3_column_double(stmt, 4);

			cout<<num<< ". "<<nombre<<", "<<marca<<", "<<color<<", "<<precio<<endl;
            num++;

		}
	}
	while(resultado == SQLITE_ROW);
	sqlite3_finalize(stmt);

}

Producto* BD::seleccionarProductoDeVendedor(int posicion,int id)
{
	char query[200];
	int resultado;
	int numProducto = cantidadProducto();
	Producto **productos = new Producto*[numProducto];
	int num = 0;

	sprintf(query, "SELECT * FROM Producto WHERE idVendedor ='%d'",id);
	sqlite3_prepare_v2(db, query, strlen(query)+ 1, &stmt, NULL);

	do
	{
		resultado = sqlite3_step(stmt);
		if(resultado == SQLITE_ROW)
		{
            int id = sqlite3_column_int(stmt, 0);
			char *nombre = (char *)sqlite3_column_text(stmt, 1);
			char *marca = (char *)sqlite3_column_text(stmt, 2);
			char *color = (char *)sqlite3_column_text(stmt, 3);
			float precio = (float)sqlite3_column_double(stmt, 4);

			productos[num] = new Producto(id,nombre,marca,color,precio);

			num++;

		}
	}
	while(resultado == SQLITE_ROW);
	sqlite3_finalize(stmt);

	return productos[posicion];

}


void BD::borrarProducto(Producto* p)
{
	char query[200];
    sprintf(query,"DELETE FROM Producto WHERE nombre='%s' and marca ='%s' and color= '%s' and precio= %f",p->getNombre(),p->getMarca(),p->getColor(),p->getPrecio());
    sqlite3_prepare_v2(db, query,strlen(query)+ 1, &stmt, NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    cout << "\n" << endl;
    cout << "El producto ha sido eliminado correctamente correctamente\n" << endl;

}

void BD::editarProducto(Producto* p)
{
	char query[200];
    sprintf(query,"UPDATE producto SET nombre='%s', marca='%s', color='%s',precio=%f WHERE id = %d",p->getNombre(),p->getMarca(),p->getColor(),p->getPrecio(),p->getId());
    sqlite3_prepare_v2(db, query,strlen(query)+ 1, &stmt, NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    cout << "\n" << endl;
    cout << "El producto ha sido editado correctamente correctamente\n" << endl;
}

//METODOS DE LA TABLA CAMISETA
int BD::existeCamiseta(const char *nombre, const char *marca,const char *color, const float precio, const char *manga)
{
	char query[200];

	sprintf(query, "SELECT COUNT(*) FROM Camiseta WHERE nombre = '%s' and marca= '%s' and color = '%s' and precio = '%f' and manga ='%s'", nombre,marca,color,precio,manga);
    sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
    sqlite3_step(stmt);
	int resultado = sqlite3_column_int(stmt, 0);//0 es el numero de la columna.
    sqlite3_finalize(stmt);
	return resultado;
}

void BD::insertarCamiseta(const Camiseta &c)
{
	char query[200];
	int resultado = existeCamiseta(c.getNombre(),c.getMarca(),c.getColor(),c.getPrecio(),c.getTipoManga());

	if(resultado == 0)
	{

        sprintf(query,"INSERT INTO Camiseta (nombre,marca,color,precio,idVendedor,manga) VALUES('%s','%s','%s','%f','%d','%s')",c.getNombre(),c.getMarca(),c.getColor(),c.getPrecio(),c.getIdVendedor(),c.getTipoManga());
        sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
        sqlite3_step(stmt);

        sqlite3_finalize(stmt);

        insertarProducto(c);

	}else {
	    cout<<"ERROR! El producto introducido ya existe"<<endl;
	}

}

//METODOS DE LA TABLA PANTALON
int BD::existePantalon(const char *nombre, const char *marca,const char *color, const float precio, const char *tipo)
{
	char query[200];

	sprintf(query, "SELECT COUNT(*) FROM Producto WHERE nombre = '%s' and marca= '%s' and color = '%s' and precio = '%f' and tipo", nombre,marca,color,precio,tipo);
    sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
    sqlite3_step(stmt);
	int resultado = sqlite3_column_int(stmt, 0);//0 es el numero de la columna.
    sqlite3_finalize(stmt);
	return resultado;
}

void BD::insertarPantalon(const Pantalon &p)
{
	char query[200];
	int resultado = existePantalon(p.getNombre(),p.getMarca(),p.getColor(),p.getPrecio(),p.getTipoPantalon());

	if(resultado == 0)
	{

        sprintf(query,"INSERT INTO Pantalon (nombre,marca,color,precio,idVendedor,tipo) VALUES('%s','%s','%s','%f','%d','%s')",p.getNombre(), p.getMarca(), p.getColor(), p.getPrecio(),p.getIdVendedor(),p.getTipoPantalon());

        sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
        sqlite3_step(stmt);

        sqlite3_finalize(stmt);

        insertarProducto(p);

	}else {
	    cout<<"ERROR! El producto introducido ya existe"<<endl;
	}

}

//METODOS DE LA TABLA ZAPATILLAS
int BD::existeZapatillas(const char *nombre, const char *marca,const char *color, const float precio,const int pie)
{
	char query[200];

	sprintf(query, "SELECT COUNT(*) FROM Zapatillas WHERE nombre = '%s' and marca= '%s' and color = '%s' and precio = '%f' and pie = '%d'", nombre,marca,color,precio,pie);
    sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
    sqlite3_step(stmt);
	int resultado = sqlite3_column_int(stmt, 0);//0 es el numero de la columna.
    sqlite3_finalize(stmt);
	return resultado;
}

void BD::insertarZapatillas(const Zapatillas &z)
{
	char query[200];
	int resultado = existeZapatillas(z.getNombre(),z.getMarca(),z.getColor(),z.getPrecio(),z.getNumPie());

	if(resultado == 0)
	{

        sprintf(query,"INSERT INTO Zapatillas (nombre,marca,color,precio,idVendedor,pie) VALUES('%s','%s','%s','%f','%d','%d')",z.getNombre(), z.getMarca(), z.getColor(), z.getPrecio(),z.getIdVendedor(),z.getNumPie());

        sqlite3_prepare_v2(db, query, strlen(query) + 1, &stmt, NULL);
        sqlite3_step(stmt);

        sqlite3_finalize(stmt);

        insertarProducto(z);

	}else {
	    cout<<"ERROR! El producto introducido ya existe"<<endl;
	}

}
