#include <iostream>
#include "BD.h"
#include "Usuario.h"

using namespace std;

void menuInicio(BD *bd, Usuario u);
void menuPrincipal(BD *bd, Usuario u);
void registrarUsuario(BD *bd, Usuario u);
void eliminarCuenta(BD *bd, Usuario u);
void cerrarApp(BD *bd, Usuario u);

int main()
{
    BD *bd = new BD("Skaa.db");
    Usuario u;
    Producto p("b","a", "a", 32);
    bd->crearBD();
    bd->abrirBD();
    bd->insertarProducto(p);
    menuInicio(bd, u);
    return 0;
}

void menuInicio(BD *bd, Usuario u) {

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
        if(intentos >= 3)
        {
            menuInicio(bd,u);
        }
        if(resultado == 0)
        {
            cout<<"El nick no es correcto"<<endl;
        }else if(resultado==1)
        {
            cout<<"Contrasenya incorrecta"<<endl;
        }else if(resultado ==3)
        {
             cout<<"ERROR! No existe nadie con ese nombre de usuario"<<endl;
        }else
        {
            cout<<"Sesion iniciada"<<endl;
            menuPrincipal(bd, u);
        }
    }while(resultado!=2 && intentos<3);
		}
			break;
		case 2: {
			registrarUsuario(bd, u);

		}
			break;
		case 3: {
			cerrarApp(bd, u);
		}
			break;
		default: {
			cout<<"Seleccion invalida, porfavor introduzca uno de los numeros de la derecha"<< endl;
		}
			break;
		}
	} while (eleccion != 1 && eleccion != 2 && eleccion != 3 && eleccion != 4);
}

void menuPrincipal(BD *bd, Usuario u) {

	int eleccion;

	cout << "Buenos dias " << endl;
	cout << "Elija una opcion e introduzca el numero que se encuentre a la izquierda"<< endl;
	cout << "1. Anyadir productos a la cesta" << endl;
	cout << "2. Mostrar mi cesta" << endl;
	cout << "3. Finalizar compra" << endl;
	cout << "4. Eliminar cuenta" << endl;
	cout << "5. Cerrar Sesion" << endl;
	cout << "6. Salir" << endl;


	do {
		cin >> eleccion;

		switch (eleccion) {
		case 1: {
		    bd->mostrarProductos();

		}
			break;
		case 2: {


		}
			break;
		case 3: {

		}
			break;
        case 4:{
            eliminarCuenta(bd, u);
        }
			break;
        case 5:{
            menuInicio(bd, u);
        }
            break;
        case 6:{
             cerrarApp(bd, u);
        }
			break;
		default: {
			cout<<"Seleccion invalida, porfavor introduzca uno de los numeros de la derecha"<< endl;
		}
			break;
		}
	} while (eleccion != 1 && eleccion != 2 && eleccion != 3 && eleccion != 4 && eleccion != 5 && eleccion != 6);
}


void registrarUsuario(BD *bd, Usuario u){
    char nombre[20],pass[20];

	cout << "Introduzca su nombre de usuario" << endl;
	cin >> nombre;
	cout << "Introduzca su contrasenya" << endl;
	cin >> pass;

	u.setNombre(nombre);
	u.setPass(pass);

    bd->insertarUsuario(u);

	menuInicio(bd, u);
}

void eliminarCuenta(BD *bd, Usuario u){

    int eleccion;

	cout << "¿Está seguro de que desea eliminar su cuenta de usuario?" << endl;
	cout << "1. Si, estoy seguro" << endl;
	cout << "2. No, deseo volver atras" << endl;

	do {
		cin >> eleccion;


		switch (eleccion) {
		case 1:{
		    bd->borrarUsuario(u);
			cout << "La aplicación ha sido cerrada correctamente" << endl;
		}
		break;
		case 2:{
			menuPrincipal(bd, u);
		}
		break;
		default:{
			cout << "Por favor, introduza 1 o 2" << endl;
		}
		break;
		}
	} while (eleccion != 1 && eleccion != 2);

}
void cerrarApp(BD *bd, Usuario u){
	//A ésta parte se accede cuando deseas salir de la aplicación

	int eleccion;

	cout << "¿Está seguro de que desea salir de la aplicación?" << endl;
	cout << "1. Si, estoy seguro" << endl;
	cout << "2. No, no deseo salir" << endl;

	do {
		cin >> eleccion;


		switch (eleccion) {
		case 1:{
			cout << "La aplicación ha sido cerrada correctamente" << endl;
			exit(0);
		}
		break;
		case 2:{
			menuInicio(bd, u);
		}
		break;
		default:{
			cout << "Por favor, introduza 1 o 2" << endl;
		}
		break;
		}
	} while (eleccion != 1 && eleccion != 2);
}


