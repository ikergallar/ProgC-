#ifndef PRODUCTO_H_
#define PRODUCTO_H_
using namespace std;

class Producto {
	private:
		int id;
		char *nombre ;
		char *tipo ;
		char *descripcion ;
		float precio;
		Producto *cesta;

	public:
		Producto(char *nombre, char *tipo, char *descripcion, float precio);
		Producto();
		Producto(Producto &p);
		~Producto();

		int getId() const {return id;}
		char * getNombre() const {return nombre;}
        char * getTipo() const {return tipo;}
        char * getDescripcion() const {return descripcion;}
        float getPrecio() const {return precio;}

		void setNombre(char *n);
		void setTipo(char *t);
		void setDescripcion(char *d);
		void setPrecio(float p);
};

#endif /* PRODUCTO_H_ */
