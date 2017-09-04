#include <iostream>
#include <string>
using namespace std;

int isPalindrome(int n) {
	//if palindrome, return 1; otherwise, return 0
	string s = to_string(n);
	int len = s.length();
	//cout << "Length of " << n << ": " << len << endl;
	int pCtr = 0;
	int palindromeHalfwayPoint = (int)floor(len / 2);
	//cout << "Half of " << len << ", rounded down: " << palindromeHalfwayPoint << endl;
	int oddLenModifier = 0;
	if (len % 2 == 1) {
		oddLenModifier = 1;
	}
	int whileCtr = 0;
	while (s[whileCtr] == s[len - 1 - whileCtr]) {
		//cout << "Inside the While Loop." << endl;
		if (whileCtr >= palindromeHalfwayPoint) {
			//cout << n << " is a palindrome." << endl;
			return 1;
		}
		whileCtr++;
	}
	//cout << "Out of the While Loop." << endl;
	//cout << n << " is not a palindrome." << endl;
	return 0;
}

int main() {
	/*isPalindrome(1);
	isPalindrome(10);
	isPalindrome(9009);
	isPalindrome(8675309);
	*/
	int digitA = 999;
	int digitB = 999;
	int palindromeAB = 0;
	int productAB = 0;
	int largestPalindrome = 0;
	int largestA = 0;
	int largestB = 0;
	int ctr = 0;
	while (digitA>100) {
		productAB = digitA * digitB;
		if (isPalindrome(productAB)) {
			cout << productAB << " is a palindrome." << endl;
			if (productAB > palindromeAB) {
				palindromeAB = productAB;
				largestA = digitA;
				largestB = digitB;
				cout << palindromeAB << " is the new largest palindrome." << endl;
				system("pause");
			}
		}
		digitB--;
		if (digitB < 100) {
			digitA--;
			digitB = digitA;
		}
	}
	cout << palindromeAB << " is the largest palindrome number made from the product of two 3-digit numbers (" << largestA << " and " << largestB << ")." << endl;
	return 0;
}