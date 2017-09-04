#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class StringList {
	string data;
	StringList *next;
public:
	StringList(string);
	string getData();
	void printS();
	StringList* getNext();
};

int main() {
	cout << "Hello World!" << endl;
	ifstream inFile;
	inFile.open("problem11_Numbers.txt");
	string line;
	char currentChar;
	
	if (inFile.is_open()) {
		cout << "file opened!" << endl;
		inFile.get(currentChar);
	}
	
	while (inFile.good()) {
		if(!iswspace(currentChar)){
			line += currentChar;
		}
		else {
			cout << "Number Sequence: " + line << endl;
			line.clear();
		}
		cout << currentChar<<endl;
		inFile.get(currentChar);
		
	}
	cout << "Line:" + line << endl;
	/*while (inFile.good()) {
		getline(inFile, line, 'q');
		cout << line << endl;
	}*/
	inFile.close();
	return 1;
};

StringList::StringList(string S)
{
	this->data = S;
}

string StringList::getData() {
	return this->data;
}

void StringList::printS() {
	cout << this->getData() << endl;
}

StringList* StringList::getNext() {
	return this->next;
}