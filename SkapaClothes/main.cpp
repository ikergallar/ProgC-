#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "BD.h"
#include "Usuario.h"
#include "Carrito.h"
#include "Producto.h"


using namespace std;

void menuInicio(BD *bd, Usuario u);
void menuPrincipal(BD *bd, Usuario u);
void menuAdmin(BD *bd);
void registrarUsuario(BD *bd, Usuario u);
void eliminarCuenta(BD *bd, Usuario u);
void cerrarApp(BD *bd, Usuario u);
void anyadirProductosCesta (Producto * productos, int cantProductos, BD *bd, Carrito *carrito);

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

	do {

        system("cls");

        cout << "Bienvenido a la aplicacion de Skapa Clothes" << endl;
	    cout << "Elija una opcion e introduzca el numero que se encuentre a la izquierda"<< endl;
	    cout << "1. Iniciar sesion" << endl;
	    cout << "2. Registrarme como nuevo usuario" << endl;
	    cout << "3. Salir de la aplicacion" << endl;

		cin >> eleccion;

		switch (eleccion) {
		case 1: {
		    char nombre[10],pass[10];
		    int intentos = 0, resultado ;
            do{
                cout<<"Introduce nombre de usuario: ";
                cin>> nombre;
                cout<<"Introduce la contrasenya: ";
                cin>> pass;

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
                    }else if(resultado ==4)
                    {
                         menuAdmin(bd);
                    }else
                    {
                        cout<<"Sesion iniciada"<<endl;
                        menuPrincipal(bd, u);
                    }

            }while(resultado!=2 && resultado != 4 && intentos<3);
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

    Producto *productos = new Producto();
    Carrito *carrito = new Carrito();

	int eleccion;


	do {

        system("cls");

        cout << "Buenos dias " << endl;
	    cout << "Elija una opcion e introduzca el numero que se encuentre a la izquierda"<< endl;
	    cout << "1. Anyadir productos a la cesta" << endl;
	    cout << "2. Mostrar mi cesta" << endl;
	    cout << "3. Finalizar compra" << endl;
	    cout << "4. Eliminar cuenta" << endl;
	    cout << "5. Cerrar Sesion" << endl;
	    cout << "6. Salir" << endl;

		cin >> eleccion;

		switch (eleccion) {
		case 1: {
		    cout << "-----PRODUCTOS DISPONIBLES-----" << endl;
		    bd->mostrarProductos();
		    anyadirProductosCesta(productos, 0, bd, carrito);

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

void menuAdmin(BD *bd){
    int eleccion;
	char c;

	do{
		system("cls");

		cout << "Gestion de productos" << endl;
		cout << "_____________________________" << endl;
		cout << "1. Mostrar los productos disponibles" << endl;
		cout << "2. Añadir nuevo producto a la tienda" << endl;
		cout << "3. Eliminar producto existente" << endl;
	    cout << "4. Salir" << endl;

		cin >> eleccion;

		switch (eleccion){

		case 1:
        {
			bd->mostrarProductos();
			cout << "Pusla un numero para continuar..." << endl;
			cin >> c;
        }
			break;

		case 2:
        {
		    char nombre[20],tipo[10],descripcion[20];
		    float precio;
            cout<<"Introduzca el nombre del producto: ";
            cin>>nombre;
            cout<<"Introduzca el tipo de producto: ";
            cin>>tipo;
            cout<<"Introduzca la descripcion del producto: ";
            cin>>descripcion;
            cout<<"Introduzca el precio del producto: ";
            cin>>precio;

            Producto p(nombre,tipo,descripcion,precio);

            bd->insertarProducto(p);

            menuAdmin(bd);
        }
			break;

		case 3:
        {
		    bd->mostrarProductos();
		    cout << "Seleccione el producto que desea eliminar" << endl;
            char nombre[20],tipo[10],descripcion[20];
		    float precio;
            cout<<"Introduzca el nombre del producto que desea eliminar: ";
            cin>>nombre;
            cout<<"Introduzca el tipo de producto que desea eliminar: ";
            cin>>tipo;
            cout<<"Introduzca la descripcion del producto que desea eliminar: ";
            cin>>descripcion;
            cout<<"Introduzca el precio del producto que desea elimiar: ";
            cin>>precio;

            Producto p(nombre,tipo,descripcion,precio);

            bd->borrarProducto(p);

            menuAdmin(bd);
        }
			break;
        case 4:
        {
            exit(0);
        }
            break;

		default:
			cout << "Opcion seleccionada incorrecta" << endl;
			break;
		}

	}while (eleccion != 1 && eleccion != 2 && eleccion != 3 && eleccion != 4 && eleccion != 5);
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
			cout << "Su cuenta ha sido eliminada correctamente" << endl;
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

void anyadirProductosCesta (Producto * productos, int cantProductos, BD *bd, Carrito *carrito){

	system ("cls");

    bd->mostrarProductos();

	int p;
	int cant;

	cout << "NUMERO del producto: ";
	cin >> p;
	cout << "CANTIDAD de " << productos[p-1].getTipo() << "s " ;
	cin >> cant;

	if (p <= cantProductos && p> 0 ){

		cout << "INFO: " <<productos[p-1].getDescripcion();
		cout << endl;
		int s;

		do{

			cout << "¿Esta seguro que desea agregarlo a la cesta?" << endl;
			cout << "1. Si"<< endl;
			cout << "2. No" << endl;
			cin >> s;

			if (s == 1){
				Producto *pc =  new Producto(productos[p-1]);

				pc[carrito->getCantProductos()] = *pc;
				carrito->setCesta(pc);
				carrito->setCantProductos(carrito->getCantProductos() + 1);

			}else if (s == 2){
				cout << "Operacion cancelada" << endl;

			}else{
				cout << "Opcion seleccionada incorrecta" << endl;
			}
		}while (s != 1 && s!= 2);


	}else{
		cout << "Opcion mal introducida" << endl;
	}



}


