#include<bits/stdc++.h>

using namespace std;

string lcp_util(string s1, string s2) {
	string res;
	int n1 = s1.length();
	int n2 = s2.length();
	for(int i = 0, j = 0; i < n1, j < n2; i++, j++) {
		if(s1[i] != s2[j])
			break;
		res.push_back(s1[i]);
	}
	return res;
}

string lcp(string arr[], int n) {
	string prefix = arr[0];
	for(int i = 0; i < n; i++) {
		prefix = lcp_util(prefix, arr[i]);
	}
	return prefix;
}

int main() {
	string arr[] = {"apple", "appetite", "app"};
	string result = lcp(arr, 3);
	if(result.length()) {
		cout << "Prefix is: " << result << endl;
	} else {
		cout << "No common prefix!" << endl;
	}
	return 0;
}