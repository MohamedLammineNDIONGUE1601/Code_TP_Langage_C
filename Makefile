constante: constante.o main.o
	gcc -o constante constante.o main.o


constante.o: constante.c
	gcc -W -Wall -o constante.o constante.c -ansi -std=c99 -pedantic

main.o: main.c constante.h
	gcc -W -Wall -o main.o -c main.c -ansi -std=c99 -pedantic