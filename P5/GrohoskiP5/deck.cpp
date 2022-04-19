//-----------------------------------------------------------------------------
// Nathan Grohoski
// CSCI-2212-01
// Program 5: Shuffle
//
// This class is used to read in the deck of cards created from the output file
// of program 4, it has the ability to shuffle the deck, and it delegates
// printing to the card class, printing in both a human freindly way as well
// as a way that matches the format original deck input file.
//-----------------------------------------------------------------------------
#include "deck.hpp"
//-----------------------------------------------------------------------------
DeckT::DeckT( ifstream& deckIn ){
    string readIn;
    SuitT suit;
    char rank;
    
    //Read input file and convert strings to CardT
    for (int k = 0; k < SIZE; k++){
        //Error if full deck of desired size isn't read in
        if (!deckIn.good()) fatal( "Full Deck not Read" );
        
        getline (deckIn, readIn); //Read in string for card
        rank = readIn[2]; //Read proper char for rank
                
        //Converts the char lable from input to SuitT       
        switch (readIn[0]){
            case 'S':
                suit = SPADES;
                break;
            case 'H':
                suit = HEARTS;
                break;
            case 'D':
                suit = DIAMONDS;
                break;
            case 'C':
                suit = CLUBS;
                break;
            default:
                suit = UNKNOWN;
        }
        
        //Construct cards and put into array
        CardT temp(suit, rank);
        deck[k] = temp;
    }
}
//-----------------------------------------------------------------------------
void DeckT::shuffle(){
    int randy;
    
    srand(time(NULL)); //initialize random seed
    
    //Shuffle Algorithm
    while (cardCount > 0){
        randy = rand() % cardCount; //Random number between 0 and deck size
        --cardCount; //Decrement shuffled card
        swap( deck[randy], deck[cardCount] ); //Swap card positions
    }
}
//-----------------------------------------------------------------------------
void DeckT::serialize( ostream& out ){
    for (int k = 0; k < SIZE; k++){
        deck[k].print( out );  //Serial output File
    }
}
//-----------------------------------------------------------------------------
void DeckT::print( ostream& out ){
    for (int k = 0; k < SIZE; k++){
        deck[k].prettyPrint( cout );  //stdout
        deck[k].prettyPrint( out );   //Pretty output file
    }
}
//-----------------------------------------------------------------------------
