CC = gcc
FLAGS = -ggdb3 -Wall -Wextra -Wshadow -std=gnu11 -fsanitize=address -Wno-unused-parameter

pipes: pipes.c
	$(CC) $(FLAGS) $^ -o $@ -lm

all: pipes

clean:
	rm -f pipes

.PHONY: all clean