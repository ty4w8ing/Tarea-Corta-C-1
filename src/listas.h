#ifndef LISTAS_H_
#define LISTAS_H_

	struct lista_el {
		int identificador;
		unsigned cantidad;
		struct lista_el *siguiente; 
	};

	typedef struct lista_el lista;

	extern lista* head;
	extern lista* current;

	lista* crearLista(int id);
	bool buscar(int id);
	lista* insertar(int id); 
	lista* borrar(int id);
	void exportar(char* salida);
	
#endif