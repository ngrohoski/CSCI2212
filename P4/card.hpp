//-----------------------------------------------------------------------------
// Nathan Grohoski
// CSCI-2212-01
// Program 4: A Deck of Cards
//
// Header file for the CardT class
//-----------------------------------------------------------------------------
#pragma once

#include "tools.hpp"
//-----------------------------------------------------------------------------
enum SuitT {UNKNOWN, SPADES, HEARTS, DIAMONDS, CLUBS};
//-----------------------------------------------------------------------------
class CardT{
  private:
    SuitT suit;
    char rank;
    short points;
    
  public:
    CardT() = default;  //Null constructor
    ~CardT() = default;
    CardT( SuitT suitRead, char rankRead );
    void print( ostream& out);
};
//-----------------------------------------------------------------------------
