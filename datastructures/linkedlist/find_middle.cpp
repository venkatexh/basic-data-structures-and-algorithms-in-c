#include<iostream>

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

int find_middle(Node *head){
  if(head == NULL)
    return 0;
  Node *p = head;
  Node *q = head;
  while(q != NULL && q->next != NULL) {
    p = p->next;
    q = q->next->next;
  }
  return p->data;
}

int main() {
	LinkedList *list = new LinkedList();
	list->insertLast(10);
	list->insertLast(20);
	list->insertLast(30);
	list->insertLast(40);
  list->insertLast(50);
	list->traverse();
  int k = find_middle(list->head);
  if(k) {
    cout << k <<endl;
  }
	delete list;
	return 0;
}