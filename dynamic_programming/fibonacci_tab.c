#include<stdio.h>

int fibonacci(int n) {
	int arr[n+1];
	arr[0] = 0;
	arr[1] = 1;
	for(int i=2; i<=n; i++) {
		arr[i] = arr[i-1] + arr[i-2];
	}
	return arr[n];
}

int main() {
	int x;
	printf("Enter a number: ");
	scanf("%d", &x);
	printf("Result is: %d\n", fibonacci(x));
	return 0;
}