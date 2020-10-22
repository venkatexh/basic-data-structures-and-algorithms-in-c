#include<stdio.h>

int main() {
	char str[50];
	int i = 0, j = 0;
	printf("Enter a string: \n");
	fgets(str, 50, stdin);
	while(str[i] != '\n') {
		i++;
	}
	char temp;
	for(i, j; i != j; i--, j++) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	printf("Reversed string: %s\n", str);
	
	return 0;
}