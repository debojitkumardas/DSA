SRC_DIR=./src/
BIN_DIR=./bin/

CC=gcc
DEPFLAGS=-MD -MP
CFLAGS=-Wall -Werror -Wextra -Wshadow -pedantic -I . $(DEPFLAGS)

SRC=$(wildcard $(SRC_DIR)*.c)
HDR=$(patsubst %.c, $(BIN_DIR)%.d, $(notdir $(SRC)))
OBJ=$(patsubst %.c, $(BIN_DIR)%.o, $(notdir $(SRC)))
BIN=$(BIN_DIR)main

all: $(BIN)

debug: CFLAGS += -DDEBUG -g
debug: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(BIN_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(HDR) $(OBJ) $(BIN)

clean_o:
	rm -rf .cache compile_commands.json
