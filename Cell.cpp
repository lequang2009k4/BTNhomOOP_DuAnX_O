// // Cell.cpp
#include "Cell.h"

Cell::Cell() : symbol(' ') {}

char Cell::getSymbol() const {
    return symbol;
}

void Cell::setSymbol(char s) {
    symbol = s;
}
