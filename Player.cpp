// Player.cpp
#include "Player.h"

Player::Player(char s) : symbol(s) {}

char Player::getSymbol() const {
    return symbol;
}
