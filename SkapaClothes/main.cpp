#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "BD.h"
#include "Usuario.h"
#include "Producto.h"
#include "Cesta.h"
#include "Carrito.h"
#include "Comprador.h"
#ifdef __cplusplus
extern "C" {
#include "EnC/Factura.h"
#include "EnC/Config.h"
}
#endif

using namespace std;

//MENUS
void menuBienvenida(BD *bd, Usuario* u);
void menuInicio(BD *bd);
void menuPrincipal(BD *bd, Usuario* u,Cesta *cesta);
void menuAdmin(BD *bd);
void menuVenta(BD *bd, Usuario* u);
void cerrarApp(BD *bd);

//METODOS DE USUARIO
void registrarUsuario(BD *bd);
void eliminarCuenta(BD *bd,Usuario* u);

//METODOS DE PRODUCTO/CARRITO/CESTA
void anyadirProductosCesta (BD *bd,Cesta *cesta,Usuario* u);
void mostrarCesta(BD *bd);
void terminarPedido(BD *bd,Cesta *cesta,Usuario* u,Carrito *carrito);

//VARIABLES
int contInicio = 0;
int contPrincipal = 0;
int contAdmin = 0;

int main()
{
    BD *bd = new BD("Skaa.db");
    Usuario* u = new Usuario();
    bd->crearBD();
    bd->abrirBD();
    menuInicio(bd);
    bd->cerrarBD();
    return 0;
}
void menuInicio(BD *bd)
{
	int eleccion;
	if(contInicio == 0)
    {
        system("cls");
        cout << "Bienvenido a la aplicacion de Skapa Clothes" << endl;
    }
	do {
        cout << "------------------------------------------------------"<< endl;
	    cout << "Elija una opcion e introduzca el numero que se encuentre a la izquierda"<< endl;
	    cout << "1. Iniciar sesion" << endl;
	    cout << "2. Registrarme como nuevo usuario" << endl;
	    cout << "3. Salir de la aplicacion" << endl;
		cin >> eleccion;
		contInicio++;
		switch (eleccion)
		{
		case 1:
        {
		    char nombre[20],pass[20];
		    int intentos = 0, resultado ;
            do
            {
                cout<<"Introduce nombre de usuario: ";
                cin>> nombre;
                cout<<"Introduce la contrasenya: ";
                cin>> pass;
                intentos++;
                resultado = bd->comprobarLogin(nombre,pass);
                if(intentos >= 3)
                {
                    menuInicio(bd);
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
                    Factura f;
                    menuAdmin(bd);
                }else
                {
                    cout<<"Sesion iniciada"<<endl;
                    Usuario *u = bd->seleccionarUsuarioIniciado(nombre);
                    menuBienvenida(bd, u);
                }
            }while(resultado!=2 && resultado != 4 && intentos<3);
		}
			break;
		case 2:
        {
			registrarUsuario(bd);
		}
			break;
		case 3:
        {
			cerrarApp(bd);
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
void menuBienvenida(BD *bd, Usuario* u)
{
	int eleccion;
    system("cls");
    cout << "Bienvenido a la aplicacion de Skapa Clothes" << endl;
	do {
        cout << "------------------------------------------------------"<< endl;
	    cout << "Elija una opcion e introduzca el numero que se encuentre a la izquierda"<< endl;
	    cout << "1. Comprar productos" << endl;
	    cout << "2. Vender productos" << endl;
        cout << "3. Editar perfil" << endl;
	    cout << "4. Eliminar cuenta" << endl;
	    cout << "5. Salir de la aplicacion" << endl;
		cin >> eleccion;
		switch (eleccion)
		{
		case 1:
        {
            Cesta *cesta = new Cesta();
		    menuPrincipal(bd,u,cesta);
		}
			break;
		case 2:
        {
            menuVenta(bd,u);
		}
			break;

        case 3:
        {
            int a = 0;
            char pass[20],confPass[20];
            char *passActual;
            passActual = new char [strlen(u->getNombre()) + 1];
	        strcpy(passActual, u->getNombre());
            cout<<"Contrasenya actual: "<<passActual<<endl;
            cout<<"Nueva contrasenya: "<<endl;
            cin>>pass;
            cout<<"Confirmar contrasenya: "<<endl;
            cin>>confPass;

            if(strcmp(pass,confPass) == 0)
            {
                u->setPass(pass);
                bd->editarUsuario(u);
                menuBienvenida(bd,u);

            }else

                cout<<"Las contraseñas no coinciden "<<endl;
                int o;
                cout << "Introduce un numero para continuar..." << endl;
                cin >> o;
                menuBienvenida(bd,u);
        }
            break;

        case 4:
        {
            eliminarCuenta(bd,u);
        }
			break;

        case 5:
        {
			cerrarApp(bd);
		}
			break;

		default:
        {
			cout<<"Seleccion invalida, porfavor introduzca uno de los numeros de la derecha"<< endl;
		}
			break;
		}
	} while (eleccion != 1 && eleccion != 2 && eleccion != 3 );
}
void menuPrincipal(BD *bd, Usuario* u,Cesta *cesta)
{
	int eleccion;
	if(contPrincipal == 0)
    {
        system("cls");
        cout << "Buenos dias "<<endl;
	}
	do {
        cout << "----------------------------------------------"<< endl;
	    cout << "Elija una opcion e introduzca el numero que se encuentre a la izquierda"<< endl;
	    cout << "1. Anyadir productos a la cesta" << endl;
	    cout << "2. Mostrar mi cesta" << endl;
	    cout << "3. Finalizar compra" << endl;
	    cout << "4. Cerrar Sesion" << endl;
	    cout << "5. Salir" << endl;

		cin >> eleccion;

		switch (eleccion)
		{
		case 1:
        {
		    cout << "-----PRODUCTOS DISPONIBLES-----" << endl;
		    bd->mostrarProductos();
		    anyadirProductosCesta(bd,cesta,u);
		}
			break;
		case 2:
        {
            cesta->imprimir();
		    menuPrincipal(bd, u,cesta);
		}
			break;
		case 3:
        {
            Carrito *carrito = new Carrito();
		    terminarPedido(bd,cesta,u,carrito);
		}
			break;
        case 4:
        {
            menuInicio(bd);
        }
            break;

        case 5:
        {
             cerrarApp(bd);
        }
			break;
		default:
        {
			cout<<"Seleccion invalida, porfavor introduzca uno de los numeros de la derecha"<< endl;
		}
			break;
		}
	} while (eleccion != 1 && eleccion != 2 && eleccion != 3 && eleccion != 4 && eleccion != 5 );
}

void menuVenta(BD *bd, Usuario* u)
{
	int eleccion;
	char c;
    int conf;
    system("cls");

	do {

        cout << "------------------------------------------------------"<< endl;
	    cout << "Elija una opcion e introduzca el numero que se encuentre a la izquierda"<< endl;
	    cout << "1. Poner un producto a la venta" << endl;
	    cout << "2. Ver mis productos" << endl;
        cout << "3. Eliminar un producto de la venta" << endl;
	    cout << "4. Salir de la aplicacion" << endl;
		cin >> eleccion;

		switch (eleccion)
		{
		case 1:
        {
            int e;
            cout<<"Que tipo de producto desea poner a la venta?: "<<endl;
            cout<<"1. Camiseta "<<endl;
            cout<<"2. Pantalon "<<endl;
            cout<<"3. Zapatillas "<<endl;
            cin>>e;

            switch (e)
            {
            case 1:
            {

                char nombre[15],marca[15],color[15],manga[15];
                float precio;
                cout<<"Introduzca la marca de la camiseta: ";
                cin>>marca;
                cout<<"Introduzca el color de la camiseta: ";
                cin>>color;
                cout<<"Introduzca el precio de la camiseta: ";
                cin>>precio;
                cout<<"Introduzca el tipo de manga de la camiseta: ";
                cin>>manga;

                strcpy(nombre, "Camiseta");

                Camiseta c(nombre,marca,color,precio,u->getId(),manga);

                cout<<"¿Esta seguro que desea anyadir el siguiente producto?: "<<endl;
                c.imprimir();
                cout<<"1. SI "<<endl;
                cout<<"2. NO "<<endl;
                cin>>conf;

                switch(conf)
                {
                case 1:
                {
                    bd->insertarCamiseta(c);
                }
                break;

                case 2:
                {
                    menuVenta(bd,u);
                }
                } while (conf != 1 && conf != 2);


            }

                 break;

            case 2:
            {

                 char nombre[15],marca[15],color[15],tipo[15];
		         float precio;
                 cout<<"Introduzca la marca del pantalon: ";
                 cin>>marca;
                 cout<<"Introduzca el color del pantalon: ";
                 cin>>color;
                 cout<<"Introduzca el precio del pantalon: ";
                 cin>>precio;
                 cout<<"Introduzca el tipo de pantalon: ";
                 cin>>tipo;

                 strcpy(nombre, "Pantalon");

                 Pantalon p(nombre,marca,color,precio,u->getId(),tipo);


                cout<<"¿Esta seguro que desea anyadir el siguiente producto?: "<<endl;
                p.imprimir();
                cout<<"1. SI "<<endl;
                cout<<"2. NO "<<endl;
                cin>>conf;

                switch(conf)
                {
                case 1:
                {
                    bd->insertarPantalon(p);
                }
                break;

                case 2:
                {
                    menuVenta(bd,u);
                }
                } while (conf != 1 && conf != 2);

              }
                 break;

            case 3:
            {

                 char nombre[15],marca[15],color[15];
		         float precio;
		         int pie;
                 cout<<"Introduzca la marca de las zapatillas: ";
                 cin>>marca;
                 cout<<"Introduzca el color de las zapatillas: ";
                 cin>>color;
                 cout<<"Introduzca el precio de las zapatillas: ";
                 cin>>precio;
                 cout<<"Introduzca el numero de pie de las zapatillas: ";
                 cin>>pie;

                 strcpy(nombre, "Zapatillas");

                 Zapatillas z(nombre,marca,color,precio,u->getId(),pie);

                cout<<"¿Esta seguro que desea anyadir el siguiente producto?: "<<endl;
                z.imprimir();
                cout<<"1. SI "<<endl;
                cout<<"2. NO "<<endl;
                cin>>conf;

                switch(conf)
                {
                case 1:
                {
                    bd->insertarZapatillas(z);
                }
                break;

                case 2:
                {
                    menuVenta(bd,u);
                }
                } while (conf != 1 && conf != 2);

              }
                 break;

            } while (e != 1 && e != 2 && e != 3  );

		}

		cout << "Pusla una tecla para continuar..." << endl;
        cin >> c;

        menuVenta(bd,u);

			break;
		case 2:
        {
            bd->mostrarProductoDeVendedor(u->getId());
            cout << "Pusla una tecla para continuar..." << endl;
			cin >> c;
            menuVenta(bd,u);

		}
			break;
		case 3:
        {
             bd->mostrarProductoDeVendedor(u->getId());
             int eleccion,r;
	         cout << "NUMERO del producto: ";
	         cin >> eleccion;
             Producto *p = bd->seleccionarProductoDeVendedor(eleccion,u->getId());
             cout << "¿Esta seguro que desea retirarlo de la venta?"<<endl;
             cout << "1. SI"<<endl;
             cout << "2. NO"<<endl;
             cin>>r;

             if(r = 1)
             {
                 bd->borrarProducto(p);
                 menuVenta(bd,u);

             }
             else
             {
                menuVenta(bd,u);
             }

		}
			break;
        case 4:
        {
		}
			break;
		default:
        {
			cout<<"Seleccion invalida, porfavor introduzca uno de los numeros de la derecha"<< endl;
		}
			break;
		}
	} while (eleccion != 1 && eleccion != 2 && eleccion != 3 && eleccion != 4 );
}
void menuAdmin(BD *bd)
{
    int eleccion;
	char c;
	if(contAdmin == 0)
    {
        system("cls");
		cout << "BIENVENIDO ADMINISTRADOR" << endl;
	}
	do{
        cout << "----------------------------------" << endl;
		cout << "1. Mostrar los productos disponibles" << endl;
		cout << "2. Eliminar producto existente" << endl;
		cout << "3. Editar producto existente" << endl;
		cout << "4. Eliminar cuenta de usuario" << endl;
        cout << "5. Visualizar datos de la ultima compra realizada" << endl;
	    cout << "6. Salir" << endl;
		cin >> eleccion;
		contAdmin++;
		switch (eleccion)
		{
		case 1:
        {
			bd->mostrarProductos();
			cout << "Pusla un numero para continuar..." << endl;
			cin >> c;
			menuAdmin(bd);
        }
			break;
		case 2:
        {
            int resp;
		    bd->mostrarProductos();
		    cout << "Introduzca el numero del producto que desea eliminar" << endl;
            cin>>resp;
            Producto *p = bd->seleccionarProducto(resp);
            bd->borrarProducto(p);
            menuAdmin(bd);
        }
			break;
        case 3:
        {
            int resp;
		    bd->mostrarProductos();
		    cout << "Introduzca el numero del producto que desea editar" << endl;
            cin>>resp;
            Producto *p = bd->seleccionarProducto(resp);
            char nombre[15],marca[15],color[15];
		    float precio;
            cout<<"Introduzca el nombre del producto: ";
            cin>>nombre;
            cout<<"Introduzca la marca del producto: ";
            cin>>marca;
            cout<<"Introduzca el color del producto: ";
            cin>>color;
            cout<<"Introduzca el precio del producto: ";
            cin>>precio;
            int id = p->getId();
            p = new Producto(id,nombre,marca,color,precio);
            bd->editarProducto(p);
            menuAdmin(bd);
        }
			break;
        case 4:
        {
            int resp;
		    bd->mostrarUsuarios();
		    cout << "Introduzca el numero del usuario que desea eliminar" << endl;
            cin>>resp;
            Usuario *u = bd->seleccionarUsuario(resp);
            bd->borrarUsuario(u);
            menuAdmin(bd);
        }
            break;

        case 5:
        {
            menuAdmin(bd);
        }
            break;
        case 6:
        {
            exit(0);
        }
		default:
			cout << "Opcion seleccionada incorrecta" << endl;
			break;
		}
	}while (eleccion != 1 && eleccion != 2 && eleccion != 3 && eleccion != 4 && eleccion != 5 && eleccion != 6);
}
void registrarUsuario(BD *bd)
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
        cout<<"Las contraseñas no coinciden: "<<endl;
        menuInicio(bd);
    }else
    {
    Usuario * u = new Usuario();
	u->setNombre(nombre);
	u->setPass(pass);
    bd->insertarUsuario(u);
	menuInicio(bd);
	}
}
void eliminarCuenta(BD *bd, Usuario* u)
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
			menuBienvenida(bd,u);
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
void cerrarApp(BD *bd)
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
			menuInicio(bd);
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
void anyadirProductosCesta(BD *bd,Cesta *cesta,Usuario* u)
{
	system ("cls");
    bd->mostrarProductos();
	int eleccion;
	int cant;
	cout << "NUMERO del producto: ";
	cin >> eleccion;
    Producto *p = bd->seleccionarProducto(eleccion);
	cout << "CANTIDAD de " << p->getNombre()<<" : ";
	cin >> cant;
    cout << "INFO: " <<p->getColor();
    cout << endl;
    int s;
    do{
        cout << "¿Esta seguro que desea agregarlo a la cesta?" << endl;
        cout << "1. Si"<< endl;
        cout << "2. No" << endl;
        cin >> s;
        if (s == 1)
        {
            cesta->anadirProducto(p,cant);
            cout << "Producto agregado correctamente" << endl;
            menuPrincipal(bd,u,cesta);
        }else if (s == 2)
        {
            cout << "Operacion cancelada" << endl;
        }else
        {
            cout << "Opcion seleccionada incorrecta" << endl;
        }
    }while (s != 1 && s!= 2);
}

void terminarPedido(BD *bd,Cesta *cesta,Usuario* u,Carrito *carrito)
{
	system ("cls");
	carrito->setCesta(cesta);

	if (cesta->getNumProductos() == 0)
    {
		cout << "¡¡¡ NINGUN PRODUCTO EN SU CARRITO !!!" << endl;
	}else
	{
		int opcion;
		char direccion[100];
		cout << "Ingrese la direccion a la que desea que se entregue el pedido " << endl;
		cout <<	"Introduzca su direccion: " << endl;
		cin >> direccion;
		cout << "------------------------------------------" << endl;
		cesta->imprimir();
		cout << "Esta seguro que desea realizar su pedido?" << endl;
		cout << "1. Si" << endl;
		cout << "2. NO" << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
		    Factura f;

			for(int i = 0; i < cesta->getNumProductos(); i++)
            {
                f.idProducto = cesta->getProducto()[i]->getId();
                f.idUsuario = u->getId();
                f.precio = f.precio + cesta->getProducto()[i]->getPrecio();
                f.numFacturas = cesta->getNumProductos();

                escribirFactura(&f,cesta->getNumProductos());

            }
			cout <<"Su pedido se ha realizado correctamente" <<endl << endl;
			carrito->imprimirRecibo();
			cout << endl;
			cout<<"¿Desea visualizar la factura de su compra?"<<endl;
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
}
