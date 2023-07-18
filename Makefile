CC = c89
CFLAGS = -Wall -Wextra -Wpedantic -O3
PREFIX = ~/.local

tictactoe: main.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm tictactoe

install: tictactoe
	cp $< $(PREFIX)/bin/

.PHONY: clean install
