#ifndef PRODUCTO_H_
#define PRODUCTO_H_
using namespace std;

class Producto {
	private:
		int idPrd;
		string nombre ;
		string tipo ;
		string descripcion ;
		float precio;

	public:
		Producto(int idPrd, string nombre, string tipo, string descripcion, float precio);
		Producto();
		~Producto();

		int getIdPrd() const;
		void setIdPrd(int idPrd);
		string getNombre();
		void setNombre(string nombre);
		string getTipo();
		void setTipo(string tipo);
		string getDescripcion();
		void setDescripcion(string descripcion);
		float getPrecio() const;
		void setPrecio(float precio);

		void imprimirProducto() const;
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
