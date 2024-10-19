explode: main.o lab2.o
	gcc -o explode main.o lab2.o

main.o: main.c
	gcc -c main.c

lab2.o: lab2.c
	gcc -c lab2.c
