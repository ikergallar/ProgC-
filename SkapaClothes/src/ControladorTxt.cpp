/*
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include "Producto.h"
#include "Usuario.h"

using namespace std;

int importarUsuarios (Usuario * usuarios){
ifstream archivo;
string texto;

archivo.open("../SkapaClothes/Usuarios.csv", ios::in);

if(archivo.fail()){
    cout<<"No se pudo abrir el archivo";
    exit(1);
}

int contador =0;

while(!archivo.eof()){
    getline(archivo, texto);

    Usuario *u = new Usuario();
    string s = texto;

    char nombre;
    char contrasenya;
    char correo;

    int contV=0;
    string parte;

    char separador = ',';
    for(size_t p=0, q=0; p!=s.npos; p=q){
    parte= s.substr(p+(p!=0),(q=s.find(separador, p+1))-p-(p!=0));
         if (contV == 0){
				correo = parte;
			}else if (contV == 1){
				nombre = parte;
			}else if (contV == 2){
				contrasenya = parte;
			}else{
				cout << "ERROR";
			}
			contV++;
		}


        u->setNomUsuario(nombre);
        u->setCorreo(correo);
        u->setContrasenya(contrasenya);

        usuarios[contador]= *u;
        contador++;

    }

archivo.close();

return contador;

}

void exportarUsuarios(Usuario * usuarios, int cantUsuarios){
ofstream archivo;
archivo.open("../SkapaClothes/Usuarios.csv", ios::in);

if(!archivo.fail()){
    cout<<"No se puede abrir el archivo";
    exit(1);
}

for(int i=0; i<cantUsuarios; i++){

        char* nombre = usuarios[i].getNomUsuario();
        char* correo = usuarios[i].getCorreo();
        char* contrasenya = usuarios[i].getContrasenya();

       if(i == cantUsuarios-1) {
        archivo << correo << "," << nombre << "," << contrasenya;

       }else{
           archivo << correo << "," << nombre << "," << contrasenya << endl;
       }

}
archivo.close();

}

int importarStock(Producto * stock){

    ifstream archivo;
    string texto;
    archivo.open();

    if(archivo.fail()){
            cout<<"No se puede abrir el archivo";
    exit(1);
    }

    int cont=0;

    while (!archivo.eof()){
        getline(archivo, texto);

        Producto *p = new Producto();
        string s = texto;

        int id;
        float precio;

        string idS;


    }

}

*/
