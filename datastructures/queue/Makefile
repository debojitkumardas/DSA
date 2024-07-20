# to check for memory leaks enable -fsanitize=address
all:
	g++ -Wall -Wextra -Werror -ggdb -std=c++17 ./src/queue.h ./src/main.cpp -o ./bin/main

run:
	./bin/main

# leak check using valgrind
# to store the logs provided by valgrind use: --log-file=<name of file>
leak_check:
	valgrind --enable-debuginfod=no --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --track-origins=yes -s --verbose ./bin/main

clean:
	rm -rf ./bin/*
