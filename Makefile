CC=gcc
CFLAGS=-g -Wall
LFLAGS=
EXE=elfdump

all: $(EXE)

clean:
	rm -rf $(EXE)