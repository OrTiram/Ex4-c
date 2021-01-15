CC=gcc
FLAGS=-Wall -g
OBJECTS_MAIN=main.o

all : frequency

frequency: $(OBJECTS_MAIN) TRIE.o
	$(CC) $(-Wall -g) -o frequency $(OBJECTS_MAIN) TRIE.o
	
TRIE.o: TRIE.c TRIE.h
	$(CC) $(-Wall -g) -c TRIE.c
	
	
.PHONY: clean

clean:
	rm -f  *.o frequency