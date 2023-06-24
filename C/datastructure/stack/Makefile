main: main.o stack.o
	gcc -g main.o stack.o -o main

main.o: main.c stack.c
	gcc -c -g main.c stack.c -o main.o stack.o

clean:
	rm -rf *.o
