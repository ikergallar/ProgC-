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

int calcularId();
void registrarUsuario();
int iniciarSesion();

int main()
{
    int iniciarSesion();
    return 0;
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
