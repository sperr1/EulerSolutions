#include <iostream>
#include <time.h>
using namespace std;

int* gameGenerator() {

	int game[] = { 0, 0, 0 };
	int winRoom = rand() % 3;
	game[winRoom] = 1;
	return game;
}

int hallOption(int* g, int choice) {
	int roomChoice = rand() % 3;
	while (roomChoice == choice || g[roomChoice] == 1) {
		if (roomChoice == choice) {
			//cout << "Whoops, can't reveal the door you chose!" << endl;
		}
		if (g[roomChoice] == 1) {
			//cout << "Whoops, can't reveal the winning door!" << endl;
		}
		roomChoice = rand() % 3;
	}
	//cout << "Room " << roomChoice+1 << " status: " << g[roomChoice] << endl;
	return roomChoice;
}

int doorChangeCalculator(int initialDoor, int revealedDoor) {
	int sum = initialDoor + revealedDoor;
	switch (sum) {
		case 1: return 2;
		case 2: return 1;
		case 3: return 0;
	}
}
int main() {
	srand(time(NULL));
	int round = 0;

	int winStay = 0;
	int loseStay = 0;
	int winSwitch = 0;
	int loseSwitch = 0;

	int* game;
	while (true) {
		round++;
		game = gameGenerator();
		//cout << "Game " << round<<"|";
		for (int i = 0; i < 3; i++) {
			//cout << " Door " << i+1 << ": " << game[i];
		}
		//cout << endl;
		//choose a door
		int doorChoice = rand() % 3;
		//cout << "Choosing door " << doorChoice + 1 << "." << endl;
		//host opens a losing door that you haven't picked
		int revealDoor = hallOption(game, doorChoice);
		//cout << "The door to be revealed will be " << revealDoor + 1 << "." << endl;
		//choose to stay or switch door choice
		int switchDoor = doorChangeCalculator(doorChoice, revealDoor);
		//cout << "If switching, door will be " << switchDoor+1 << "." << endl;
		//evaluate results, then repeat
		if (game[doorChoice] == 1) {
			winStay++;
		}
		else {
			loseStay++;
		}

		if (game[switchDoor] == 1) {
			winSwitch++;
		}
		else {
			loseSwitch++;
		}

		if (round == 10000) {
			cout << "10000 games" << endl;
			cout << "STAY: WIN " << winStay << " | LOSE " << loseStay << endl;
			cout << "SWITCH: WIN " << winSwitch << " | LOSE " << loseSwitch << endl;
			break;
		}
	}
}