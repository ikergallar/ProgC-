#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED

#define MAX_LINE_FACTURAS 100

typedef struct{
	int idProducto;
	int idUsuario;
}Factura;

Factura *leerFactura(int *numFacturas);
void escribirFactura(Factura *facturas, int numFacturas);

#endif // FACTURA_H_INCLUDED
