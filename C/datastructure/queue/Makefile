main: main.o queue.o
	gcc -g main.o queue.o -o main

%.o: %.c
	gcc -g -c $^ -o $@

clean:
	rm -rf *.o
