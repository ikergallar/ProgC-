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

public:
    Producto(const char *nombre, const char *marca, const char *color, const float precio);
    Producto();
    Producto(const Producto &p);
    virtual ~Producto();

    int getId() const {return id;}
    char * getNombre() const {return nombre;}
    char * getMarca() const {return marca;}
    char * getColor() const {return color;}
    float getPrecio() const {return precio;}

    void setId(int i);
    void setNombre(char *n);
    void setMarca(char *m);
    void setColor(char *d);
    void setPrecio(float p);
};
#endif /* PRODUCTO_H_ */
