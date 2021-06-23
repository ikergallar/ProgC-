#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EnC/Factura.h"
#include "EnC/Config.h"
#include "EnC/FuncionFicheros.h"

Factura *leerFactura(int *numFacturas)
{
	FILE *fichero;
    fichero = fopen(FICHERO_FACTURA, "r");
    char c = fgetc(fichero);
    if (c == EOF)
    {
        *numFacturas = 0;
    }else
    {
        ungetc(c, fichero);

    }

    char str[MAX_LINE_FACTURAS];
    fgets(str, MAX_LINE_FACTURAS, fichero);
    sscanf(str, "%i", numFacturas);
    clearIfNeeded(str, MAX_LINE_FACTURAS);

    Factura *facturas = malloc(*numFacturas * sizeof(Factura));
    int contador = 0;
    while (fgets(str, MAX_LINE_FACTURAS, fichero))
    {
        Factura f;
        char *ptr = strtok(str, "#");
        sscanf(ptr, "%d", &f.idProducto);

        ptr = strtok(NULL, "#");
        sscanf(ptr, "%d", &f.idUsuario);

        facturas[contador] = f;
        contador++;
        clearIfNeeded(str, MAX_LINE_FACTURAS);
    }

    Factura *facturasDeProducto = realloc(facturas, ((contador) * sizeof(Factura)));
    *numFacturas = contador;

    fclose(fichero);
    return facturasDeProducto;
}

void escribirFactura(Factura *facturas, int numFacturas)
{
	FILE *fichero;
	fichero = fopen(FICHERO_FACTURA, "w");
	fprintf(fichero, "SU FACTURA\n");

	for (int i=0; i<numFacturas; i++)
    {
		fprintf(fichero, "Resumen de compra--->Id del Producto: %d, Id del Usuario: %d\n", facturas[i].idProducto, facturas[i].idUsuario);
		fflush(stdout);

	}
	fprintf(fichero, "PRECIO TOTAL DEL PEDIDO: %f",facturas->precio);

	fclose(fichero);
}

void imprimirFactura(Factura *factura)
{
    printf("Id del producto comprado: %d", factura->idProducto);
}


