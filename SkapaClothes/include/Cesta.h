#ifndef CESTA_H_INCLUDED
#define CESTA_H_INCLUDED
#include "Producto.h"

class Cesta{
    private:
		Producto* p;
		int cant;

	public:
		Cesta(Producto *p, int cant);
		Cesta();
		Cesta(Cesta & c);
		virtual ~Cesta();

		Producto* getProducto () const{return p;}
        int getCant ()const{return cant;}

		void setProducto (Producto* p);
		void setCant (int cant);

		void imprimirProductoCant() const;

};



#endif // CESTA_H_INCLUDED
