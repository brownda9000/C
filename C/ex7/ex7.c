
/*************************************************************
Author : David Brown
Description: Linked List of employees example
Version :
Date:
**************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 80
#define MAX_SURNAME 80
#define MAX_CITY 80

/*
void  getField2 ( char buf[1024], int fieldno ) {
//const char* getField ( char buf[], int fieldno ) {
  // Retrieve a specified field from a line of text buffer
     
         char   name [80];
         int    fieldpos=0 , pos= 0 , fieldstart=0, fieldend=0, fieldfound=0 ;

        printf("%s\n", buf);
         while ( fieldfound == 0 ) {    // While field not found
             if ( buf[pos] == ',' )  fieldpos++; 
             if ( fieldpos ==  ( fieldno - 1) && fieldstart == 0 )  { fieldstart=pos+1; }                 // Start of field 
             if ( fieldpos == fieldno )          {fieldfound=1; fieldend=pos;  } // End of Field
             pos++;
         
        } 
         strncpy(name, buf+fieldstart, (fieldend-fieldstart) );
         printf("%s start=%d end=%d \n", name, fieldstart,fieldend);
}
*/
char *getField ( char buffer[1024], int fieldno ) {
	  char *field, *value="", buf[1024];
      const char delimeter[2]=",";
	  int  ptr=1; 
	  
	  strcpy(buf, buffer);
	  /* get the first field */
      field = strtok(buf, delimeter );
	  
	  
	  
	  
	  if ( fieldno == 1 ) { 
	        value = field;
			field = NULL ; // return first field
	  }
	  
	  while ( field != NULL  ) {
		    
		    field = strtok(NULL, delimeter );  // get next field 
			
			ptr++;
			
			if ( fieldno == ptr )  { 
			    value = field;
				field = NULL;
			}			// Found field that was requested stop loop
			
				
	  }
	  
	  	  
      return value;	

}

// TODO create logging function with time and date.
void logmesg(char * mesg ) {
	fprintf(stderr,"%d %s %s %s %d %s %s", __COUNTER__, __DATE__, __TIME__, __FILE__, __LINE__, __func__ , mesg);
}

// 
// Define data structure for employee linked list.
//

struct employees {
	int emp_id;
	char  name[MAX_NAME]  , surname[MAX_SURNAME], city[MAX_CITY];
	struct employees *next, *curr;
};

void display_list(struct employees *top) {
	//
	// Print out the linked list of employees
	//
	struct employees  *ptr;
	
	
	ptr=top; // Set the currorarty point to the head of the list.
	// Traverse the linked list of employees using the ptr variable.
	while (ptr != NULL) { 
	    printf("Linked list %d,%s,%s,%s\n",ptr->emp_id, ptr->city,ptr->surname,ptr->name);
		// Assigned ptr the next node in the linked list
		ptr = ptr->next;	
    }
}


void main_menu(struct employees *top){
	char ch;
	

	
	while (ch != 'x' ) {
		system("clear");
		printf("			Main Menu\n");
		printf("			---------\n\n");
		printf("  1. Read in csv file \n");
		printf("  2. Higest Mark \n");
		printf("  3. Average Mark \n");
		printf("  4. Oldest Student \n");
		printf("  5. Display Linked list\n\n\n\n");
		printf(" Press x to exit ");
	
		scanf("%c",&ch);
	    
		switch(ch) { 
	
        	case '1' : printf(" Read in csv file \n");
      	               break;
			   
	        case '5' : display_list(top);
			           ch='-';
					   system("sleep 3");	
	                   break;

            case 'x' : break;			   
		}
        	
	
	}
	exit(1);
	
}

 

struct employees* listAdd(struct employees *node, char line[1024], int count) {
	    // Add employee to employee list
		
		struct employees *employee;
	   
		
	    node->emp_id = count++;
		
		//
		// Copy data to Employee node
		// 
		strcpy(node->name,getField(line, 1 ));
		
		strcpy(node->surname,getField(line, 2 ));
	
		strcpy(node->city,getField(line, 3 ));
		
        //
		// Create new free employee node
		//
		employee = (struct employees*) malloc(sizeof(struct employees));   // Create a new employee data structure node
		employee->next = NULL;
		// TODO : check for error allocating memory
		
		
		// Add new node to the linked list.
		node->next = employee;
		node=node->next;
		
		// Return node pointer.
		return node;
} 

void checkFileOpen(FILE *fp, char *mesg) {
     if (!fp) {
        printf("%s\n", mesg);
        //perror("Unable to open file.\n");
        exit(1);
     }
}

int main(void) {
    FILE *fp    = fopen("sample.csv", "r");
	FILE *fpout = fopen("outfile.txt", "w");
	struct employees *head, *curr;
	int count=0;
    char buf[1024] ;
  
	checkFileOpen(fp,"Can't open file for reading");
    
    checkFileOpen(fpout,"Can't open file for writing");

    //
    // Create a new employee data structure and Make  this employee node the start of the linked list.
	//
    head = (struct employees*) malloc(sizeof(struct employees)) ;
	head->next = NULL;
    // TODO : check for error allocating memory

    curr=head; 	
	
	
    while (fgets(buf, 1024, fp)) {
		buf[strlen(buf)-1]='\0';  // remove carriage return from line buffer
		
		// Add employee to list
		curr=listAdd(curr,buf,count);
		
		// Rearrange fields and write to output file.
		fprintf(fpout, "%s,%s,%s\n",curr->city,curr->surname,curr->name);
		
    }

    
    fclose(fp);       // close input file 
    fclose(fpout);    // close output file
	
	
	logmesg("=====> Print list \n");
	logmesg("=====> Print list \n");
	//main_menu(head);
	
	
	
	return 0;
    
}

