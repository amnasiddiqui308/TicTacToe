#include<iostream>
#include<string>
using namespace std;

void displayBoard(char board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 2) {
				cout << " " << board[i][j];
			}
			else
				cout << " " << board[i][j] << " |";
		}

		if (i != 2)
			cout << "\n---+---+---\n";
		else
			cout << endl;
	}
}

int main() {
	char board[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = '0';
		}
	}
	displayBoard(board);
}