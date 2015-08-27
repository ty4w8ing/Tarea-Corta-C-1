/* Instituto Tecnológico de Costa Rica.
 * Proyecto corto #1 del curso Lenguajes de Programación.
 * Desarrollado por José Gustavo González González.
 * El proyecto trata de crear un histograma en el cual se leen eventos de
 * un archivo de texto y este genera un archivo nuevo con los resultados.
 * NOTA DE PROGRAMADOR: este programa está pensado para ser iniciado en sistemas operativos
 * Linux. No se sabe si producirá errores en otros sistemas operativos.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listas.h"

    int main (int argc, char** argv){
    	printf("Leyendo contenido del archivo\n");
        FILE *archivo;
        archivo = fopen(argv[1],"r");
    	if(archivo == NULL) {
        	perror("Error al abrir el archivo");
          	return(EXIT_FAILURE);
       }
        char linea[10];
        for (;;){
        	fgets(linea, 10, archivo);
        	if (feof(archivo)) break;
            if (linea[0] == 120){
                borrar(atoi(&linea[1]));
            }else{
                insertar(atoi(linea));    
            }
        }
        fclose(archivo);
        exportar(argv[2]);
        printf("¡Archivo generado con exito!\n");
    	return (EXIT_SUCCESS);
    }
