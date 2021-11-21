CC = gcc
CFLAGS = -Wall -g
OBJ = main.o my_mat.o

all: connections main.o my_mat.o

main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c
my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c my_mat.c

connections: $(OBJ)
	$(CC) $(CFLAGS) -o connections $(OBJ)

.PHONY: clean all
clean:
	rm -f *.o connections
