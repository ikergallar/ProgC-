#ifndef PANTALON_H
#define PANTALON_H

#include "Producto.h"

class Pantalon: public Producto
{

    char *tipoPantalon;

    public:
        Pantalon();
        Pantalon(const char *tp);
        virtual ~Pantalon();

    protected:

    private:
};

#endif // PANTALON_H
