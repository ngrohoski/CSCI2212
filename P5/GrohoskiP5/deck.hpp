//-----------------------------------------------------------------------------
// Nathan Grohoski
// CSCI-2212-01
// Program 5: Shuffle
//
// Header file for the DeckT class
//-----------------------------------------------------------------------------
#pragma once

#include "tools.hpp"
#include "card.hpp"

#define SIZE 52
//-----------------------------------------------------------------------------
class DeckT{
  private:
    CardT deck[SIZE];
    int cardCount = SIZE;
    
  public:
    DeckT() = default;
    ~DeckT() = default;
    DeckT( ifstream& deckIn );
    void shuffle();
    void serialize( ostream& out );
    void print( ostream& out );
};
//-----------------------------------------------------------------------------
