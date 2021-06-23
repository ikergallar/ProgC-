#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EnC/Factura.h"
#include "EnC/Config.h"
#include "EnC/FuncionFicheros.h"

Factura *leerFactura()
{
    int numFacturas = 100;
	FILE *fichero;
    fichero = fopen(FICHERO_FACTURA, "r");
    char c = fgetc(fichero);
    if (c == EOF)
    {
        numFacturas = 0;
    }else
    {
        ungetc(c, fichero);

    }

    char str[MAX_LINE_FACTURAS];
    fgets(str, MAX_LINE_FACTURAS, fichero);
    sscanf(str, "%i", numFacturas);
    clearIfNeeded(str, MAX_LINE_FACTURAS);

    Factura *facturas = malloc(numFacturas * sizeof(Factura));
    int contador = 0;
    while (fgets(str, MAX_LINE_FACTURAS, fichero))
    {
        Factura f;
        char *ptr = strtok(str, "#");
        sscanf(ptr, "%s", &f.nomProducto);

        ptr = strtok(NULL, "#");
        sscanf(ptr, "%f", &f.precio);

        facturas[contador] = f;
        contador++;
        clearIfNeeded(str, MAX_LINE_FACTURAS);
    }

    Factura *facturasDeProducto = realloc(facturas, ((contador) * sizeof(Factura)));
    numFacturas = contador;

    fclose(fichero);
    return facturasDeProducto;
}

void escribirFactura(Factura *facturas)
{
	FILE *fichero;
	fichero = fopen(FICHERO_FACTURA, "w");

	for (int i=0; i<facturas->numFacturas; i++)
    {
		fprintf(fichero, "#%s#%f\n", facturas[i].nomProducto,facturas[i].precio);
		fflush(stdout);

	}
	fprintf(fichero, "#%f\n",facturas->precioTotal);
	fclose(fichero);
}

void imprimirFactura(Factura *facturas)
{
    for (int i=0; i<facturas->numFacturas; i++)
    {
		printf("Producto:%s, Precio:%f\n", facturas[i].nomProducto,facturas[i].precio);

	}
    printf("------------------\n");
	printf("PRECIO TOTAL:%f\n",facturas->precioTotal);
}


