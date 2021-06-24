#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED

#define MAX_LINE_FACTURAS 100

typedef struct{
	int idProducto;
	int idUsuario;
	float *precio;
    float precioTotal;
	int numFacturas;
	char **nomProducto;
}Factura;

Factura *leerFactura();
void escribirFactura(Factura *facturas);
void imprimirFactura(Factura *facturas);

#endif // FACTURA_H_INCLUDED
