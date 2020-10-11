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

void reverse(struct node **head) {
	struct node *p, *q, *r;
	p = *head;
	q = NULL;
	r = NULL;
	while(p!=NULL) {
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	*head = q;
}

int main() {
	
	insertLast(&head, 10);
	insertLast(&head, 20);
	insertLast(&head, 30);
	insertLast(&head, 40);
	traverse(head);
	reverse(&head);
	traverse(head);
	
	return 0;
}