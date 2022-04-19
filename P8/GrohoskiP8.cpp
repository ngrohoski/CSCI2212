//-----------------------------------------------------------------------------
// Nathan Grohoski
// CSCI-2212-01
// Program 8: Crop
//
// This program will take an input pgm image file, read in the size of said
// file, including the text header and binary pixel portions, and then crop
// the picture to a desired size.
//-----------------------------------------------------------------------------
#include "tools.hpp"
#include "pgm.hpp"

#define IN "turkey.pgm"
#define OUT "out.pgm"
//-----------------------------------------------------------------------------
int main(void){
    
    //Print one time header
    banner();
    cout <<"        Program 8: Crop\n"
         <<"--------------------------------------------------------\n";
    
    //Open input/output pgm files
    ifstream pgmFile( IN );
    if (!pgmFile.is_open()) fatal( "Can't open %s for input", IN );
    ofstream outFile( OUT );
    if (!outFile.is_open()) fatal( "Can't open %s for output", OUT );
    
    pgm pic( pgmFile );
    pic.crop();
    pic.print( outFile );
    
    bye();
    return 0;
}
//-----------------------------------------------------------------------------
