#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EnC/Factura.h"
#include "EnC/Config.h"


void escribirFactura(Factura *facturas)
{
	FILE *fichero;
	fichero = fopen(FICHERO_FACTURA, "w");

	for (int i=0; i<facturas->numFacturas; i++)
    {
		fprintf(fichero, "#%s#%f\n", facturas->nomProducto[i],facturas->precio[i]);
		fflush(stdout);

	}
	fprintf(fichero, "#%f\n",facturas->precioTotal);
	fclose(fichero);
}

void imprimirFactura(Factura *facturas)
{
    for (int i=0; i<facturas->numFacturas; i++)
    {
		printf("Producto:%s, Precio:%f\n", facturas->nomProducto[i],facturas->precio[i]);

	}
    printf("------------------\n");
	printf("PRECIO TOTAL:%f\n",facturas->precioTotal);
}


