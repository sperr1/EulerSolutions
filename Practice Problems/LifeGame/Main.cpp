#include <iostream>
#include "Cell.h"
using namespace std;

int main() {
	 Cell *c = new Cell();
	 c->~Cell();
	return 0;
}