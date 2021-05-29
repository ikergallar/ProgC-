#include "iostream"
#include <stdlib.h>
#include "Producto.h"
#include "Usuario.h"
#include "gestionProductos.h"

void imprimirStock (Producto* productos, int cantProductos){
	for (int i = 0; i < cantProductos; i++){
	//	productos[i].imprimirProducto();
		cout << endl;
	}
}


void listarProductos (Producto *stock, int cantProducto){

	int num = 1;

	for (int i = 0; i < cantProducto; i++){
		cout << num << ". " << stock[i].getNombre() << endl;
		num++;
	}
}

void eliminarProducto (Producto * stock, int cantProducto){

	system("cls");

	int op;

	listarProductos(stock, cantProducto);

	cout << "Pulsa el numero del producto que quieras eliminar" << endl;
	cin >> op;


	for (int i = op; i < cantProducto; i++){
		stock[i-1] = stock[i];

	}

	cantProducto--;
	//exportarStock(stock, cantProducto);


}



void menuGestionarProductos (Producto *stock, int cantProducto){

	int op;
	char c;

	do{

//		cantProducto = importarStock(stock);

		system("cls");

		cout << "Gestion de productos" << endl;
		cout << "_____________________________" << endl;

		cout << "1. Mostrar los productos disponibles" << endl;
		cout << "2. Añadir nuevo producto a la tienda" << endl;
		cout << "3. Eliminar producto existente" << endl;
		cout << "4. Volver" << endl;

		cin >> op;

		switch (op){

		case 1:
			listarProductos(stock, cantProducto);
			cout << "Pusla un numero para continuar..." << endl;
			cin >> c;
			break;

		case 2:
			break;

		case 3:
			eliminarProducto(stock, cantProducto);
			break;

		default:
			cout << "Opcion seleccionada incorrecta" << endl;
			break;
		}

	}while (op != 4);



}
