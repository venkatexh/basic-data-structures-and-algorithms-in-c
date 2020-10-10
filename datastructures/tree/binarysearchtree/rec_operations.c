#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *createNode(int val) {
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = val;
	temp->left = temp->right = NULL;
	return temp;
}

struct Node *insert(struct Node *temp, int val) {
	if(temp == NULL) {
		return createNode(val);
	}
	if(val>temp->data) {
		temp->right = insert(temp->right, val);
	} else if(val<temp->data) {
		temp->left = insert(temp->left, val);	
	}
	return temp;
}

struct Node *minValueNode(struct Node *node) {
	struct Node* curr = node;
	while(curr && curr->left!=NULL) {
		curr = curr->left;
	}
	return curr;
}

struct Node *delete(struct Node *node, int key) {
	if(node == NULL) {
		return node;
	}
	if(key < node->data) {
		node->left = delete(node->left, key);
	} else if(key > node->data) {
		node->right = delete(node->right, key);
	} else {
		if(node->left == NULL) {
			struct Node *temp = node->left;
			free(node);
			return temp;
		} else if (node->right == NULL) {
			struct Node *temp = node->right;
			free(node);
			return temp;
		}
		struct Node *temp = minValueNode(node->right);
		node->data = temp->data;
		node->right = delete(node->right, temp->data);
	}
	return node;
}

void inorder(struct Node *temp) {
	if(temp == NULL)
		return;
	inorder(temp->left);
	printf("%d ", temp->data);
	inorder(temp->right);
}

int main() {
	struct Node *root = NULL;
	root = insert(root, 5);
	root = insert(root, 3);
	root = insert(root, 2);
	root = insert(root, 4);
	root = insert(root, 7);
	root = insert(root, 6);
	root = insert(root, 8);
	inorder(root);
	printf("\n");
	root = delete(root, 4);
	root = delete(root, 5);
	inorder(root);
	printf("\n");
	return 0;
}
