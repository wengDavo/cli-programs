#include <stdio.h>
#include <stdlib.h>

// basic structure for the node using the struct syntax
// each node will have a data and a node referncing the next data in the singly linked list
struct node{
	int data;
	struct node *next;
};

// on initialization the linked list will not have a head i.e the first data in the linked list
// on initialization the linked list will not have the address of the next node
struct node *head = NULL;
struct node *current = NULL;

// function to print the linked list
void printList(){
	struct node *p = head;
	printf("\n[");
	
	//starting from the head we iterate and check if there is a value in the next node, if none linked list end
	while(p != NULL){
		printf("%d->", p->data);
		p = p->next;
	}
	// while there is a value in the next node set the current node P to the address of the next node
	printf("]");
}

// function to push data to the head of the linked list
void insertatbegin(int data){
	struct node *lk = (struct node*) malloc(sizeof(struct node));
	lk->data = data;
	lk->next = head;
	head = lk;
}

// function to append data to the tail of the linked list
void insertatend(int data){
	// create a new node link
	struct node *lk = (struct node*) malloc(sizeof(struct node));
	lk->data = data;
	struct node *linkedlist = head;
	
	// iterate over the linked list
	while(linkedlist->next != NULL){
		linkedlist = linkedlist->next;
	}
	
	// point first node to the new node created
	linkedlist->next = lk;
}

void main(){

//	First insertion
	insertatbegin(12);
	insertatbegin(20);	
	//insertatend(19);
	printf("Linked List:");
	printList();
	
//  Second insertion
	printf("\n");
	printf("\n");
	insertatbegin(12);
	insertatbegin(20);
	printf("Linked List:");
	printList();
}








