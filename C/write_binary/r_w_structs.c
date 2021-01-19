#include <stdio.h>
#include <stddef.h>
#include <stdlib.h> 
#include <string.h>
#include <errno.h>


//const char* PERSON_FORMAT_IN = "(%[^,], %d, %c)";
//const char* PERSON_FORMAT_OUT = "(%s, %d, %c)\n";

//
// Json format strings
// 
const char* PERSON_FORMAT_IN = 
     "{\n\t\"name\": \"%[^\"]\",\n\t\"age\":%d,\n\t\"gender\": \"%c\"\n}";
const char* PERSON_FORMAT_OUT = 
     "{\n\t\"name\": \"%s\",\n\t\"age\":%d,\n\t\"gender\": \"%c\"\n}";

//
// Define Structures
//
typedef struct Person {
    char name [20];
    int age;
    char status; 
} Person;

void check(FILE* fp, char* msg) {
    if (fp == NULL ) {
        exit(EXIT_FAILURE);
    }
}
int main(int argc, char* argv[]) {

    Person p1 = {
        .name = "Frank smith",
        .age = 26,
        .status='M'
    };

    Person p2;

    FILE* file;

    check(file=fopen( "people.dat", "w+"), "Error opening file");

    // Write to file 
    fprintf(file, PERSON_FORMAT_OUT, p1.name, p1.age, p1.status);

    // Set the pointer of the file to the begining
    fseek(file, 0 ,SEEK_SET);

     fscanf(file, PERSON_FORMAT_IN,  p2.name,  &p2.age, &p2.status );
    printf("Person 2 --> %s %d %c\n", p2.name, p2.age, p2.status);
    /*
    check(out=fopen("people.dat" , "w+"), "Error opening file");
    size_t elements_out = fwrite(&p1, sizeof(Point), 1, out);
    fclose(out);

    if (elements_out == 0 ) {
        return(2);
    }
    check(in=fopen("point.bin" , "rb"), "Error opening file for reading");
    size_t elements_in = fread(&p2, sizeof(Point), 1, in);

    if (elements_in == 0 ) {
        return(2);
    }

    printf("Point 2 %d %d\n", p2.x, p2.y);
     */
    
}