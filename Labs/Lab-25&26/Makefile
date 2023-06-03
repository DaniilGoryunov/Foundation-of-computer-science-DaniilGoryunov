CC = clang
CFLAGS = -std=c99 -pedantic -Wall
OBJ = main.o udt.o sort.o
PROG = program

build: main.o sort.o udt.o
	$(CC) $(CFLAGS) -o $(PROG) $(OBJ)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

sort.o: sort.c
	$(CC) $(CFLAGS) -c sort.c

udt.o: udt.c
	$(CC) $(CFLAGS) -c udt.c

clean:
	rm -f $(PROG) $(OBJ)
