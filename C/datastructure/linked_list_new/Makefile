SRCDIR=.
HDRDIR=.
BIN=main

CC=gcc
DEPFLAGS=-MP -MD
CFLAGS=-Wall -Wextra -g $(foreach D, $(HDRDIR), -I$(D)) $(DEPFLAGS)

SRC=$(foreach D, $(SRCDIR), $(wildcard $(D)/*.c))
OBJ=$(patsubst %.c, %.o, $(SRC))
HDR=$(patsubst %.c, %.d, $(SRC))

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BIN) $(OBJ) $(HDR)
