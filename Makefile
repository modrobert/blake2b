HEADERS = blake2b.h
CC = gcc
CFLAGS = -O2 -Wpedantic

default: blake2b

debug: CFLAGS = -g -Wpedantic
debug: blake2b

blake2bcmd.o: blake2bcmd.c
	$(CC) $(CFLAGS) -c blake2bcmd.c -o blake2bcmd.o

blake2b.o: blake2b.c $(HEADERS)
	$(CC) $(CFLAGS) -c blake2b.c -o blake2b.o

blake2b: blake2bcmd.o blake2b.o
	$(CC) $(CFLAGS) blake2bcmd.o blake2b.o -o blake2b

clean:
	-rm -f blake2bcmd.o
	-rm -f blake2b.o
	-rm -f blake2b
	
