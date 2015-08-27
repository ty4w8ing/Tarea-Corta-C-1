run: program
	./program input.txt salida.txt
program: histoprocess.o listas.o
	gcc -o program histoprocess.o listas.o

histoprocess.o: histoprocess.c listas.h
	gcc -c histoprocess.c

listas.o: listas.c listas.h
	gcc -c listas.c
