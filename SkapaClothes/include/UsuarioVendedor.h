#ifndef USUARIOVENDEDOR_H
#define USUARIOVENDEDOR_H
#include "Usuario.h"
#include "Producto.h"

class UsuarioVendedor: public Usuario
{
    private:

        Producto* p;
        float PrecioProducto;

    public:
        UsuarioVendedor();
        UsuarioVendedor(char *,char*);
        UsuarioVendedor(UsuarioVendedor &uv);
        virtual ~UsuarioVendedor();

        Producto * getProducto() const {return p;}
        float getPrecioProducto() const {return PrecioProducto;}

        void setProducto(Producto* p);
	    void setPrecioProducto(float Pre);

};

#endif // USUARIOVENDEDOR_H
