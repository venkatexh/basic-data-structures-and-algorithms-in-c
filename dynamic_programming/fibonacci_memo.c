#include<stdio.h>

#define NIL 0
#define MAX 500

int memo[MAX];

int fibonacci(int n) {
	if(memo[n] == NIL) {
		if(n <= 1) {
			memo[n] = n;
		} else {
			memo[n] = fibonacci(n-1) + fibonacci(n-2);
		}
	}
	return memo[n];
}

int main() {
	
	for(int i=0; i<MAX; i++) {
		memo[i] = NIL;
	}
	
	int x;
	printf("Enter a number: ");
	scanf("%d", &x);
	printf("Result is: %d\n", fibonacci(x));
	return 0;
}