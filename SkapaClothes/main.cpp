#include <iostream>
#include "BD.h"
#include "Usuario.h"

using namespace std;

void menuInicio(BD *bd);
void registrarUsuario(BD *bd);
void cerrarApp(BD *bd);

int main()
{
    BD *bd = new BD("Skaa.db");
    bd->crearBD();
    bd->abrirBD();
    menuInicio(bd);
    return 0;
}

void menuInicio(BD *bd) {

	int eleccion;

	cout << "Bienvenido a la aplicacion de Skapa Clothes" << endl;
	cout << "Elija una opcion e introduzca el numero que se encuentre a la izquierda"<< endl;
	cout << "1. Iniciar sesion" << endl;
	cout << "2. Registrarme como nuevo usuario" << endl;
	cout << "3. Salir de la aplicacion" << endl;

	do {
		cin >> eleccion;

		switch (eleccion) {
		case 1: {
		    char nombre[10],pass[10];
		    int intentos = 0, resultado ;
			 do{
        cout<<"Introduce nombre de usuario: ";
        cin>>nombre;
        cout<<"Introduce la contraseña: ";
        cin>>pass;
        intentos++;
        resultado = bd->comprobarLogin(nombre,pass);
        if(resultado == 0)
            cout<<"El nick no es correcto"<<endl;
        else if(resultado==1)
            cout<<"Contreña incorrecta"<<endl;
        else
            cout<<"Sesion iniciada"<<endl;
    }while(resultado!=2 && intentos<3);
		}
			break;
		case 2: {
			registrarUsuario(bd);

		}
			break;
		case 3: {
			cerrarApp(bd);
		}
			break;
		default: {
			cout<<"Seleccion invalida, porfavor introduzca uno de los numeros de la derecha"<< endl;
		}
			break;
		}
	} while (eleccion != 1 && eleccion != 2 && eleccion != 3 && eleccion != 4);
}

void menuPrincipal(BD *bd) {

	int eleccion;

	cout << "Buenos dias " << endl;
	cout << "Elija una opcion e introduzca el numero que se encuentre a la izquierda"<< endl;
	cout << "1. " << endl;
	cout << "2. " << endl;
	cout << "3. " << endl;
	cout << "4. Eliminar cuenta" << endl;


	do {
		cin >> eleccion;

		switch (eleccion) {
		case 1: {

		}
			break;
		case 2: {


		}
			break;
		case 3: {

		}
			break;
		default: {
			cout<<"Seleccion invalida, porfavor introduzca uno de los numeros de la derecha"<< endl;
		}
			break;
		}
	} while (eleccion != 1 && eleccion != 2 && eleccion != 3 && eleccion != 4);
}


void registrarUsuario(BD *bd){
    char dni[10],nombre[10],pass[10];

	cout << "Introduzca su dni" << endl;
	cin >> dni;
	cout << "Introduzca su nombre" << endl;
	cin >> nombre;
	cout << "Introduzca su contrasenya" << endl;
	cin >> pass;

	Usuario u(dni,nombre,pass);
    bd->insertarUsuario(u);

	menuInicio(bd);
}
void cerrarApp(BD *bd){
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
			menuInicio(bd);
		}
		break;
		default:{
			cout << "Por favor, introduza 1 o 2" << endl;
		}
		break;
		}
	} while (eleccion != 1 && eleccion != 2);
}


