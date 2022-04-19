//-----------------------------------------------------------------------------
// Nathan Grohoski
// CSCI-2212-01
// Program 4: A Deck of Cards
//
// This program will generate a standard deck of 52 cards, composed of 4 suits
// each with 13. This program requires the .cpp and the .hpp files for the card
// and tools class.
//-----------------------------------------------------------------------------
#include "tools.hpp"
#include "card.hpp"

#define OF "out.txt"
#define SIZE 52
//-----------------------------------------------------------------------------
const char ranks[] = {"-A23456789TJQK"};
//-----------------------------------------------------------------------------
void writeOut(CardT deck[SIZE]);
//-----------------------------------------------------------------------------
int main( void ){
    int pos = 0;
    SuitT suit;
    char rank;
    CardT deck[SIZE]; //Construct class

    //Print one time header
    banner();
    cout <<"        Program 4: A Deck of Cards\n"
         <<"--------------------------------------------------------\n";

    //Cycle suits
    for (int k = 1; k < 5; k++){
        suit = (SuitT)k;  //Convert in to Enum type

        //Cycle ranks of cards
        for (int j = 0; j < 13; j++){
            rank = ranks[j+1];
            CardT temp(suit, rank); //Temp storage of object
            deck[pos++] = temp;     //Put object into array
        }   
    }

    writeOut(deck);

    bye();
    return 0;
}
//-----------------------------------------------------------------------------
//Uses CardT print to print to console and out.txt
void writeOut(CardT deck[SIZE]){
    //Create output file, fatal if cannot create
    ofstream outfile( OF );
    if (!outfile.is_open()) fatal( "Can't open %s for output", OF );
    
    for (int k = 0; k < SIZE; k++){
        deck[k].print( cout );    //stdout
        deck[k].print( outfile ); //output file
    }
}

