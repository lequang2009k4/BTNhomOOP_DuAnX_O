// GameSystem.h
#ifndef GAMESYSTEM_H
#define GAMESYSTEM_H

#include "Table.h"

class GameSystem {
private:
    Table tb;
    Symbol* currentPlayer;

public:
    GameSystem();
    ~GameSystem();

    void newGame();
    void showRules();
    void exitGame();
    void showMenu();
    void userSelection();
};

#endif // GAMESYSTEM_H
