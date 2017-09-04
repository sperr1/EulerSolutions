#include <iostream>
#include <math.h>
using namespace std;

int primeGen(int n) {
	/* 
	2 is the smallest prime number. If we divide the number n in half, we either get prime factors 2 and n/2, where
	n/2 is the largest prime factor of n, or we get n/2 being either a composite or some 0.5 decimaled number. At 
	any rate, the largest prime factor of n if n is a composite has to be less than or equal to n/2, and since 
	prime factors are whole numbers we want to round DOWN whatever we get out of n/2 so that twice that resulting
	number does not exceed n.

	That said, if n was a prime number to begin with, then it is its own largest prime factor, but we don't want to
	have to calculate up to that number and confirm it's a prime; it's easier to eliminate the possibilities and say
	that if there is no prime factor smaller than n, n must be prime.
	*/
	int upperLimit = (int) floor(n / 2);
	cout << "Half of n, rounded down: " << upperLimit << endl;
	//We're going to do a Sieve of Eratosthenes to come up with primes up to half of n, rounded down
	
	//FIGURE OUT HOW TO PROPERLY MALLOC POINTER ARRAY IN SEPPLES
	int *sieve = (int*)calloc((upperLimit + 1), sizeof(int));
	/*
	Key for Sieve:
	0 - untouched value
	1 - neither prime nor composite
	2 - prime
	3 - composite
	*/

	sieve[0] = 1;
	sieve[1] = 1;
	int largestPrimeFactor = -1;
	for (int i = 0; i < upperLimit + 1; i++) {
		if (sieve[i] == 0) {
			sieve[i] = 2;
			if (n%i == 0 && i > largestPrimeFactor) {
				largestPrimeFactor = i;
			}
			int compositesCtr = 2*i;
			while (compositesCtr < upperLimit) {
				sieve[compositesCtr] = 3;
				compositesCtr += i;
			}
		}
		//after we do the sieve, we want to print out what kind of number sieve[i] is; this means doing an if, not an else if.
		if (sieve[i] == 1) {
			cout << i << " is neither a prime nor a composite number." << endl;
		}
		else if (sieve[i] == 2) {
			cout << i << " is a prime number." << endl;
		}
		else if (sieve[i] == 3) {
			cout << i << " is a composite number." << endl;
		}
	}
	
	free(sieve);
	if (largestPrimeFactor == -1) {
		largestPrimeFactor = n; //the largest prime factor of any number is either itself (for a prime number) or a prime of lesser value (for a composite number)
	}
	return largestPrimeFactor;
}

int main() {
	int bigNumber = 451;
	int answer = primeGen(bigNumber);
	if (answer == -1) {
		cout << "ERROR: something went wrong in calculating the prime factors." << endl;
	}
	else {
		cout << "The largest prime factor of " << bigNumber << " is " << answer << "." << endl;
	}
	return 0;
}