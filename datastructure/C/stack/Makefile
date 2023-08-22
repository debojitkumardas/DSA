main: main.o stack.o
	gcc -g main.o stack.o -o main

main.o: main.c
	gcc -c -g main.c -o main.o

stack.o: stack.c
	gcc -c -g stack.c -o stack.o

clean:
	rm -rf *.o
