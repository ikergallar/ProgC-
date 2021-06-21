#ifndef CARRITO_H_INCLUDED
#define CARRITO_H_INCLUDED
#include "Cesta.h"

class Carrito
{
private:
    Cesta *cesta;
    float importe;

public:
    Carrito(Cesta *cesta);
    Carrito();
    Carrito(Carrito & p);
    virtual ~Carrito();

    Cesta* getCesta() const{return cesta;}
    float getImporte ()const {return importe;}

    void setCesta (Cesta *cesta);
    void setFecha (int fecha);
    void setImporte (float importe);

    void imprimirRecibo();
};
#endif // CARRITO_H_INCLUDED
