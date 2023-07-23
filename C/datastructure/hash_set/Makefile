CC=gcc
DEPFLAGS=-MP -MD
CFLAGS=-Wall -Werror -Wextra -g -I . $(DEPFLAGS)

SRC=$(wildcard *.c)
HDR=$(patsubst %.c, %.d, $(SRC))
OBJ=$(patsubst %.c, %.o, $(SRC))
BIN=main

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(HDR) $(OBJ) $(BIN)
