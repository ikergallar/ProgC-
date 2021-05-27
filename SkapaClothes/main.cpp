#include <iostream>
#include <string.h>
#include "Usuario.h"
#include "BD.h"
#include <fstream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

void menuInicio();
void insertarUsuario();
int comprobarLogin();
void cerrarApp();
BD bd("BaseDeDatos.db");

int main()
{
     menuInicio();
    return 0;
}

void menuInicio() {

	int eleccion;

	cout << "Bienvenido a la aplicación de Skapa Clothes" << endl;
	cout << "Elija una opción e introduzca el numero que se encuentre a la izquierda"<< endl;
	cout << "1.  Iniciar sesión" << endl;
	cout << "2.  Registrarme como nuevo usuario" << endl;
	cout << "3.  Salir de la aplicación" << endl;

	do {
		cin >> eleccion;

		switch (eleccion) {
		case 1: {
			//iniciarSesion();
		}
			break;
		case 2: {
			insertarUsuario();
		}
			break;
		case 3: {
			cerrarApp();
		}
			break;
		default: {
			cout
					<< "Seleccion invalida, porfavor introduzca uno de los numeros de la derecha"
					<< endl;
		}
			break;
		}
	} while (eleccion != 1 && eleccion != 2 && eleccion != 3 && eleccion != 4);
}

/*void registrarUsuario() {
	string dni, nombre, contrasenya;
	cout << "Introduzca su dni" << endl;
	cin >> dni;
	cout << "Introduzca su nombre" << endl;
	cin >> nombre;
	cout << "Introduzca su contrasenya" << endl;
	cin >> contrasenya;


	std::ofstream fusuarios;

	fusuarios.open("Usuarios.csv", std::ios::app);

	fusuarios << nombre << "," << idUsu << "," << contrasenya << "\n";

	fusuarios.close();

	cout << "Usuario creado correctamente\n" << endl;

	menuInicio();
}
*/
void insertarUsuario(){
    char dni[10],nombre[10],pass[10];

	cout << "Introduzca su dni" << endl;
	cin >> dni;
	cout << "Introduzca su nombre" << endl;
	cin >> nombre;
	cout << "Introduzca su contrasenya" << endl;
	cin >> pass;
    bd.insertarUsuario(dni,nombre,pass);

    cout << "Usuario creado correctamente\n" << endl;

	menuInicio();
}

int comprobarLogin()
{
    char nombre[10],pass[10];
    int intentos = 0, resultado ;
    do{
        cout<<"Introduce nombre de usuario: ";
        cin>>nombre;
        cout<<"Introduce la contraseña: ";
        cin>>pass;
        intentos++;
        resultado = bd.comprobarLogin(nombre,pass);
        if(resultado == 0)
            cout<<"El nick no es correcto"<<endl;
        else if(resultado==1)
            cout<<"Contreña incorrecta"<<endl;
        else
            cout<<"Usuario log"<<endl;
    }while(resultado!=2 && intentos<3);

    return 0;
}

/*int iniciarSesion() {

	ifstream fin;
	string nombre, contrasenya;
	vector<string> tokens;
	string intermediate;
	string line;
	cout << "Introduzca su nombre" << endl;
	cin >> nombre;
	cout << "Introduzca su contrasenya" << endl;
	cin >> contrasenya;
	fin.open("Usuarios.csv");
	while (!fin.eof()) {
		int i = 1;
		fin >> line;
		stringstream check1(line);
		while (getline(check1, intermediate, ',')) {
			tokens.push_back(intermediate);
			switch (i) {
			case 1: {

				if (intermediate.c_str() == nombre) {
					i++;
				}
			}
				break;
			case 2: {

				i++;
			}
				break;
			case 3: {
				if (intermediate.c_str() == contrasenya) {
                    cout << "Inicio de sesion realizado con exito" << endl;

				}
			}
				break;
			default: {
			}
				break;
			}
		}
	}
	cout << "Lo sentimos pero su usuario o contrasenya son incorrectos" << endl;
	menuInicio();
	return 0;
}
*/
void cerrarApp(){
	//A ésta parte se accede cuando deseas salir de la aplicación

	int eleccion;

	cout << "¿Está seguro de que desea salir de la aplicación?" << endl;
	cout << "1.  Si, estoy seguro" << endl;
	cout << "2.  No, no deseo salir" << endl;

	do {
		cin >> eleccion;


		switch (eleccion) {
		case 1:{
			cout << "La aplicación ha sido cerrada correctamente" << endl;
			exit(0);
		}
		break;
		case 2:{
			menuInicio();
		}
		break;
		default:{
			cout << "Por favor, introduza 1 o 2" << endl;
		}
		break;
		}
	} while (eleccion != 1 && eleccion != 2);
}
