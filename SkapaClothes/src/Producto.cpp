#include "iostream"
#include <stdlib.h>
#include <string>
#include <cstring>
#include "Producto.h"
using namespace std;

//PRODUCTO
Producto::Producto(){
    nombre = new char[20];
    tipo = new char[20];
    descripcion = new char[20];

}
Producto::Producto(char *nombre, char *tipo, char *descripcion, float precio){
	this->nombre = new char [strlen(nombre) + 1];
	strcpy(this->nombre, nombre);

	this->tipo = new char [strlen(tipo) + 1];
	strcpy(this->tipo, tipo);

	this->descripcion = new char [strlen(descripcion) + 1];
	strcpy(this->descripcion, descripcion);

	this->precio = precio;
}

Producto::Producto(Producto &p){
	this->nombre = new char [strlen(p.nombre) + 1];
	strcpy(this->nombre, p.nombre);

	this->tipo = new char [strlen(p.tipo) + 1];
	strcpy(this->tipo, p.tipo);

	this->descripcion = new char [strlen(p.descripcion) + 1];
	strcpy(this->descripcion, p.descripcion);

	this->precio = precio;
}


Producto::~Producto(){
	delete this;
}

void Producto::setNombre(char *n){
	this->nombre = n;
}

void Producto::setTipo(char *t){
	this->tipo = t;
}

void Producto::setDescripcion(char *d){
	this->descripcion = d;
}

void Producto::setPrecio(float p){
	this->precio = p;
}

/*void Producto::imprimirProducto () const{
	cout << "Producto: " << this->idPrd << ", " << this->nombre << ", " << this->tipo << ", "<< this->descripcion << ", " << this->precio ;
}
*/

//PRODUCTOCANT
ProductoCant::ProductoCant(Producto *p, int cant){
	this->p = p;
	this->cant = cant;
}

ProductoCant::ProductoCant(){
	Producto *p = new Producto ();
	this->p = p;
	this->cant = 0;
}
ProductoCant::~ProductoCant(){
	delete this;
}

Producto* ProductoCant::getProducto () const{
	return this->p;
}
void ProductoCant::setProducto (Producto* p){
	this->p = p;
}
int ProductoCant::getCant ()const{
	return this->cant;
}
void ProductoCant::setCant (int cant){
	this->cant = cant;
}


//CARRITO

Carrito::Carrito(ProductoCant *cesta, int fecha, float importe){
	this->cesta = cesta;
	this->fecha = fecha;
	this->importe = importe;
	this->cantProductos = 0;
}

Carrito::Carrito(){
	this->cesta = NULL;
	this->fecha = 0.0;
	this->importe = 0.0;
	this->cantProductos = 0;

}

Carrito::~Carrito(){
	delete this;
}

ProductoCant* Carrito::getCesta() const{
	return this->cesta;
}

void Carrito::setCesta (ProductoCant *cesta){
	this->cesta = cesta;
}

int Carrito::getFecha () const{
	return this->fecha;
}

void Carrito::setFecha (int fecha){
	this->fecha = fecha;
}

float Carrito::getImporte (){
	return this->fecha;
}

void Carrito::setImporte (float importe){
	this->importe = importe;
}

void Carrito::setCantProductos (int cantProductos){
	this->cantProductos = cantProductos;
}

int Carrito::getCantProductos () const{
	return this->cantProductos;
}

void Carrito::imprimirCesta() const{

}

