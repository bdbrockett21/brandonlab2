time: main.o ipc.o time.o
	gcc -o time time.o main.o ipc.o -lrt

main.o: main.c
	gcc -c main.c

ipc.o: ipc.c
	gcc -c ipc.c
	
time.o: time.c
	gcc -c time.c

clear:
	rm -f *.0
	@echo "All clean!"