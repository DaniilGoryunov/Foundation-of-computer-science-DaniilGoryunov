CC = clang
CFLAGS = -std=c99 -pedantic -Wall
OBJ = main.o tree.o
PROG = program

build: main.o tree.o
	$(CC) $(CFLAGS) -o $(PROG) $(OBJ)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

tree.o: tree.c
	$(CC) $(CFLAGS) -c tree.c

clean:
	rm -f $(PROG) $(OBJ)
