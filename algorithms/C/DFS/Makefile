# valgrind --enable-debuginfod=no --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --track-origins=yes -s --verbose --log-file=valgrind_out.txt ./bin/main
# valgrind --enable-debuginfod=no --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --track-origins=yes -s --verbose --vgdb-error=0 ./bin/main
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./bin/main

SRC_DIR=src/
HDR_DIR=hdr/
BIN_DIR=bin/

CC=gcc
DEPFLAGS=-MD -MP
CFLAGS=-Wall -Werror -Wextra -Wshadow -pedantic -I . $(DEPFLAGS)

SRC=$(wildcard $(SRC_DIR)*.c)
HDR=$(wildcard $(HDR_DIR)*.h)

HDR_D=$(patsubst %.c, $(BIN_DIR)%.d, $(notdir $(SRC)))
OBJ=$(patsubst %.c, $(BIN_DIR)%.o, $(notdir $(SRC)))
BIN=$(BIN_DIR)main

all: $(BIN)

debug: CFLAGS += -DDEBUG -ggdb
debug: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(BIN_DIR)%.o: $(SRC_DIR)%.c $(HDR)
	$(CC) $(CFLAGS) -c -o $@ $<

run_with_valgrind:
	valgrind --enable-debuginfod=no --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --track-origins=yes -s --verbose --verbose --log-file=valgrind_out.txt ./bin/main

clean:
	rm -rf $(HDR_D) $(OBJ) $(BIN)

clean_o:
	rm -rf .cache compile_commands.json
