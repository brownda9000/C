#include <stdio.h>
#include <stddef.h>
#include <stdlib.h> 
#include <string.h>
#include <errno.h>

typedef struct Point {
    int x,y;
} Point;

void check(FILE* fp, char* msg) {
    if (fp == NULL ) {
        exit(EXIT_FAILURE);
    }
}
int main(int argc, char* argv[]) {

    Point p1 = {
        .x = 13,
        .y = -5
    };

    Point p2;

    FILE* in;
    FILE* out;


    /*
    check(out=fopen("point.bin" , "wb"), "Error opening file");
    size_t elements_out = fwrite(&p1, sizeof(Point), 1, out);
    fclose(out);

    if (elements_out == 0 ) {
        return(2);
    }
     */
    check(in=fopen("point.bin" , "rb"), "Error opening file for reading");
    size_t elements_in = fread(&p2, sizeof(Point), 1, in);

    if (elements_in == 0 ) {
        return(2);
    }

    printf("Point 2 %d %d\n", p2.x, p2.y);
    
}