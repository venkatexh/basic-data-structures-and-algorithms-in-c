#include<stdio.h>
#include<stdlib.h>

struct Node {
	struct Node *left;
	struct Node *right;
	int data;
}*root=NULL;

void insert(int key) {
	struct Node *t = root;
	struct Node *r, *p;
	
	p = (struct Node *)malloc(sizeof(struct Node));
	p->data = key;
	p->left = p->right = NULL;
	
	if(root == NULL) {
		root = p;
		return;
	}
	
	while(t!=NULL){
		r = t;
		if(key < t->data) {
			t = t->left;
		} else if(key > t->data) {
			t = t->right;
		} else {
			return;
		}
	}
	
	if(key < r->data) {
		r->left = p;
	} else {
		r->right = p;
	}
}

struct Node * search(int key) {
	struct Node *t = root;
	if(root == NULL) {
		return NULL;
	}
	while(t!=NULL) {
		if(key == t->data) {
			return t;
		} else if(key < t->data) {
			t = t->left;
		} else {
			t = t->right;
		}
	}
	return NULL;
}

void inorder(struct Node *t) {
	if(t==NULL) {
		return;
	}
	inorder(t->left);
	printf("%d ", t->data);
	inorder(t->right);
}

int main() {
	struct Node *temp;
	insert(10);
	insert(5);
	insert(20);
	insert(8);
	insert(30);
	
	inorder(root);
	temp = search(30);
	if(temp){
		printf("\nElement %d found\n", temp->data);
	} else {
		printf("\nElement not found\n");
	}
	return 0;
}