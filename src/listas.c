#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listas.h"

	/*
	 * Puntero al inicio de la lista	
	 */	
	lista* head = NULL;

	/*
	 * Función que crea un nodo cabeza que inicializa la lista.
	 * este nodo solo tiene info basura pero sirve para denotar el inicio.
	 */
	lista* crearLista(int id) {
	    lista* ptr = (lista*)malloc(sizeof(lista));
	    if(NULL == ptr){
	        return NULL;
	    }
	    ptr->identificador = -1;
	    ptr->cantidad =  0;
	    ptr->siguiente = NULL;
	    head = ptr;
	    return ptr;
	}

	/*
	 * Fucnión que me dice si ya existe un nodo o no en la lista
	 */
	bool buscar(int id){
		lista* temporal = head;
		while(temporal != NULL){
			if(temporal->identificador == id){
				return true;
			}
			temporal = temporal->siguiente;
		}
		return false;
	}

	/*
	 * Función que incerta ordenadamente en la lista
	 */
	lista* insertar(int id){
		if(head == NULL){
			(crearLista(id));
		}
		lista* temporal = head;
		if(buscar(id) == true){
			while(temporal != NULL){
				if(temporal-> identificador == id){
					temporal->cantidad += 1;
					return head;
				}
				temporal = temporal->siguiente;
			}
		}
		lista* ptr = (lista*)malloc(sizeof(lista));
	    if(NULL == ptr){
	        return NULL;
	    }
		ptr->identificador = id;
	    ptr->cantidad =  1;
	    ptr->siguiente = NULL;

	   	lista *previo;
		temporal = head->siguiente;
		previo = head;
		while(temporal != NULL && temporal->identificador < id) {
		    previo = temporal;
		    temporal = temporal->siguiente;
		}
		ptr->siguiente = temporal;
		previo->siguiente = ptr;
		return head; 
	}

	lista* buscarNodo(int id){
		lista* temporal = head;
		while(temporal != NULL){
			if(temporal->identificador == id){
				return temporal;
			}
			temporal = temporal->siguiente;
		}
		return head;
	}

	lista* buscarAnterior(int id){
		lista* temporal = head;
		while(temporal != NULL){
			if(temporal->siguiente->identificador == id){
				return temporal;
			}
			temporal = temporal->siguiente;
		}
		return head;
	}

	lista* borrar(int id){
		lista* temporal = head;
		if(buscar(id) == true){
			while(temporal != NULL){
				if(temporal-> identificador == id && temporal->cantidad > 1){
					temporal->cantidad -= 1;
					return head;
				}
				temporal = temporal->siguiente;
			}
			lista* borrando = buscarNodo(id);
			lista* previo = buscarAnterior(id);
			previo->siguiente = borrando->siguiente;
			borrando->siguiente = NULL;
			free(borrando);
			borrando = NULL;
			return head;
		}
		else{
			return head;
		}
	}

	void exportar(char* salida){
		FILE* archivo;
		archivo = fopen(salida,"w");
		if (archivo == NULL){
    		printf("Error opening file!\n");
    		exit(1);
		}
		lista* temporal = head->siguiente;
		while(temporal != NULL){
			fprintf(archivo, "%d - %d\n", temporal->identificador, temporal->cantidad);
			temporal = temporal->siguiente;
		}
		fclose(archivo); 
	}

	
	   