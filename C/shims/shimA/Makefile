

CC=gcc
CFLAGS=-Wall -g
BINS=shim.so  fire.so  randtest.out # Windows .dylib / Linux use .so

all: $(BINS)

%.so: %.c
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^ -ldl

%.out: %.c
	$(CC) $(CFLAGS) -o $@ $^ -ldl 

clean:
	rm libfunc*.so
	rm $(BINS) 
