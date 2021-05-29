#ifndef PRODUCTO_H_
#define PRODUCTO_H_
using namespace std;

class Producto {
	private:
		int idPrd;
		char *nombre ;
		char *tipo ;
		char *descripcion ;
		float precio;

	public:
		Producto(char *nombre, char *tipo, char *descripcion, float precio);
		Producto();
		Producto(Producto &p);
		~Producto();

		char * getNombre() const {return nombre;}
        char * getTipo() const {return tipo;}
        char * getDescripcion() const {return descripcion;}
        float getPrecio() const {return precio;}

		void setNombre(char *n);
		void setTipo(char *t);
		void setDescripcion(char *d);
		void setPrecio(float p);

		//void imprimirProducto() const;
};

class ProductoCant{
	private:
		Producto* p;
		int cant;

	public:
		ProductoCant(Producto *p, int cant);
		ProductoCant();
		~ProductoCant();

		Producto* getProducto () const;
		void setProducto (Producto* p);
		int getCant ()const;
		void setCant (int cant);

		void imprimirProductoCant() const;
};

class Carrito{
	private:
		ProductoCant *cesta;
		int fecha;
		float importe;
		int cantProductos;

	public:
		Carrito(ProductoCant *cesta, int fecha, float importe);
		Carrito();
		~Carrito();

		ProductoCant* getCesta() const;
		void setCesta (ProductoCant *cesta);
		int getFecha () const;
		void setFecha (int fecha);
		float getImporte ();
		void setImporte (float importe);

		void setCantProductos (int cantProductos);
		int getCantProductos () const;

		void imprimirCesta() const;


};


#endif /* PRODUCTO_H_ */
