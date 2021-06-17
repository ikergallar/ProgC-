#ifndef USUARIOVENDEDOR_H
#define USUARIOVENDEDOR_H
#include "Usuario.h"
#include "Producto.h"

class Vendedor: public Usuario
{
    private:

        Producto* p;

    public:
        Vendedor();
        Vendedor(char *,char*);
        Vendedor(Vendedor &v);
        virtual ~Vendedor();

        Producto * getProducto() const {return p;}

        void setProducto(Producto* p);

};

#endif // USUARIOVENDEDOR_H
