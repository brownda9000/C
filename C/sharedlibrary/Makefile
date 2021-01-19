

CC=gcc
CFLAGS=-Wall -g
BINS=libfunc1.so  libfunc2.so testlib.elf # Windows .dylib / Linux use .so

all: $(BINS)

%.so: %.c
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^

%.elf: %.c
	$(CC) $(CFLAGS) -o $@ $^ -ldl 

clean:
	rm libfunc*.so
	rm $(BINS) 
