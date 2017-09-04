#include <iostream>
#include <string>

using namespace std;
int main() {

	cout << "Hello world!" << endl;

	string S("Hello world!");

	cout << S.length()<< endl;
	string revS;
	for (int i = 1; i <= S.length(); i++) {
		revS = revS + S[S.length() - i];
		cout << i << ":"<<revS[i-1] << endl;

	}

	cout << revS << endl;
	return 0;
}