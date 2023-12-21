// Cell.h
#ifndef CELL_H
#define CELL_H

#include "Symbol.h"

class Cell : public Symbol {
private:
    char symbol;

public:
    Cell();

    char getSymbol() const override;
    void setSymbol(char s);
};

#endif // CELL_H
