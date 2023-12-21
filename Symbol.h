// Symbol.h
#ifndef SYMBOL_H
#define SYMBOL_H

class Symbol {
public:
    virtual char getSymbol() const = 0;
    virtual ~Symbol() {}
};

#endif // SYMBOL_H
