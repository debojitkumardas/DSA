main: main.o linked_list.o
	gcc -g main.o linked_list.o -o main

main.o: main.c
	gcc -g -c main.c -o main.o

linked_list.o: linked_list.c
	gcc -g -c linked_list.c -o linked_list.o

clean:
	rm -rf *.o
