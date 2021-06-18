#ifndef ZAPATILLAS_H
#define ZAPATILLAS_H

#include "Producto.h"

class Zapatillas: public Producto
{
    int numPie;
    public:
        Zapatillas();
        Zapatillas(int np);
        virtual ~Zapatillas();

    protected:

    private:
};

#endif // ZAPATILLAS_H
