#ifndef CAMISETA_H
#define CAMISETA_H

#include "Producto.h"

class Camiseta: public Producto
{
    char *tipoManga;

    public:
        Camiseta();
        Camiseta(const char *tm);
        virtual ~Camiseta();

    protected:

    private:
};

#endif // CAMISETA_H
