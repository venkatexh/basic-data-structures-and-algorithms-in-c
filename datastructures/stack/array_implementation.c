#include<limits.h>
#include<stdio.h>
#include<stdlib.h>

struct stack {
	int top;
	unsigned capacity;
	int *array;
};

struct stack *createStack(unsigned capacity) {
	struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int *)malloc(stack->capacity*sizeof(int));
	return stack;
}

int isFull(struct stack *stack) {
	return stack->top == stack->capacity-1;
}

int isEmpty(struct stack *stack) {
	return stack->top == -1;
}

void push(struct stack *stack, int x) {
	if(isFull(stack)){
		printf("Stack full.\n");
		return;
	}
	stack->array[++stack->top] = x;
	printf("%d pushed to stack. \n", x);
}

int pop(struct stack *stack) {
	if(isEmpty(stack)) {
		printf("Stack empty!");
		return INT_MIN;
	}
	return stack->array[stack->top--];
}

int peek(struct stack *stack) {
	if(isEmpty(stack)) {
		printf("Stack empty.\n");
		return INT_MIN;
	}
	return stack->array[stack->top];
}

int main() {
	
	struct stack *stack = createStack(10);
	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
	printf("%d popped from stack.\n", pop(stack));
	printf("Top element is %d.\n", peek(stack));
	
	return 0;
}