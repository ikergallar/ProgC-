#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED

#define MAX_LINE_FACTURAS 100

typedef struct{
	int idProducto;
	int idUsuario;
	float precio;
	int numFacturas;
}Factura;

Factura *leerFactura(int *numFacturas);
void escribirFactura(Factura *facturas, int numFacturas);
void imprimirFactura();

#endif // FACTURA_H_INCLUDED
