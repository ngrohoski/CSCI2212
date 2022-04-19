//-----------------------------------------------------------------------------
// Nathan Grohoski
// CSCI-2212-01
// Program 5: Shuffle
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
    CardT() = default;
    ~CardT() = default;
    CardT( SuitT suitRead, char rankRead );
    void prettyPrint( ostream& out );
    void print( ostream& out );
};
//-----------------------------------------------------------------------------
