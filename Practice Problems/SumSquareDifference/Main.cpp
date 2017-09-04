#include <iostream>

using namespace std;

int sigma(int min, int max) {
	int sum = 0;
	for (int i = min; i <= max; i++) {
		sum += i;
	}
	return sum;
}
int sigmaSquare(int min, int max) {
	int sum = 0;
	for (int i = min; i <= max; i++) {
		sum += (int)pow(i, 2);
	}
	return sum;

}

int uniSigma(int min, int max) {
	int sumA = 0;
	int sumB = 0;
	for (int i = min; i <= max; i++) {
		sumA += (int)pow(i, 2);
		sumB += i;
	};
	sumB = (int)pow(sumB, 2);
	return (sumB - sumA);
}

int main() {
	int low = 1;
	int high = 10;
	int sumA = sigmaSquare(low, high);
	cout << "sum of squares of first "<<high<<" numbers: " << sumA << endl;
	int sumB = pow(sigma(low, high),2);
	cout << "square of sum of first "<<high<<" numbers: " << sumB << endl;
	int diffAB = sumB - sumA;
	cout << "difference of the two: " << diffAB << endl;
	int diffABround2 = uniSigma(low, high);
	cout << "difference when doing it all in a single function: " << diffABround2 << endl;
	return 0;
}