#include<iostream>
#include<stdlib.h>

using namespace std;

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
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = key;
	struct node *p = *head;
	new_node->next = NULL;
	
	if(*head == NULL) {
		*head = new_node;
		return;
	}
	while(p->next!=NULL) {
		p = p->next;
	}
	p->next = new_node;
}

bool check_sorted(struct node *head) {
	if(!head) {
		return true;
	}
	if(head->next == NULL) {
		return true;
	}
	struct node *p = head->next;
	int k = head->data;
	while(p != NULL) {
		if(p->data < k) {
			return false;
		}
		k = p->data;
		p = p->next;
	}
	return true;
}

int main() {
	
	insertLast(&head, 0);
	insertLast(&head, 10);
	insertLast(&head, 30);
	insertLast(&head, 40);
	insertLast(&head, 20);
	traverse(head);
	if(check_sorted(head))
		cout << "Sorted" << endl;
	else
		cout << "Unsorted" << endl;
	traverse(head);
	cout << endl;
	return 0;
}