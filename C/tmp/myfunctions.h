/*****************************************************************************
Author : David Brown
Description: This file contains the user define functions and structure definitions
Version :
Date: 1st July 2020
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <regex.h>

/**********************************************************************************/
/***************** Define MACROS                 **********************************/
/**********************************************************************************/
#define MAX_NAME 80
#define MAX_SURNAME 80
#define MAX_CITY 80
#define BUFFER_SIZE 1024

/**********************************************************************************/
/***************** Define Data Structures         **********************************/
/**********************************************************************************/

//
//  Linked list data structure 
//
struct employees {
	int emp_id;
	char  name[MAX_NAME]  , surname[MAX_SURNAME], city[MAX_CITY];
	struct employees *next, *curr;
};

struct employees *head;  // Global head of queue

//
//  Tree data structure 
//
struct empnode {
	int node_id;
	struct employees employee;
	struct empnode *left;
	struct empnode *right;	
};

//
// Employee stack data structure.
//
struct stack {
	struct empnode *node;
	struct stack   *next;
};

struct empnode *root = NULL;       // Top of employee Binary tree
struct stack   *stackhead = NULL;  // Top of employee stack

/**********************************************************************************/
/***************** Define User Functions        **********************************/
/**********************************************************************************/
char *getField ( char buffer[BUFFER_SIZE], int fieldno ) {
	//
	// Retrieve fields from csv file
	//
	  char *field, *value="", buf[BUFFER_SIZE];
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

void checkFileOpen(FILE *fp, char *mesg) {
     if (!fp) {
        printf("%s\n", mesg);
        //perror("Unable to open file.\n");
        exit(1);
     }
}

//********************************************************************************
//**               Binary Tree Functions                                        **
//********************************************************************************

//
// Employee Stack operations 
//
void push( struct empnode *node ) {
	// Add node onto the stack
	struct stack* stackItem;
	stackItem = (struct stack *) malloc(sizeof(struct stack ));   // Create a stack node 
	
	// Add employee node onto the stack if node is not NULL
	if ( node != NULL ) {
		if ( stackhead == NULL ) {
	        stackItem->next = NULL;
        }			
	else {
	        stackItem->next = stackhead;  // Place employee node on the stack
		    
	}
	     stackItem->node = node;   // Intialize stack  node
         stackhead = stackItem;		   // Last entry become the top of the stack
	}
}

struct empnode* pop () {
	// Pop last employee off the stack
	struct empnode *last=NULL;
	
     if ( stackhead == NULL ) 
		 return NULL;
	 else {
		 last = stackhead->node; // Point to the last employee on stack
		 stackhead = stackhead->next;
		 return last;
	 }
}

//
//
//
struct empnode* createBTreeNode() {
	//
	// Create the root of the BTree data structure 
	//
	struct empnode *employee;
	
	employee = (struct empnode *) malloc(sizeof(struct empnode ));   // Create a new employee data structure node
		if ( employee  == NULL ){
		    printf("There has been a malloc error creating a new btree employee\n");
		    exit(1);
	    }
	return employee;
}

int balanceBtree() {
	// 
	// Returns 1 if the Btree is balanced otherwise return 0
	// Depth of left side differs by no more than 1 to be balanced.
	//
	struct empnode *employee=root ; // Point to the root of the tree
	int count, lcount;
	
	
	//
	// Calculate the highest depth of the left side of the tree.
	//
	count = 0;
	lcount = 0;
	
	employee=employee->left;
	
	while ( employee != NULL ) {
	    count++;
        
        if ( employee->left != NULL ) 
			employee=employee->left;
        else {
			if ( employee->right != NULL ) 
				employee=employee->right;
			else {
				
				if ( lcount ==  0 ) {
			       employee=root->left->right ;
				   lcount=count;
				   count=1;
				}
			}
		}    			
	}
	
}

void insertBtreeEmployee( char line[BUFFER_SIZE], int count) {
	//
	// Insert a employee node into the Employee binary tree.
	// 
	
	 struct empnode *node, *ptr;
	 int found=0; // 1 = we have found the node in the binary tree to insert node
	   
		
		node = createBTreeNode();
		
		//
		// Populate the Employee node with data
		// 
		node->node_id = count;  // Key for the binary tree
		
		node->employee.emp_id = count;
		
		strcpy(node->employee.name,getField(line, 1 ));
		
		strcpy(node->employee.surname,getField(line, 2 ));
	
		strcpy(node->employee.city,getField(line, 3 ));
		
		node->left  = NULL;
		node->right = NULL;
		
		if ( root == NULL )
			root = node;  // First node in tree
        else {
            // Search for where to insert node
			 // TODO
			 ptr     = root;
			 
			 
			 while ( ! found ) {
				
				if (ptr->node_id < node->node_id ) {
				    ptr=ptr->left;
				}
				else { 
			        ptr=ptr->right;
				}
				if ( ptr == NULL ) {
				    ptr = node ; // Insert Node in Employee Binary Tree
                    found = 1;					
				}
			 }
        }			
		
}

//********************************************************************************
//********************* Linked List Functions ************************************
//********************************************************************************


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

void searchSurname(struct employees *top, char* surname) {
	//
	// Print out the linked list of employees
	//
	struct employees  *ptr;
	
	
	ptr=top; // Set the currorarty point to the head of the list.
	
	// Traverse the linked list of employees using the ptr variable.
	while (ptr != NULL) {
	
		
        if ( strcmp(ptr->surname, surname) == 0	) {	
	        printf("Linked list %d,%s,%s,%s\n",ptr->emp_id, ptr->city,ptr->surname,ptr->name);
		}
		
		// Assigned ptr the next node in the linked list
		ptr = ptr->next;	
    }
}

void destroyList(struct employees *top) {
	//
	// Print out the linked list of employees
	//
	struct employees  *ptr, *temp;
	
	
	ptr=top; // Set the currorarty point to the head of the list.
	// Traverse the linked list of employees using the ptr variable.
	while (ptr != NULL) { 
	    // Copy the pointer to the next item in the list.
	    temp = ptr->next;
		// Free memory allocated to node
		free(ptr) ;
		// Assigned ptr the next node in the linked list
		ptr = temp;	
    }
}

void deleteItem(struct employees *top, int employeeid) {
	//
	// Delete node out the linked list of employees
	//
	struct employees  *ptr, *temp, *prev;
	
	
	ptr=top; // Set the current ptr point to the head of the list.
	prev=NULL;
	
	
	// Traverse the linked list of employees using the ptr variable.
	while (ptr != NULL) { 
	
         if ( ptr->emp_id ==  employeeid ) { // Found node to delete in the Linked list
			 if ( ptr == head ) {
				temp = head->next;  // Get new head of list
				free(head);         // Unallocated the memory from the head node
				head = temp;        // Assign new node to the head of the list 
			 }
			 else {
				 // Join the previous and next node to maintain the linked list
				 prev->next = ptr->next;
				 free(ptr); // Unallocated the memory from the ptr(current) node
				 
			 }
			 ptr = NULL; // Exit while loop now
		 }
		
		 if ( ptr != NULL ) {
			prev = ptr;       // Current ptr becomes previous node ptr

			ptr = ptr->next;  // Advance to the next node.		 
	     }
    }
}

void printEmployeesHtml(struct employees *top) {
	//
	// Print out a html table of the linked list of employees in html
	//
	FILE *fphtml = fopen("employee.html", "w");
	struct employees  *ptr;
	
	checkFileOpen(fphtml,"Can't open html file for writing");
	
	ptr=top; // Set the currorarty point to the head of the list.
	// Traverse the linked list of employees using the ptr variable.
	
	fprintf(fphtml,"<HTML><BODY>\n<head>\n<style>\n table, th, td {\n  border: 1px solid black;\n  border-collapse: collapse;\nbackground-color: #f1f1c1;\n}\n</style>\n</head>\n<table style='width:100%%'>\n");
	
	// Print table row of column headings
	fprintf(fphtml,"<tr>\n");
	fprintf(fphtml,"<th>%s</th>\n","Employee id");
	fprintf(fphtml,"<th>%s</th>\n","Name");
	fprintf(fphtml,"<th>%s</th>\n","Surname");
	fprintf(fphtml,"<th>%s</th>\n","City");
	fprintf(fphtml,"</tr>\n");
	
	while (ptr != NULL) { 
	    // Print table row of data
     	fprintf(fphtml,"<tr>\n");
		fprintf(fphtml,"<th>%08d</th>\n",ptr->emp_id);
		fprintf(fphtml,"<th>%s</th>\n",ptr->name);
		fprintf(fphtml,"<th>%s</th>\n",ptr->surname);
		fprintf(fphtml,"<th>%s</th>\n",ptr->city);
		fprintf(fphtml,"</tr>\n");
		
		// Assigned ptr the next node in the linked list
		ptr = ptr->next;
    }
	
	fprintf(fphtml,"<table><BODY><HTML>");
	
	fclose(fphtml); // Close the html output file
}


void main_menu(){
	char ch;   // menu input 
	char str[MAX_SURNAME]; // String for searching
	int  emp_id=0;
	

	
	while (ch != 'x' ) {
		system("clear");
		printf("\033[0;32m			Main Menu\n");
		printf("			---------\n\n");
		printf("  1. Display Btree of employees \n");
		printf("  2. Higest Mark \n");
		printf("  3. Average Mark \n");
		printf("  4. Search for Student \n");
		printf("  5. Destroy linked list \n");
		printf("  6. Print html employee file \n");
		printf("  7. Delete item from list \n");
		printf("  8. Display linked list\n\n\n\n");
		printf(" Press x to exit ");
	
		scanf("%c",&ch);
	    
		switch(ch) { 
	
        	case '1' : // TODO
      	               break;
					   
			case '4' : system("clear");
			           printf("Search for surname : ");
			           scanf("%s", &str[MAX_SURNAME]);
		               searchSurname(head,&str[MAX_SURNAME]);
					   system("sleep 3");	
					   break;
					   
			case '5' : destroyList(head); // Destroy list nodes if list not empty
			           head=NULL;        // clear the Linked list
      	               break;
					   
			case '6' : printEmployeesHtml(head);
			           break;
					   
			case '7' : system("clear");
			           display_list(head);
					   printf("\n\n\n\nPlease enter employee id to delete : ");
			           scanf("%d", &emp_id );
			           deleteItem(head,emp_id);
					   break;
					   
	        case '8' : display_list(head);
			           ch='-';
					   system("sleep 3");	
	                   break;

            case 'x' : break;			   
		}
        	
	
	}
	exit(1);
	
}

 

struct employees* listAdd(struct employees *node, char line[BUFFER_SIZE], int count) {
	    // Add employee to employee list
		
		struct employees *employee;
	   
		
	    node->emp_id = count;
		
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
		if ( employee == NULL ){
		    printf("There has been a malloc error creating a new employee\n");
		    exit(1);
	    }
		employee->next = NULL;
		// TODO : check for error allocating memory
		
		
		// Add new node to the linked list.
		node->next = employee;
		node=node->next;
		
		// Return node pointer.
		return node;
} 

