#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedListString.h"


/* Function to push a node */
void push(struct node** head_ref, char* new_data)
{
        /* allocate node */
        struct node* new_node = malloc(sizeof(struct node));

        /* put in the data  */

        strcpy(new_node->data, new_data);


        /* link the old list off the new node */
        new_node->next = (*head_ref);

        /* move the head to point to the new node */
        (*head_ref) = new_node;
}

/* Function to print linked list */
void printList(struct node *head)
{
        struct node *temp = head;
        while (temp != NULL)
        {
                printf("%s  ", temp->data);
                temp = temp->next;
        }
}

/* Function to count the number of elements in the linked list */
int listCount(struct node *head){

	int count = 0;
	struct node *temp = head;
	while(temp != NULL) {
		temp = temp->next;
		count++;
	}
	return count;
}

void reverseList(struct node** head_ref){

	struct node* previous = NULL;
	struct node* curr = *head_ref;
	struct node* next = NULL;
	while(curr != NULL) {
		next = curr->next;
		curr->next = previous;
		previous = curr;
		curr = next;
	}
	*head_ref = previous;
}

void listAllDelete(struct node **currP){

	struct node* temp = *currP;
	struct node* next;
	while(temp != NULL) {
		next = temp->next;
		free(temp);
		temp = next;
	}
	*currP = NULL;
}

void deleteElement(struct node **currP, char *value){

	struct node* temp = *currP;
	struct node* previous;
	while(temp != NULL && !strcmp(temp->data, value)) {
		*currP = temp->next;
		free(temp);
		temp = *currP;
	}
	while(temp != NULL) {
		while(temp != NULL && strcmp(temp->data, value)) {
		previous = temp;
		temp = temp->next;
	}
	if(temp == NULL){
		 return;
	}
	previous -> next = temp -> next;
	free(temp);
	temp = previous -> next;
	}
}

