// GameSystem.cpp
#include <iostream>
#include <cstdlib>
#include "GameSystem.h"

using namespace std;

GameSystem::GameSystem() : currentPlayer(new Player('X')) {}

GameSystem::~GameSystem() {
    delete currentPlayer;
}

void GameSystem::newGame() {
    Table table;
    table.output();
    tb = Table();
    currentPlayer = new Player('X');
    tb.takeTurn(currentPlayer);
}

void GameSystem::showRules() {
    system("cls");
    cout << "Rules:\n";
    cout << "\tBoard has 100 cells arranged in a 10x10 grid.\n";
    cout << "\tPlayers (X or O) take turns selecting one cell at each turn by typing the numbers 1 to 100 from the keyboard.\n";
    cout << "\tStart with Player X's turn\n";
    cout << "\tPlayers cannot reselect a cell that has been previously selected\n";
    cout << "\tThe winner is the first player who can create a chain of 5 identical symbols in a row (horizontally, vertically, or diagonally).\n";
}


void GameSystem::exitGame() {
    cout << "Exiting the game. Goodbye!\n";
    exit(0);
}

void GameSystem::showMenu() {
    cout << "\nSelect an option:\n";
    cout << "1 - Start a new game\n";
    cout << "2 - Rules\n";
    cout << "3 - Exit\n";
}

void GameSystem::userSelection() {
    int choice;
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");
        switch (choice) {
            case 1:
                newGame();
                break;
            case 2:
                showRules();
                break;
            case 3:
                exitGame();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 3);
}
