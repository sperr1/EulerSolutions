#include <iostream>


int main() {
	int nums[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			nums[i][j] = (i + 1)*(j + 1);
		}
	}
	return 0;
}