#include<bits/stdc++.h>

using namespace std;
int findMax(int a, int b);

int LCS(char *X, char *Y, int i, int j) {
	if(X[i] == '\0' || Y[j] == '\0') {
		return 0;
	} else if(X[i] == Y[j]) {
		return 1 + LCS(X, Y, i+1, j+1);
	} else {
		return findMax(LCS(X, Y, i+1, j), LCS(X, Y, i, j+1));
	}
}

int findMax(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	char X[] = "abdg";
	char Y[] = "bg";
	
	cout << "Length is: " << LCS(X, Y, 0, 0) << endl;
	return 0;
}