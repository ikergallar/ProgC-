#ifndef PRODUCTO_H_
#define PRODUCTO_H_

class Producto
{
private:

    int id;
    char *nombre ;
    char *marca ;
    char *color ;
    float precio;
    int idVendedor;

public:
    Producto(const char *nombre, const char *marca, const char *color, const float precio,int id);
    Producto(int id, const char *nombre, const char *marca, const char *color, const float precio);
    Producto();
    Producto(const Producto &p);
    virtual ~Producto();

    int getId() const {return id;}
    char * getNombre() const {return nombre;}
    char * getMarca() const {return marca;}
    char * getColor() const {return color;}
    float getPrecio() const {return precio;}
    int getIdVendedor() const {return idVendedor;}

    void setId(int i);
    void setNombre(char *n);
    void setMarca(char *m);
    void setColor(char *d);
    void setPrecio(float p);
    void setIdVendedor(int iV);

    virtual void imprimir();
};
#endif /* PRODUCTO_H_ */
