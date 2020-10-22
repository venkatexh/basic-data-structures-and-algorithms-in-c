#include<stdio.h>
#include<string.h>

void checkPalindrome(char str[]) {
	int l, h;
	l = 0;
	h = strlen(str) - 2;
	
	while(h > l){
		if(str[l++] != str[h--]) {
			printf("Not palindrome!\n");
			return;
		}
	}
	printf("Palindrome!");
}

int main() {
	char str[50];
	int i = 0, j = 0;
	printf("Enter a word:\n");
	fgets(str, 50, stdin);
	checkPalindrome(str);
	
	return 0;
}