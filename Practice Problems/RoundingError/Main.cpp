#include <iostream>
#include <time.h>

using namespace std;


int roundingError(int num) {
	int randVal = (rand() % 10) + 1;
	//cout << "randVal: " << randVal << endl;
	int newNum = (double) num / randVal;
	//cout << "newNum: " << newNum*randVal << ", actual value: " << ((double)num / randVal) *randVal << endl;
	newNum *= randVal;
	return newNum;
}

int main() {
	srand(time(NULL));

	int startVal = 60;
	for (int j = 0; j < 100; j++) {
		startVal = roundingError(startVal);
		//cout << "startVal: " << startVal << endl;
		int wCtr = 0;
		while (wCtr <= startVal) {
			cout << "-";
			wCtr++;
		}
		cout << endl;
		if (startVal == 0) {
			cout << "Hit zero in " << j << " iterations." << endl;
			break;
		}
	}
	return 0;
}