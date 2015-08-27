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
	 * Esta función necesita un tentero que servirá como identificador del nodo. 
	 */
	lista* crearLista(int id) {
	    lista* ptr = (lista*)malloc(sizeof(lista)); //creo en espacio en memoria para tener el nodo
	    if(NULL == ptr){
	    	printf("Error al asignar la memoria\n");
	        return NULL;
	    }
	    ptr->identificador = -1; //asigno un -1 al identificador head.
	    ptr->cantidad =  0; //asigno una cantidad 0 al identificador.
	    ptr->siguiente = NULL; //señalo el puntero al siguiente nodo (en este caso vacio).
	    head = ptr;	//le asigno al puntero head el nodo.
	    return ptr; //retorno el puntero al nodo.
	}

	/*
	 * Fucnión que me dice si ya existe un nodo o no en la lista.
	 * Retorna un 0 en caso de false y un 1 en caso de true.
	 */
	bool buscar(int id){
		lista* temporal = head; //asigno un puntero temporal a la cabeza de la lista.
		while(temporal != NULL){ //mientras ese puntero temporal no apunte al fin de la lista.
			if(temporal->identificador == id){	//si el identificador del nodo es igual al id buscado.
				return true; //retorno 1
			}
			temporal = temporal->siguiente; //si no, paso al siguiente nodo.
		}
		return false; //no lo encontre.
	}


	/*
	 * Función que incerta ordenadamente en la lista
	 */
	lista* insertar(int id){
		if(head == NULL){ //si la lista esta vacia, cree un nodo cabeza.
			(crearLista(id));
		}
		lista* temporal = //head;	creo un puntero temporal a la cabeza de la lista.
		if(buscar(id) == true){ //busco si el nodo existe
			while(temporal != NULL){ //si es así debo solamente aunemtar el contador de la cantidad del nodo
				if(temporal-> identificador == id){
					temporal->cantidad += 1;
					return head; //termina la ejecucuón
				}
				temporal = temporal->siguiente;
			}
		}
		// si el nodo no existe, debo asignar la memoria para el almacenamiento de este.
		lista* ptr = (lista*)malloc(sizeof(lista));
	    if(NULL == ptr){
	        return NULL;
	        printf("Error al asignar la memoria\n");
	    }
	    //asigno los valores que concervan la información del puntero
		ptr->identificador = id;
	    ptr->cantidad =  1;
	    ptr->siguiente = NULL;
	    //me preparo para insertar el nodo nuevo
	   	lista *previo; 
		temporal = head->siguiente; //asigno 2 punteros, 1 al head y otro al siguiente
		previo = head;
		//digo que mientras no termine y no encuentre un id mayor al q voy a insertar
		while(temporal != NULL && temporal->identificador < id) { 
		    previo = temporal;
		    temporal = temporal->siguiente;
		}
		//inserto el nodo.
		ptr->siguiente = temporal;
		previo->siguiente = ptr;
		return head; 
	}

	/*
	 * Función que asigna un puntero a un nodo que este buscando.
	 */ 
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

	/*
	 * Función que asigna un puntero a un nodo anterior del que este buscando.
	 */
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

	/*
	 * Función que borra un nodo y libera la memoria.
	 */
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

	/*
	 * Función que exporta la información de la lista a un archivo de salida.
	 */ 
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

	
	   