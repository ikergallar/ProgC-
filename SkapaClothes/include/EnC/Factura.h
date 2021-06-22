#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED

#define MAX_LINE_FACTURAS 50

typedef struct{
	int idProducto;
	int idUsuario;
	char *nombreUsuario;
}Factura;

Factura *leerFactura(int *numFacturas);
void escribirFactura(Factura *facturas, int numFacturas);

#endif // FACTURA_H_INCLUDED
