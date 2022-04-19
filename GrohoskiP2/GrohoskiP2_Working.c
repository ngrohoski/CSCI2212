//-----------------------------------------------------------------------------
// Nathan Grohoski
// CSCI-2212-01
// Program 2: Search and Replace
//
// 
//-----------------------------------------------------------------------------
#include "tools.h"

#define FLEN 256 //Max file length +1
#define WLEN 16  //Max word length +1

//-----------------------------------------------------------------------------
//Function Prototypes
void getFiles();
void getWords(char* key, char* replacement);
void processFile(cstream inFile, cstream outFile);
//-----------------------------------------------------------------------------
int main(void){
    //Print one time header
    banner();
    printf("        Program 2: Search and Replace\n");
    printf("----------------------------------------------------\n\n");

    getFiles();  //Read in files
    
	bye();
	return 0;
}

//-----------------------------------------------------------------------------
void getFiles(cstream inFile, cstream outFile){
    char inName[FLEN];
    char outName[FLEN];
    char* in = &inName[0];
    char* out = &outName[0];
    
	//Get and echo file names from user
	printf("Enter the path of the input file: ");
	scanf(" %255s", in);
    inFile = fopen(inName, "r");
    if(!inFile) fatal("\nCannot open file\n"); //Can't open file
    
	printf("Enter the path of the output file: ");
	scanf(" %255s", out);
    outFile = fopen(outName, "w");  
    if(!outFile) fatal("\nCannot open file\n"); //Can't open file
    
    //Echo file names
    printf("\nInput File: %s\n", in);
    printf("Output File: %s\n", out);
    
    processFile(inFile, outFile); //Read and write files
}

//-----------------------------------------------------------------------------
void getWords(char* key, char* replacement){
	//Get key word and replacement from user
	printf("\nEnter the desired key word of max 15 chars: ");
	scanf("%15s", key);
	printf("Enter the desired replacement word of max 15 chars: ");
	scanf("%15s", replacement);
    
    //Echo Words
    printf("\nSearch for: %s\n", key);
    printf("Replace with: %s\n", replacement);
}

//-----------------------------------------------------------------------------
void processFile(cstream inFile, cstream outFile){
    char key[WLEN];
    char replacement[WLEN];
    char readWord[WLEN];
    int lineCount = 0;

    getWords(key, replacement); //Words to find and replace
    
    //Read each word from input file, break if no input
    while(fscanf(inFile, "%15s", readWord) == 1){
        //Test if Key word is read
        if(!strcmp(readWord, key)){  //Key read
            fprintf(outFile, "%s ", replacement); //Print replacement word
            lineCount += strlen(replacement) + 1; //Cursor pos in output
        }
        else{ //Key not read
            fprintf(outFile, "%s ", readWord);  //Print original word
            lineCount += strlen(readWord) + 1;  //Cursor pos in output   
        }
        
        //Start new line in output if more than 70 chars
        if(lineCount >= 70){
            fprintf(outFile, "\n");
            lineCount = 0;
        }
    }
}
