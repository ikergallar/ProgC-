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


       // u->setNombre(nombre);



    }




}



}


