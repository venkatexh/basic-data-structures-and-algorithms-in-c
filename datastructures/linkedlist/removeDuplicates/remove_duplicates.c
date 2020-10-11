//remove duplicates from a sorted singly linked list

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
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

void removeDuplicates(struct node **head) {
	struct node *p, *q;
	p = *head;
	q = p->next;
	
	while(q!=NULL) {
		if(p->data!=q->data) {
			p=q;
			q=q->next;
		} else {
			p->next = q->next;
			free(q);
			q = p->next;
		}
	}
}

int main() {
	
	insertLast(&head, 3);
	insertLast(&head, 5);
	insertLast(&head, 5);
	insertLast(&head, 6);
	insertLast(&head, 8);
	insertLast(&head, 8);
	traverse(head);
	removeDuplicates(&head);
	traverse(head);
	
	return 0;
}