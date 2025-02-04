CC = gcc
FLAGS = -ggdb3 -Wall -Wextra -Wshadow -std=gnu11 -fsanitize=address -Wno-unused-parameter 

tictactoe: tictactoe.h tictactoe.c
	$(CC) $(FLAGS) $^ -o $@ -lm

discussion: discussion.c
	$(CC) $(FLAGS) $^ -o $@ -lm
	
clean:
	rm -f tictactoe

.PHONY: clean