#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

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

void *merge(struct node *first, struct node *second) {
	
	struct node *last;
	
	if(first->data < second->data){
		last = first;
		first = first->next;
		last->next = NULL;
	} else {
		last = second;
		second = second->next;
		last->next = NULL;
	}
	
	while(first!=NULL && second!=NULL) {
		
		if(first->data < second->data) {
			last->next = first;
			last = first;
			first = first->next;
			last->next = NULL;
		} else {
			last->next = second;
			last = second;
			second = second->next;
			last->next = NULL;
		}
	}
	
	if(first!=NULL) {
		last->next = first;
	} else {
		last->next = second;
	}
}

int main() {
	
	struct node *head1, *head2;
	head1 = NULL;
	head2 = NULL;
	
	insertLast(&head1, 3);
	insertLast(&head1, 5);
	insertLast(&head1, 8);
	insertLast(&head2, 4);
	insertLast(&head2, 7);
	insertLast(&head2, 8);
	
	traverse(head1);
	traverse(head2);
	
	merge(head1, head2);
	
	traverse(head1);
	
	return 0;
	
}