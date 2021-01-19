gcc -nopie -g -c  -finstrument-functions -o myprofiler.o myprofiler.c
gcc -g -c -o -no-pie trace.o trace.c
gcc -no-pie myprofiler.o  trace.o -o myprofiler
