#include<bits/stdc++.h>

using namespace std;

int findMinLength(string arr[], int n) {
	int min_length = arr[0].length();
	for(int i = 1; i < n; i++) {
		if(arr[i].length() < min_length)
			min_length = arr[i].length();
	}
	return min_length;
}

string lcp(string arr[], int n) {
	int min_len = findMinLength(arr, n);
	
	string res;
	char curr;
	
	for(int i = 0; i < min_len; i++) {
		curr = arr[0][i];
		for(int j = 1; j < n; j++) {
			if(arr[j][i] != curr)
				return res;
		}
		res.push_back(curr);
	}
	return res;
}

int main() {
	string arr[] = {"apple", "appetite", "app"};
	int n = sizeof(arr)/sizeof(arr[0]);
	string res = lcp(arr, n);
	if(res.length())
		cout << "Longest common prefix: " << res << endl;
	else
		cout << "No common prefix!" << endl;
	return 0;
	
}