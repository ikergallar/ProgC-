#ifndef PRODUCTO_H_
#define PRODUCTO_H_
using namespace std;

class Producto
{
	private:
		int id;
		char *nombre ;
		char *tipo ;
		char *marca ;
		char *descripcion ;
		float precio;

	public:
		Producto(char *nombre, char *tipo, char *marca, char *descripcion, float precio);
		Producto();
		Producto(Producto &p);
		virtual ~Producto();

		int getId() const {return id;}
		char * getNombre() const {return nombre;}
        char * getTipo() const {return tipo;}
        char * getMarca() const {return marca;}
        char * getDescripcion() const {return descripcion;}
        float getPrecio() const {return precio;}

        void setId(int i);
		void setNombre(char *n);
		void setTipo(char *t);
        void setMarca(char *m);
		void setDescripcion(char *d);
		void setPrecio(float p);
};
#endif /* PRODUCTO_H_ */
