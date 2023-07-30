BIN_DIR=./bin/

CC=gcc
DEPFLAGS=-MD - MP
CFLAGS=-Wall -Werror -Wextra -g

SRC=$(wildcard *.c)
HDR=$(patsubst %.c, %.d, $(SRC))
OBJ=$(patsubst %.c, %.o, $(SRC))
BIN=$(BIN_DIR)main

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(HDR) $(OBJ) $(BIN)
