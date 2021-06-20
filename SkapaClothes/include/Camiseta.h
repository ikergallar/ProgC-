#ifndef CAMISETA_H
#define CAMISETA_H

#include "Producto.h"

class Camiseta: public Producto
{

    private:

        char *tipoManga;

    public:
        Camiseta();
        Camiseta(const char *nombre, const char *marca, const char *color, const float precio,int id, char *);
        Camiseta(const Camiseta &c);
        virtual ~Camiseta();

        char * getTipoManga() const {return tipoManga;}

        void setTipoManga(char *);

        virtual void imprimir();

};

#endif // CAMISETA_H
