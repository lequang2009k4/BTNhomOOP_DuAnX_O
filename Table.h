// Table.h
#ifndef TABLE_H
#define TABLE_H

#include "Cell.h"
#include "Player.h"

class Table {
private:
    Cell arr[10][10];
    bool gameFinished;

public:
    Table();

    void input(Player& currentPlayer);
    void takeTurn(Symbol* currentPlayer);
    void check();
    void output();
};

#endif // TABLE_H
