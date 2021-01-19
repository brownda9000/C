# Tooling - -fsanitize=address -fsanitize=memory -fsanitize=undefined
gcc -g -Wall -I. -fsanitize=address  -fsanitize=undefined  myqueue.c  webserver2.c -o webserver2 -lpthread

