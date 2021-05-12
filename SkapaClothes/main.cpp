#include <iostream>
#include <string.h>
#include "Usuario.h"
#include <fstream>
#include <vector>
#include <utility>	 // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream>
#include <bits/stdc++.h>

using namespace std;


void menuInicio();
int calcularId();
void registrarUsuario();
int iniciarSesion();

int main()
{
     menuInicio();
    return 0;
}

void menuInicio() {

	int eleccion;

	cout << "Bienvenido a la aplicación de Skapa Clothes" << endl;
	cout
			<< "Elija una opción e introduzca el numero que se encuentre a la izquierda"
			<< endl;
	cout << "1.  Iniciar sesión" << endl;
	cout << "2.  Registrarme como nuevo usuario" << endl;
	cout << "3.  Salir de la aplicación" << endl;

	do {
		cin >> eleccion;

		switch (eleccion) {
		case 1: {
			iniciarSesion();
		}
			break;
		case 2: {
			registrarUsuario();
		}
			break;
		case 3: {
			//cerrarApp();
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


int calcularId() {

	ifstream fin;
	int id;
	vector<string> tokens;
	string intermediate;
	string line;
	fin.open("Usuarios.csv");
	while (!fin.eof()) {
		int i = 1;
		fin >> line;
		stringstream check1(line);
		while (getline(check1, intermediate, ',')) {
			tokens.push_back(intermediate);
			switch (i) {
			case 1: {
				i++;
			}
				break;
			case 2: {
				i++;
				stringstream parseid;
				parseid << intermediate;
				parseid >> id;
			}
				break;
			case 3: {
			}
				break;
			default: {
			}
				break;
			}
		}
	}
	id++;
	return id;
}

void registrarUsuario() {
	string nombre, correo, contrasenya, idUsu;
	int id;
	cout << "Introduzca su nombre" << endl;
	cin >> nombre;
	cout << "Introduzca su correo" << endl;
	cin >> correo;
	cout << "Introduzca su contrasenya" << endl;
	cin >> contrasenya;
	id = calcularId();
	stringstream parseid;
	parseid << id;
	parseid >> idUsu;

	std::ofstream fusuarios;

	fusuarios.open("Usuarios.csv", std::ios::app);

	fusuarios << nombre << "," << idUsu << "," << contrasenya << "\n";

	fusuarios.close();

	cout << "Usuario creado correctamente\n" << endl;

	menuInicio();
}

int iniciarSesion() {

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
	iniciarSesion();
	return 0;
}
