#ifndef PANTALON_H
#define PANTALON_H

#include "Producto.h"

class Pantalon: public Producto
{
    private:

        char *tipoPantalon;

    public:
        Pantalon();
        Pantalon(const char *nombre, const char *marca, const char *color, const float precio,int id, char*);
        Pantalon(const Pantalon &p);
        virtual ~Pantalon();

        char * getTipoPantalon() const {return tipoPantalon;}

        void setTipoPantalon(char *);

        virtual void imprimir();
};
#endif // PANTALON_H
