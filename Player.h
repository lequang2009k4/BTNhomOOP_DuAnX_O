// // Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "Symbol.h"

class Player : public Symbol {
private:
    char symbol;

public:
    Player(char s);

    char getSymbol() const override;
};

#endif // PLAYER_H
