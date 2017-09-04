#include <iostream>
using namespace std;



int main() {
	int sum = 0;
	int maximum = 1000;

	for (int i = 3; i <= maximum; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}
	cout << "sum of all numbers less than " << maximum << " that are multiples of 3 or 5: " << sum << endl;
	return 0;
}