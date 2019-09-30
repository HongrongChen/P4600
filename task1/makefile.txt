

main.o:main.c
	gcc -c -o main.o main.c

statistics.o : statistics.c
	gcc -c -o statistics.o statistics.c





program: main.o statistics.o
	gcc -o program main.o statistics.o