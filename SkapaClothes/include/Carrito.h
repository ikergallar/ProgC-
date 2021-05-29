#ifndef CARRITO_H_INCLUDED
#define CARRITO_H_INCLUDED
#include "Producto.h"

class Carrito{
	private:
		Producto *cesta;
		int fecha;
		float importe;
		int cantProductos;

	public:
		Carrito(Producto *cesta, int fecha, float importe);
		Carrito();
		~Carrito();

		Producto* getCesta() const{return cesta;}
		int getFecha () const{return fecha;}
        float getImporte ()const {return importe;}
        int getCantProductos () const{return cantProductos;}

		void setCesta (Producto *cesta);
		void setFecha (int fecha);
		void setImporte (float importe);
		void setCantProductos (int cantProductos);

		void imprimirCesta() const;


};



#endif // CARRITO_H_INCLUDED
