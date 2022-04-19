//-----------------------------------------------------------------------------
// Nathan Grohoski
// CSCI-2212-01
// Program 2: Search and Replace
//
// This program will read an input file and write to an output file, both
// found by user input. The user will then input a key word and a replacement
// word, if the key is found in the input it is replaced in the output.
//-----------------------------------------------------------------------------
#include "tools.h"

#define FLEN 256 //Max file length +1
#define WLEN 16  //Max word length +1
//-----------------------------------------------------------------------------
//Function Prototypes
cstream getFile( char* fileIO );
void getWords( char* key, char* replacement );
void processFile( cstream inStrm, cstream outStrm, char* key, char* replace );
//-----------------------------------------------------------------------------
int main(void){
    cstream inStrm;
    cstream outStrm;
    char key[WLEN];
    char replace[WLEN];
    
    //Print one time header
    banner();
    printf( "        Program 2: Search and Replace\n" );
    printf( "----------------------------------------------------\n" );

    inStrm = getFile( "Input" );    //Get input file stream
    outStrm = getFile( "Output" );  //Get output file steam   
    getWords( key, replace );       //Get key words
    processFile( inStrm, outStrm, key, replace ); //Read input, write output
    
	bye();
	return 0;
}
//-----------------------------------------------------------------------------
//Reads user inputs and opens either an input or output file
cstream getFile( char* fileIO ){
    cstream fileStream;
    char fileName[FLEN];
    char* fileStrng = &fileName[0];
    
	//Get and echo file names from user
	printf( "\nEnter the path of the %s file: ", fileIO );
	scanf( " %255s", fileStrng );
    
    //Set as read if input, write if output
    if (!strcmp( fileIO, "Input" )) fileStream = fopen( fileName, "r" ); 
    else fileStream = fopen( fileName, "w" );
    if (!fileStream) fatal( "\nCannot open file\n" ); //Can't open file
    printf( "%s File: %s\n", fileIO, fileStrng );  //Echo file name
    
    return fileStream;
}
//-----------------------------------------------------------------------------
//Reads user input for key and replacement words
void getWords( char* key, char* replace ){
	//Get key word and replacement from user
	printf( "\nEnter the desired key word of max 15 chars: " );
	scanf( "%15s", key );
	printf( "Enter the desired replacement word of max 15 chars: " );
	scanf( "%15s", replace );
    
    //Echo Words
    printf( "\nSearch for: %s\n", key );
    printf( "Replace with: %s\n", replace );
}
//-----------------------------------------------------------------------------
//Reads input file, searches and replaces key when writting output
void processFile( cstream inStrm, cstream outStrm, char* key, char* replace ){
    char readWord[WLEN];
    int lineCount = 0;
    
    for(;;){
        fscanf( inStrm, "%15s", readWord );   //Read word from file
        if (feof( inStrm )) break;     //Break if end of file
        
        //Look for key word
        if (!strcmp( readWord, key )){  //Key found
            fprintf( outStrm, "%s ", replace ); //Print replacement word
            lineCount += strlen(replace) + 1; //Cursor pos in output
        }
        else{
            fprintf( outStrm, "%s ", readWord );  //Print original word
            lineCount += strlen(readWord) + 1;  //Cursor pos in output   
        }
        
        //Start new line in output if more than 70 chars
        if (lineCount >= 70){
            fprintf( outStrm, "\n" );
            lineCount = 0;
        }
    }
}
