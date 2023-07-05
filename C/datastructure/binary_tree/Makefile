CC=gcc
DEPFLAGS=-MP -MD
CFLAGS=-Wall -Werror -Wextra -g -I . $(DEPFLAGS)

SRC=$(wildcard *.c)
OBJ=$(patsubst %.c, %.o, $(SRC))
HDR=$(patsubst %.c, %.d, $(SRC))
BIN=main

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm $(OBJ) $(HDR) $(BIN)
