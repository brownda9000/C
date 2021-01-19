#include "myqueue.h"
#include <stdlib.h>

node_t* head = NULL;
node_t* tail = NULL;

void enqueue( int *client_socket) {
    // Create memory allocation for new node
    node_t *newnode = malloc(sizeof(node_t));

    newnode->client_socket = client_socket;

    newnode->next = NULL;

    if ( tail == NULL ) {
        head = newnode;
    } else {
        tail->next = newnode;
    }

    tail = newnode;
   
}

int* dequeue() {
    // if queue empty return NULL
    // otherwise return the pointer
    if ( head == NULL ) {
        return NULL;
    }
    else {
        // Retrieve the socket details
        int  *result = head->client_socket;
        // Point to old head
        node_t *temp = head;
        // Create not list head
        head = head->next;

        if ( head == NULL ) tail = NULL;
        
        free(temp); // Free the memory of the old head node 
        return result;

    }

  
}