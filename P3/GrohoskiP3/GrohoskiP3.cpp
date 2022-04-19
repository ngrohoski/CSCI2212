//-----------------------------------------------------------------------------
// Nathan Grohoski
// CSCI-2212-01
// Program 3: Little Brown Dog
//
// This program will read the file defined, push all lines of text up to the
// new line character into a vector, sort every line of said vector, and print 
// the output to another text file. 
//-----------------------------------------------------------------------------
#include "tools.hpp"
#define INF "p3-BrownDog.txt"
#define OF  "out.txt"
//-----------------------------------------------------------------------------
//Function prototypes
void processFiles( ifstream& infile, ofstream& outfile );
//-----------------------------------------------------------------------------
int main( void ){
    //Print one time header
    banner();
    cout <<"        Program 3: Little brown dog\n"
         <<"--------------------------------------------------------\n";

    //Read input file, give error if can't open
    ifstream infile( INF );
    if (!infile.is_open()) fatal( "Can't open %s for input", INF );

    //Read output file, give error if can't open
    ofstream outfile( OF );
    if (!outfile.is_open()) fatal( "Can't open %s for output", OF );
    
    cout << "Output will print to out.txt\n"
         << "The file will be created in the location of the Program\n";

    processFiles( infile, outfile );

    bye();
    return 0;
}
//-----------------------------------------------------------------------------
//Function will process input file, sort strings, and write output file
void processFiles( ifstream& infile, ofstream& outfile){
    vector<string> v;
    string readIn;

    //Get strings from input
    for(;;){
        if (infile.eof()) break; //break if end of file
        getline( infile, readIn );
        v.push_back( readIn );   //Put all strings into vector for sorting
    }

    //Sort strings
    sort( v.begin(), v.end() );

    //Print sorted vector to output file
    for( int k = 0; k < v.size(); k++ ){
        outfile << v[k];
    }
}
//-----------------------------------------------------------------------------
