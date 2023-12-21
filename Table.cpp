// Table.cpp
#include <iostream>
#include <iomanip>
#include "Table.h"

using namespace std;

Table::Table() : gameFinished(false) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            arr[i][j] = Cell();
        }
    }
}

void Table::input(Player& currentPlayer) {
    int row, col;
    while (true) {
        std::cout << "Player " << currentPlayer.getSymbol() << "'s turn (1-10, 1-10):\n";

        // Nhập hàng
        do {
            cout << "Enter row (1-10): ";
            cin >> row;
            if (row < 1 || row > 10) {
                cout << "Invalid row! Please enter a number between 1 and 10.\n";
            }
        } while (row < 1 || row > 10);

        // Nhập cột
        do {
            cout << "Enter column (1-10): ";
            cin >> col;
            if (col < 1 || col > 10) {
                cout << "Invalid column! Please enter a number between 1 and 10.\n";
            }
        } while (col < 1 || col > 10);

        system("cls");

        if (arr[row - 1][col - 1].getSymbol() == ' ') {
            arr[row - 1][col - 1].setSymbol(currentPlayer.getSymbol());
            output();
            check();
            break;
        } else {
            output();
            cout << "Cell already occupied! Enter again: \n";
        }
    }
}

void Table::takeTurn(Symbol* currentPlayer) {
    do {
        input(*dynamic_cast<Player*>(currentPlayer));
        currentPlayer = (currentPlayer->getSymbol() == 'X') ? new Player('O') : new Player('X');
    } while (!gameFinished);
}

void Table::check() {
	    // Check for 5 in a row horizontally
	for (int i = 0; i < 10; i++) {
	    for (int j = 0; j <= 5; j++) {
	        if ((arr[i][j].getSymbol() == 'X' && arr[i][j + 1].getSymbol() == 'X' && arr[i][j + 2].getSymbol() == 'X' &&
	             arr[i][j + 3].getSymbol() == 'X' && arr[i][j + 4].getSymbol() == 'X') ||
	            (arr[i][j].getSymbol() == 'O' && arr[i][j + 1].getSymbol() == 'O' && arr[i][j + 2].getSymbol() == 'O' &&
	             arr[i][j + 3].getSymbol() == 'O' && arr[i][j + 4].getSymbol() == 'O')) {
	            cout << "Player " << arr[i][j].getSymbol() << " wins!\n";
	            gameFinished = true;
	            return;
	        }
	    }
	}
	
	    // Check for 5 in a row vertically
	for (int i = 0; i <= 5; i++) {
	    for (int j = 0; j < 10; j++) {
	        if ((arr[i][j].getSymbol() == 'X' && arr[i + 1][j].getSymbol() == 'X' && arr[i + 2][j].getSymbol() == 'X' &&
	             arr[i + 3][j].getSymbol() == 'X' && arr[i + 4][j].getSymbol() == 'X') ||
	            (arr[i][j].getSymbol() == 'O' && arr[i + 1][j].getSymbol() == 'O' && arr[i + 2][j].getSymbol() == 'O' &&
	             arr[i + 3][j].getSymbol() == 'O' && arr[i + 4][j].getSymbol() == 'O')) {
	            cout << "Player " << arr[i][j].getSymbol() << " wins!\n";
	            gameFinished = true;
	            return;
	        }
	    }
	}
	
	    // Check for 5 in a row diagonally (top-left to bottom-right)
	for (int i = 0; i <= 5; i++) {
	    for (int j = 0; j <= 5; j++) {
	        if ((arr[i][j].getSymbol() == 'X' && arr[i + 1][j + 1].getSymbol() == 'X' && arr[i + 2][j + 2].getSymbol() == 'X' &&
	             arr[i + 3][j + 3].getSymbol() == 'X' && arr[i + 4][j + 4].getSymbol() == 'X') ||
	            (arr[i][j].getSymbol() == 'O' && arr[i + 1][j + 1].getSymbol() == 'O' && arr[i + 2][j + 2].getSymbol() == 'O' &&
	             arr[i + 3][j + 3].getSymbol() == 'O' && arr[i + 4][j + 4].getSymbol() == 'O')) {
	            cout << "Player " << arr[i][j].getSymbol() << " wins!\n";
	            gameFinished = true;
	            return;
	        }
	    }
	}
	
	    // Check for 5 in a row diagonally (top-right to bottom-left)
	for (int i = 0; i <= 5; i++) {
	    for (int j = 4; j < 10; j++) {
	        if ((arr[i][j].getSymbol() == 'X' && arr[i + 1][j - 1].getSymbol() == 'X' && arr[i + 2][j - 2].getSymbol() == 'X' &&
	             arr[i + 3][j - 3].getSymbol() == 'X' && arr[i + 4][j - 4].getSymbol() == 'X') ||
	            (arr[i][j].getSymbol() == 'O' && arr[i + 1][j - 1].getSymbol() == 'O' && arr[i + 2][j - 2].getSymbol() == 'O' &&
	             arr[i + 3][j - 3].getSymbol() == 'O' && arr[i + 4][j - 4].getSymbol() == 'O')) {
	            cout << "Player " << arr[i][j].getSymbol() << " wins!\n";
	            gameFinished = true;
	            return;
	        }
	    }
	}
	
	    // Check for a tie
	bool isTie = true;
	for (int i = 0; i < 10; ++i) {
	    for (int j = 0; j < 10; ++j) {
	        if (arr[i][j].getSymbol() == ' ') {
	            isTie = false;
	            break;
	        }
	    }
	    if (!isTie) {
	        break;
	    }
	}
	
	if (isTie) {
	    cout << "It's a tie!\n";
	    gameFinished = true;
	}
}


void Table::output() {
    // In chỉ mục cột
    cout << "   ";
    for (int i = 1; i <= 10; i++) {
        cout << setw(4) << i;
        cout << " ";
    }
    cout << "\n";

    // In định dạng bảng
    cout << "   +";
    for (int i = 0; i < 10; i++) {
        cout << "----+";
    }
    cout << "\n";

    // In bảng và chỉ mục hàng
    for (int i = 0; i < 10; i++) {
        cout << setw(2) << i + 1 << " |";
        for (int j = 0; j < 10; j++) {
            cout << " " << setw(2) << arr[i][j].getSymbol() << " |";
        }
        cout << "\n   +";
        for (int j = 0; j < 10; j++) {
            cout << "----+";
        }
        cout << "\n";
    }
}