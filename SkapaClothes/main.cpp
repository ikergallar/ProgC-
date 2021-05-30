#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "BD.h"
#include "Usuario.h"
#include "Producto.h"
#include "Cesta.h"
#include "Carrito.h"


using namespace std;

//MENUS
void menuInicio(BD *bd, Usuario* u,Carrito *carrito);
void menuPrincipal(BD *bd, Usuario* u,Carrito *carrito);
void menuAdmin(BD *bd);
void cerrarApp(BD *bd, Usuario* u,Carrito *carrito);

//METODOS DE USUARIO
void registrarUsuario(BD *bd, Usuario* u,Carrito *carrito);
void eliminarCuenta(BD *bd,Usuario* u,Carrito *carrito);

//METODOS DE PRODUCTO/CARRITO/CESTA
void anyadirProductosCesta (BD *bd, Carrito *carrito,Cesta *cesta,Usuario* u);
void mostrarCesta(BD *bd, Carrito *carrito);
void terminarPedido(BD *bd,Carrito *carrito);

int main()
{
    BD *bd = new BD("Skaa.db");
    Usuario* u = new Usuario();
    Carrito* carrito = new Carrito();
    bd->crearBD();
    bd->abrirBD();
    menuInicio(bd, u,carrito);
    return 0;
}
void menuInicio(BD *bd, Usuario* u,Carrito *carrito)
{
	int eleccion;

    cout << "Bienvenido a la aplicacion de Skapa Clothes" << endl;

	do {

	    cout << "Elija una opcion e introduzca el numero que se encuentre a la izquierda"<< endl;
	    cout << "1. Iniciar sesion" << endl;
	    cout << "2. Registrarme como nuevo usuario" << endl;
	    cout << "3. Salir de la aplicacion" << endl;

		cin >> eleccion;

		switch (eleccion)
		{
		case 1:
        {
		    char nombre[10],pass[10],confPass[10];
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
                    menuInicio(bd,u,carrito);
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
                    menuPrincipal(bd, u,carrito);
                }

            }while(resultado!=2 && resultado != 4 && intentos<3);
		}
			break;
		case 2:
        {
			registrarUsuario(bd,u,carrito);
		}
			break;
		case 3:
        {
			cerrarApp(bd,u,carrito);
		}
			break;
		default:
        {
			cout<<"Seleccion invalida, porfavor introduzca uno de los numeros de la derecha"<< endl;
		}
			break;
		}
	} while (eleccion != 1 && eleccion != 2 && eleccion != 3 && eleccion != 4);
}

void menuPrincipal(BD *bd, Usuario* u,Carrito *carrito)
{
    Producto *productos = new Producto();
    Cesta * cesta = new Cesta();

	int eleccion;

    system("cls");

    cout << "Buenos dias " << u->getNombre()<<endl;

	do {

	    cout << "Elija una opcion e introduzca el numero que se encuentre a la izquierda"<< endl;
	    cout << "1. Anyadir productos a la cesta" << endl;
	    cout << "2. Mostrar mi cesta" << endl;
	    cout << "3. Finalizar compra" << endl;
	    cout << "4. Eliminar cuenta" << endl;
	    cout << "5. Cerrar Sesion" << endl;
	    cout << "6. Salir" << endl;

		cin >> eleccion;

		switch (eleccion)
		{
		case 1:
        {
		    cout << "-----PRODUCTOS DISPONIBLES-----" << endl;
		    bd->mostrarProductos();
		    anyadirProductosCesta(bd,carrito,cesta,u);

		}
			break;
		case 2:
        {
		    mostrarCesta(bd,carrito);
		}
			break;
		case 3:
        {
		    terminarPedido(bd,carrito);
		}
			break;
        case 4:
        {
            eliminarCuenta(bd,u,carrito);
        }
			break;
        case 5:
        {
            menuInicio(bd,u,carrito);
        }
            break;
        case 6:
        {
             cerrarApp(bd,u,carrito);
        }
			break;
		default:
        {
			cout<<"Seleccion invalida, porfavor introduzca uno de los numeros de la derecha"<< endl;
		}
			break;
		}
	} while (eleccion != 1 && eleccion != 2 && eleccion != 3 && eleccion != 4 && eleccion != 5 && eleccion != 6);
}

void menuAdmin(BD *bd)
{
    int eleccion;
	char c;

	do{
		system("cls");

		cout << "BIENVENIDO ADMINISTRADOR" << endl;
		cout << "_____________________________" << endl;
		cout << "1. Mostrar los productos disponibles" << endl;
		cout << "2. Añadir nuevo producto a la tienda" << endl;
		cout << "3. Eliminar producto existente" << endl;
		cout << "4. Eliminar cuenta de usuario" << endl;
	    cout << "5. Salir" << endl;

		cin >> eleccion;

		switch (eleccion)
		{
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
            int resp;
		    bd->mostrarProductos();
		    cout << "Introduzca el numero del producto que desea eliminar" << endl;
            cin>>resp;

            Producto* p = bd->seleccionarProducto(resp);

            bd->borrarProducto(p);

        }
			break;
        case 4:
        {
            int resp;
		    bd->mostrarUsuarios();
		    cout << "Introduzca el numero del usuario que desea eliminar" << endl;
            cin>>resp;

            Usuario* u = bd->seleccionarUsuario(resp);

            bd->borrarUsuario(u);
        }
            break;
        case 5:
        {
            exit(0);
        }

		default:
			cout << "Opcion seleccionada incorrecta" << endl;
			break;
		}

	}while (eleccion != 1 && eleccion != 2 && eleccion != 3 && eleccion != 4 && eleccion != 5);
}

void registrarUsuario(BD *bd, Usuario* u, Carrito *carrito)
{
    char nombre[20],pass[20],confPass[20];

	cout << "Introduzca su nombre de usuario" << endl;
	cin >> nombre;
	cout << "Introduzca su contrasenya" << endl;
	cin >> pass;
	cout<<"Confirme la contrasenya: "<< endl;
    cin>> confPass;

    if(strcmp(pass,confPass) != 0)
    {
        cout<<"Las contraseñas no coinciden: ";
    }else

	u->setNombre(nombre);
	u->setPass(pass);

    bd->insertarUsuario(u);

	menuInicio(bd,u,carrito);
}

void eliminarCuenta(BD *bd, Usuario* u,Carrito *carrito)
{
    int eleccion;

	cout << "¿Está seguro de que desea eliminar su cuenta de usuario?" << endl;
	cout << "1. Si, estoy seguro" << endl;
	cout << "2. No, deseo volver atras" << endl;

	do {
		cin >> eleccion;

		switch (eleccion)
		{
		case 1:
        {
		    bd->borrarUsuario(u);
		}
		break;
		case 2:
        {
			menuPrincipal(bd, u,carrito);
		}
		break;
		default:
        {
			cout << "Por favor, introduza 1 o 2" << endl;
		}
		break;
		}
	} while (eleccion != 1 && eleccion != 2);

}
void cerrarApp(BD *bd, Usuario* u, Carrito *carrito)
{
	int eleccion;

	cout << "¿Está seguro de que desea salir de la aplicación?" << endl;
	cout << "1. Si, estoy seguro" << endl;
	cout << "2. No, no deseo salir" << endl;

	do {
		cin >> eleccion;

		switch (eleccion)
		{
		case 1:
        {
			cout << "La aplicación ha sido cerrada correctamente" << endl;
			exit(0);
		}
		break;
		case 2:
        {
			menuInicio(bd,u,carrito);
		}
		break;
		default:
        {
			cout << "Por favor, introduza 1 o 2" << endl;
		}
		break;
		}
	} while (eleccion != 1 && eleccion != 2);
}

void anyadirProductosCesta(BD *bd, Carrito *carrito,Cesta * cesta,Usuario* u)
{
	system ("cls");

    bd->mostrarProductos();

	int eleccion;
	int cant;

	cout << "NUMERO del producto: ";
	cin >> eleccion;
    Producto* p = bd->seleccionarProducto(eleccion);
	cout << "CANTIDAD de " << p->getTipo() << "s " ;
	cin >> cant;

    cout << "INFO: " <<p->getDescripcion();
    cout << endl;
    int s;

    do{

        cout << "¿Esta seguro que desea agregarlo a la cesta?" << endl;
        cout << "1. Si"<< endl;
        cout << "2. No" << endl;
        cin >> s;

        if (s == 1)
        {
            Cesta *c = new Cesta(p,cant);

            cesta[carrito->getCantProductos()] = *c;
            carrito->setCesta(cesta);
            carrito->setCantProductos(carrito->getCantProductos() + 1);

            cout << "Producto anyadido correctamente" << endl;
            menuPrincipal(bd,u,carrito);

        }else if (s == 2)
        {
            cout << "Operacion cancelada" << endl;

        }else
        {
            cout << "Opcion seleccionada incorrecta" << endl;
        }
    }while (s != 1 && s!= 2);
}

void mostrarCesta(BD *bd, Carrito *carrito)
{
	system ("cls");

	if (carrito->getCantProductos() == 0)
    {
		cout << "¡NINGUN PRODUCTO EN SU CESTA!" << endl;

	}else
	{
		cout << "MI CESTA" << endl;
		cout << "_____________" << endl;

		int num = 1;
		float total = 0.0;

		for (int i = 0; i < carrito->getCantProductos(); i++)
        {
			cout << num << ". " << carrito->getCesta()[i].getProducto()->getNombre() <<
					 "    x " << carrito->getCesta()[i].getCant() << endl;
			num++;

			int cantPr = carrito->getCesta()->getCant();
			float valorPr = carrito->getCesta()->getProducto()->getPrecio();

			total = total + (cantPr * valorPr);
		}

		cout <<"_______________________________________" << endl;
		cout << "TOTAL:         " << total  << " Euros"<< endl;
	}

	int o;
	cout << "Introduce un numero para continuar..." << endl;
	cin >> o;
}

void imprimirRecibo (Carrito * carrito)
{
	system("cls");

	cout << "RECIBO DEL PEDIDO" << endl;
	cout << "_________________________________" << endl;

	float total = 0.0;
	int cant;

	for (int i = 0; i < carrito->getCantProductos(); i++)
    {
		float costoP;
		costoP = carrito->getCesta()[i].getProducto()->getPrecio();

		cant = carrito->getCesta()[i].getCant();

		total = total + (cant * costoP);

		cout << carrito->getCesta()[i].getProducto()->getNombre();
		cout << "    " << costoP  << " €";
		cout << "   x" << carrito->getCesta()[i].getCant() << endl;
	}
	carrito->setImporte(total);

	cout << "__________________________________" << endl;
	cout << "TOTAL:                      " << total << "  €" << endl;
}

void terminarPedido(BD *bd,Carrito * carrito)
{
	system ("cls");

	if (carrito->getCantProductos() == 0)
    {
		cout << "¡¡¡ NINGUN PRODUCTO EN SU CARRITO !!!" << endl;

	}else
	{
		int opcion;
		char direccion[100];

		cout << "Ingrese la direccion a la que desea que se entregue el pedido " << endl;
		cout <<	"Introducuzca su direccion: " << endl;
		cin >> direccion;
		cout << "------------------------------------------" << endl;
		mostrarCesta(bd,carrito);
		cout << "Esta seguro que desea realizar su pedido?" << endl;
		cout << "1. Si" << endl;
		cout << "2. NO" << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			cout <<"Su pedido se ha realizado correctamente" <<endl << endl;
			imprimirRecibo(carrito);
			cout << endl;
			cout << "Gracias por su compra, lo esperamos de vuelta :)" << endl;
			break;
		case 2:
			cout <<"Su pedido se ha cancelado" <<endl;
			break;

		default:
			cout << "Esa respuesta no es válida" <<endl;
			break;

		}
	}
	int o;
	cout << "Introduce un numero para continuar..." << endl;
	cin >> o;
}
