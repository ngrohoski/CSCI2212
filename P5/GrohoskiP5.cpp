//-----------------------------------------------------------------------------
// Nathan Grohoski
// CSCI-2212-01
// Program 5: Shuffle
//
// This program will read the card deck output from program 4, shuffle, and
// print the newly ordered deck.
//-----------------------------------------------------------------------------
#include "tools.hpp"
#include "card.hpp"
#include "deck.hpp"

#define INF "in.txt"
#define SerOF "serialOut.txt"
#define OF "prettyOut.txt"
#define SIZE 52
//-----------------------------------------------------------------------------
int main( void ){
    //Print one time header
    banner();
    cout <<"        Program 5: Shuffle A Deck of Cards\n"
         <<"--------------------------------------------------------\n";
    
    //Open file streams, give errors if can't open
    ifstream inFile( INF );
    if( !inFile.is_open() ) fatal ("Cannot open %s for input", INF);
    ofstream serOutFile( SerOF );
    if( !inFile.is_open() ) fatal ("Cannot open %s for input", SerOF); 
    ofstream outFile( OF );
    if( !inFile.is_open() ) fatal ("Cannot open %s for input", OF); 
    
    //Read in, shuffle, print deck
    DeckT deck( inFile );
    deck.shuffle();
    deck.serialize( serOutFile );
    deck.print( outFile );
    
    bye();
    return 0;
}
//-----------------------------------------------------------------------------
