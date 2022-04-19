//-----------------------------------------------------------------------------
// Nathan Grohoski
// CSCI-2212-01
// Program 4: A Deck of Cards
//
// This class is used to determine the points of the generated card in order,
// it will also be used to print the information about the card.
//-----------------------------------------------------------------------------
#include "card.hpp"
//-----------------------------------------------------------------------------
const int point[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
const char* suits[] = {"U","S","H","D","C"};
const char ranks[] = {"-A23456789TJQK"};
//-----------------------------------------------------------------------------
CardT::CardT( SuitT suitRead, char rankRead ){
    suit = suitRead;
    rank = rankRead;
    
    //Get points based on card rank
    switch (rank){
        case 'A':
            points = point[1];
            break;
        case 'T':
            points = point[10];
            break;
        case 'J':
            points = point[11];
            break;
        case 'Q':
            points = point[12];
            break;
        case 'K':
            points = point[13];
            break;
        default:
            points = point[ rank - '0' ];
    }
}
//-----------------------------------------------------------------------------
void CardT::print( ostream& out){
    out << suits[suit] << " " << rank << " " << points << endl;
}
