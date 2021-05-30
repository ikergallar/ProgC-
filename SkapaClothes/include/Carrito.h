#ifndef CARRITO_H_INCLUDED
#define CARRITO_H_INCLUDED
#include "Cesta.h"

class Carrito
{
	private:
		Cesta *cesta;
		int fecha;
		float importe;
		int cantProductos;

	public:
		Carrito(Cesta *cesta, int fecha, float importe);
		Carrito();
		Carrito(Carrito & p);
		virtual ~Carrito();

		Cesta* getCesta() const{return cesta;}
		int getFecha () const{return fecha;}
        float getImporte ()const {return importe;}
        int getCantProductos () const{return cantProductos;}

		void setCesta (Cesta *cesta);
		void setFecha (int fecha);
		void setImporte (float importe);
		void setCantProductos (int cantProductos);
};
#endif // CARRITO_H_INCLUDED
