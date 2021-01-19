

CC=gcc
CFLAGS=-g -Wall
BIN=downloadcurl


all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) -c $<  -o $@ -lcurl

clean: 
	rm -rf *.dSYM  $(BIN)
