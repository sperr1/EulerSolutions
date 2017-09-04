#include <iostream>

using namespace std;

//generates the nth fib number 
int fibGenerator(int n) {
	int fibVal = 0;
	if (n == 0 || n == 1) {
		fibVal = 1;
	}
	else {
		if (n > 1) {
			fibVal = fibGenerator(n - 1) + fibGenerator(n - 2);
		}
	}
	return fibVal;
}

int main() {
	int fCtr = 0;
	while (fibGenerator(fCtr) <= 4000000) {
		cout << "Fibonacci Value (" << fCtr << "): " << fibGenerator(fCtr) << endl;
		fCtr++;
	}
	cout << "Next step: Sum all even Fib values up to the " << fCtr << "th value." << endl;

	int fSum = 0;
	for (int i = 0; i < 34; i++) {
		if (fibGenerator(i) % 2 == 0) {
			fSum += fibGenerator(i);
		}
	}
	cout << "Sum of all even Fibonacci numbers less than 4mil: " << fSum << endl;
}