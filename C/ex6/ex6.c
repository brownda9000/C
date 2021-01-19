
/*************************************************************
Author : David Brown
Description: Linked List of employees example
Version :
Date:
**************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myfunctions.h"



#ifndef DEBUG
#define DEBUG 0
#endif
#define debug_printf(fmt, ...) \
do { if (DEBUG) { \
fprintf(stderr, "DEBUG %s[%d] %s() " fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__); \
fflush(stderr); } }while (0)

struct employees *head;

int main(int argc, char **argv) {
	
    
	struct employees  *curr;
	int count=0;
    char buf[BUFFER_SIZE] ;
	
	FILE *fp    = fopen("sample.csv", "r");
	FILE *fpout = fopen("outfile.txt", "w");
  
    debug_printf("Starting application \n");
	
	
	checkFileOpen(fp,"Can't open file for reading");
    
    checkFileOpen(fpout,"Can't open file for writing");
	
	//
	// Create root of binary tree
	//

    root = NULL; // Initialize the binary tree
	
    //
    // Create a new employee data structure and Make  this employee node the start of the linked list.
	//
    head = (struct employees*) malloc(sizeof(struct employees)) ;
	if ( head == NULL ){
		printf("There has been a malloc error creating the link list head\n");
		exit(1);
	}
	head->next = NULL;
    

    curr=head; 	
	
	
    while (fgets(buf, sizeof(buf), fp)) {
		buf[strlen(buf)-1]='\0';  // remove carriage return from line buffer
		
		count++;
		
		// Add employee to Linked list
		curr=listAdd(curr,buf,count);
		
		// Add an employee into the Employee Binary Tree
		insertBtreeEmployee(buf,count); 
		
		// Rearrange fields and write to output file.
		fprintf(fpout, "%s,%s,%s\n",curr->city,curr->surname,curr->name);
		
    }

    
    fclose(fp);       // close input file 
    fclose(fpout);    // close output file
	
	
	//logmesg("=====> Print list \n");
	//logmesg("=====> Print list \n");
	main_menu(head);
	
	
	
	return EXIT_SUCCESS;;
    
}

