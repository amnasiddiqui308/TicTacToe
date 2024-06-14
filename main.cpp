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

void terminalCases(char board[3][3], bool& gameDraw) {
	bool checkWin = false;

	//Player Wins
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < 3; j++) {
			if (board[i][j] == board[i][j - 1])
				checkWin = true;

			else {
				checkWin = false;
				break;
			}
		}

		if (checkWin) {
			cout << "Player " << board[i][0] << " won!" << endl;
			return;
		}
	}

	if (!checkWin) {
		for (int i = 0; i < 3; i++) {
			for (int j = 1; j < 3; j++) {
				if (board[j][i] == board[j - 1][i])
					checkWin = true;

				else {
					checkWin = false;
					break;
				}
			}

			if (checkWin) {
				cout << "Player " << board[0][i] << " won!" << endl;
				return;
			}
		}
	}

	if (!checkWin) {
		if (((board[0][0] || board[0][2]) == board[1][1]) && (board[1][1] == board[2][2])) {
			checkWin = true;
			cout << "Player " << board[1][1] << " won!" << endl;
			return;
		}
		
		else
			checkWin = false;
	}

	//Game is Draw
	if (!checkWin) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == ' ') {
					gameDraw = false;
					break;
				}
			}
		}

		if (gameDraw) {
			cout << "Game is Draw :(" << endl;
		}
	}
}

void takingInput(char board[3][3], char player) {
	int row = 0, col = 0;

	do {
		cout << "Enter your move (row and column between 0 to 2)" << endl;
		cin >> row >> col;

		if (row < 0 || row > 2 || col < 0 || col > 2) {
			cout << "INVALID BOX HAS BEEN CHOSEN!\nEnter your move again." << endl;
		}
	} while (row < 0 || row > 2 || col < 0 || col > 2);

	board[row][col] = player;
}

int main() {
	char board[3][3], player1 = 'X', player2 = 'O';
	bool gameDraw = true;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}

	while (1) {
		displayBoard(board);
	}

}