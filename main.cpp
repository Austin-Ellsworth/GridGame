#include <iostream>
#include <stdlib.h> 
#include <time.h> 


using namespace std;

void createBoard();
void printBoard();
bool moveEnemy();
bool movePlayer();

char gameBoard[14][20];
int playerX = 1;
int playerY = 1;
int goalY = 13;
int goalX = 19;
int enemy1Y = 7;
int enemy1X = 9;
int enemy2Y = 4;
int enemy2X = 1;
int enemy3Y = 9;
int enemy3X = 3;

int main() {
	char start = 'x';
	char playAgain = 'y';
	cout << "\t***********************\n\t** Press S to start! **\n\t***********************\n\n";
	
	cout << "Instructions: \n1. You are player (P)\n2. Avoid traps! (T)\n3. Avoid enemies! (E)\n4. Enemies will move one space each move you make\n5. Find the treasure to win!";

	while ((start != 's') && (start != 'S')) {
		cin >> start;
	}
	
	while (playAgain == 'y' or playAgain == 'Y') {
		playerX = 1;
		playerY = 1;
		goalY = 13;
		goalX = 19;
		enemy1Y = 7;
		enemy1X = 9;
		enemy2Y = 4;
		enemy2X = 1;
		enemy3Y = 9;
		enemy3X = 3;
		system("cls");
		createBoard();
		printBoard();

		while (movePlayer() && moveEnemy()) { //either to return false ends game
			cout << endl;
			system("cls");
			createBoard();
			printBoard();

		}
		cout << "\n\tPlay again? (Y - yes) or (N - no)";
		cin >> playAgain;
	}

	cout << "\n\tGood Game!\n\n";
	return 0;
}

void createBoard() {
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 20; j++) {
			gameBoard[i][j] = '.';
		}
	}
	gameBoard[playerY][playerX] = 'P';
	gameBoard[enemy1Y][enemy1X] = 'E';
	gameBoard[enemy2Y][enemy2X] = 'E';
	gameBoard[enemy3Y][enemy3X] = 'E';
	gameBoard[4][12] = 'T';
	gameBoard[8][8] = 'T';
	gameBoard[11][13] = 'T';
	gameBoard[goalY][goalX] = 'X';
}

void printBoard() {
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 20; j++) {
			cout << gameBoard[i][j];
		}
		cout << endl;
	}
}

bool movePlayer() {
	char input;
	cin >> input;

	if (input == 'w') {
		if (playerY != 0) {
			playerY -= 1;
		}
		else {
			cout << "You cannot move off the board\n\n";
		}
	}
	else if (input == 'd') {
		if (playerX != 19) {
			playerX += 1;
		}
		else {
			cout << "You cannot move off the board\n\n";
		}
	}
	else if (input == 's') {
		if (playerY != 13) {
			playerY += 1;
		}
		else {
			cout << "You cannot move off the board\n\n";
		}
	}
	else if (input == 'a') {
		if (playerX != 0) {
			playerX -= 1;
		}
		else {
			cout << "You cannot move off the board\n\n";
		}
	}
	else {
		cout << "That's not a valid input\n\n";
	}

	if (gameBoard[playerY][playerX] == 'T') {
		cout << "\n\tYou've stumbled into a trap, and have parished.\n";
		return false;
	}
	if (gameBoard[playerY][playerX] == 'E') {
		cout << "\n\tYou've been flanked by an enemy, and have met an untimely demise.\n";
		return false;
	}
	if (gameBoard[playerY][playerX] == 'X') {
		cout << "\n\tYou've finally found the treasure, and make a quick escape.\n";
		return false;
	}

	return true;
}

bool moveEnemy() {
	int move;
	srand(time(0));
	move = rand() % 4;
	if (move == 0) {
		if (enemy1Y != 0) {
			enemy1Y -= 1;
		}
	}
	else if (move == 1) {
		if (enemy1X != 19) {
			enemy1X += 1;
		}
	}
	else if (move == 2) {
		if (enemy1Y != 13) {
			enemy1Y += 1;
		}
	}
	else if (move == 3) {
		if (enemy1X != 0) {
			enemy1X -= 1;
		}
	}

	move = rand() % 4;
	if (move == 0) {
		if (enemy2Y != 0) {
			enemy2Y -= 1;
		}
	}
	else if (move == 1) {
		if (enemy2X != 19) {
			enemy2X += 1;
		}
	}
	else if (move == 2) {
		if (enemy2Y != 13) {
			enemy2Y += 1;
		}
	}
	else if (move == 3) {
		if (enemy2X != 0) {
			enemy2X -= 1;
		}
	}

	move = rand() % 4;
	if (move == 0) {
		if (enemy3Y != 0) {
			enemy3Y -= 1;
		}
	}
	else if (move == 1) {
		if (enemy3X != 19) {
			enemy3X += 1;
		}
	}
	else if (move == 2) {
		if (enemy3Y != 13) {
			enemy3Y += 1;
		}
	}
	else if (move == 3) {
		if (enemy3X != 0) {
			enemy3X -= 1;
		}
	}

	if ((playerY == enemy1Y && playerX == enemy1X) || (playerY == enemy2Y && playerX == enemy2X) || (playerY == enemy3Y && playerX == enemy3X)) {
		cout << "\n\tYou've been flanked by an enemy, and have met an untimely demise.\n";
		return false;
	}
}