#include<iostream>
#include<stdlib.h>

using namespace std;

class Node {
	public:
	int data;
	Node *next;
};

class LinkedList {
	public:
	LinkedList() {
		head = NULL;
	}
	~LinkedList() {}
	void insertLast(int k);
	void traverse();
	
	
	Node *head;
};

void LinkedList::insertLast(int k) {
	Node *new_node = new Node();
	new_node->data = k;
	new_node->next = NULL;
	if(head == NULL) {
		head = new_node;
	} else {
		Node *temp = head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new_node;
	}
}

void LinkedList::traverse() {
	if(head == NULL) {
		cout << "List empty!" << endl;
	} else {
		Node *temp = head;
		while(temp != NULL) {
			cout << "->" << temp->data;
			temp = temp->next;
		}
		cout << endl;
	}
}

void insert_in_sorted(Node *head, int k) {
	Node *temp = new Node();
	temp->next = NULL;
	temp->data = k;
	if(head == NULL) {
		head = temp;
		return;
	}
	Node *p = head;
	while(p->next != NULL ) {
		if(p->data < k) {
			p = p->next;
		} else {
			break;
		}
	}
	if(p->data > k) {
		temp->data = p->data;
		p->data = k;
		temp->next = p->next;
		p->next = temp;
	} else {
		p->next = temp;
	}
}

int main() {
	LinkedList *list = new LinkedList();
	list->insertLast(10);
	list->insertLast(25);
	list->insertLast(30);
	list->insertLast(40);
	list->traverse();
	insert_in_sorted(list->head, 35);
	list->traverse();
	delete list;
	return 0;
}