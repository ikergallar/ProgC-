#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EnC/FuncionFicheros.h"

void clearIfNeeded(char *str, int max_line) {
	// Limpia los caracteres de más introducidos
	if ((strlen(str) == max_line-1) && (str[max_line-2] != '\n'))
		while (getchar() != '\n');
}

char* strcopySinBarraN(char *strOrigen, int max_line) {
	char * stringFinal;
	stringFinal = (char *)malloc((strlen(strOrigen)) * sizeof(char)); // no hace falta sumarle 1 a strlen(srtOrigen) ya que está contando el \n (que sustituiremos por el\0)

	clearIfNeeded(strOrigen, max_line);
	int len = strlen(strOrigen);
			if (len > 0 && strOrigen[len-1] == '\n'){
				strOrigen[len-1] = '\0';
			}
	strcpy(stringFinal, strOrigen);
	return stringFinal;
}
