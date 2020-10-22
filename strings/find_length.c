#include<stdio.h>
#include<string.h>

int main() {
	char str[100];
	int i = 0;
	printf("Enter string:\n");
	fgets(str, 100, stdin);
	while(str[i] != '\n') {
		i++;
	}
	printf("Length of string is: %d\n", i);
	
	return 0;
	
}