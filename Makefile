FILE=main
FLAGS=-Wall -g -std=c99
DEPS=itch.c handlers.c reader.c
CC=gcc

all: build

run: build
	./$(FILE)

gdb: build
	gdb $(FILE)

valgrind: build
	valgrind ./$(FILE)

build:
	$(CC) $(FLAGS) -o $(FILE) $(DEPS) $(FILE).c

clean:
	rm $(FILE)
