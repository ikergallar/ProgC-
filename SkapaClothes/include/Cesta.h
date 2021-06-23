#ifndef CESTA_H_INCLUDED
#define CESTA_H_INCLUDED
#include "Producto.h"

class Cesta{

private:
    Producto** productos;
    int numProductos;
    int *cant;

public:
    Cesta();
    Cesta(Producto* productos, int cant);
    Cesta(Cesta &c);
    virtual ~Cesta();

    Producto** getProducto () const{return productos;}
    int getNumProductos ()const{return numProductos;}
    int *getCant ()const{return cant;}

    void setProductos(Producto* p);
    void setNumProductos(int numProductos);
    void setCant(int c);

    void anadirProducto(Producto* p, int cant);
    float imprimir();

};
#endif // CESTA_H_INCLUDED
