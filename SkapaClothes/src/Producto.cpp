#include "iostream"
#include <stdlib.h>
#include <string>
#include <cstring>
#include "Producto.h"
using namespace std;

//PRODUCTO
Producto::Producto(int idPrd, string nombre, string tipo, string descripcion, float precio){
	this->idPrd = idPrd;
	this->nombre = nombre;
	this->tipo = tipo;
	this->descripcion = descripcion;
	this->precio = precio;
}

Producto::Producto(){
	this->idPrd = 0;
	this->nombre =  "";
	this->tipo =  "";
	this->descripcion = "";
	this->precio = 0.00;
}

Producto::~Producto(){
	delete this;
}

int Producto::getIdPrd() const{
	return this->idPrd;
}
void Producto::setIdPrd(int idPrd){
	this->idPrd = idPrd;
}

string Producto::getNombre() {
	return this->nombre;
}
void Producto::setNombre(string nombre){
	this->nombre =  nombre;
}

string Producto::getTipo() {
	return this->tipo;
}
void Producto::setTipo(string tipo){
	this->tipo = tipo;
}

string Producto::getDescripcion() {
	return this->descripcion;
}
void Producto::setDescripcion(string descripcion){
	this->descripcion = descripcion;
}

float Producto::getPrecio() const{
	return this->precio;
}
void Producto::setPrecio(float precio){
	this->precio = precio;
}

void Producto::imprimirProducto () const{
	cout << "Producto: " << this->idPrd << ", " << this->nombre << ", " << this->tipo << ", "<< this->descripcion << ", " << this->precio ;
}


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

void ProductoCant::imprimirProductoCant() const{
	this->p->imprimirProducto();
	cout<< " Cantidad: " << this->cant;
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

