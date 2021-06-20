#ifndef ZAPATILLAS_H
#define ZAPATILLAS_H

#include "Producto.h"

class Zapatillas: public Producto
{

    private:
        int numPie;

    public:

        Zapatillas();
        Zapatillas(const char *nombre, const char *marca, const char *color, const float precio,int id, int);
        Zapatillas(const Zapatillas &z);
        virtual ~Zapatillas();

        int getNumPie() const {return numPie;}

        void setNumPie(int);

        virtual void imprimir();



};

#endif // ZAPATILLAS_H
