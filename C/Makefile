CC = gcc
CFLAGS = -Wall -ggdb3 -pedantic
#DEPS = myfunctions.h
OBJ = $(prog).o

%.o: %.c $(DEPS)
	        $(CC) $(prog).c $(CFLAGS) -c -o $(prog)

go: $(OBJ)
	        gcc $(prog).c $(CFLAGS) -o $(prog)
