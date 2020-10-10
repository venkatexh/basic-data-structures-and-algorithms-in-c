#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
}*head = NULL;

void traverse(struct node *node) {
	while(node!=NULL) {
		printf("->%d", node->data);
		node=node->next;
	}
	printf("\n");
}

void insertFirst(struct node **head, int key) {
	struct node* new = (struct node *)malloc(sizeof(struct node));
	new->data = key;
	
	new->next = *head;
	*head = new;
}

void insertLast(struct node **head, int key) {
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = key;
	struct node *p = *head;
	new->next = NULL;
	
	if(*head == NULL) {
		*head = new;
		return;
	}
	while(p->next!=NULL) {
		p = p->next;
	}
	p->next = new;
	
}

void deleteFirst(struct node **head) {
	if(*head == NULL)
		return;
	struct node *p = *head;
	*head = p->next;
	free(p);
}

void deleteLast(struct node **head) {
	if(head == NULL)
		return;
	struct node *p = *head;
	struct node *prev;
	while(p->next!=NULL) {
		prev = p;
		p=p->next;
	}
	free(p);
	prev->next = NULL;
}

int main() {
	insertFirst(&head, 20);
	insertFirst(&head, 10);
	insertLast(&head, 30);
	insertLast(&head, 40);
	traverse(head);
	deleteFirst(&head);
	deleteLast(&head);
	traverse(head);
	return 0;
}