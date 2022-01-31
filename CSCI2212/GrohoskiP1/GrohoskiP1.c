//-----------------------------------------------------------------------------
// Nathan Grohoski
// CSCI-2212-01
// Program 1
//
// This program will take a user input of characters, identify any alpha 
// characters, convert all to lower case, and remove repeats. The program will 
// then return the user a list of all unique alpha characters.
//-----------------------------------------------------------------------------

#include "tools.h"

//Define constants
#define arrayLength 26
#define sentinel '#' //Loop terminating character

//-----------------------------------------------------------------------------
//Function prototype to find repeat charactres
bool compare(char input[], char tempInput, int count);

//-----------------------------------------------------------------------------
int main(void){
    
    //Declare Variables
    int k = 0;
    int endLength = 0;
    char input[arrayLength];
    char tempInput;
    bool unique;
    bool reject;
    
    //Print one time header
    banner();
    printf("Program 1: List of Letters\n");
    
    //Print user instructions
    printf("Enter up to 26 unique aplha characters\n");
    printf("Non alpha characters and repeats will be rejected\n");
    printf("Terminate with #:\n");

    
    //Loop to read in character inputs
    while(k < arrayLength){
        scanf(" %c", &tempInput);
        
        //Reset reject flag
        reject = false;
        
        //Break if user enters '#'
        if(tempInput == sentinel) break;
        
        //Reject non alpha characters
        if(isalpha(tempInput) == false) reject = true;
        
        //Convert any upper case inputs to lower if alpha
        if(islower(tempInput) == false && reject == false){
            tempInput = tolower(tempInput);
        }
        
        //Check for repeat characters
        if(reject == false){
            unique = compare(input, tempInput, k); //Call unique check func
            if(unique == false) reject = true;     //Reject if not unique
        }
        
        //If the character is not rejected place into array
        if(reject == false){
            input[k] = tempInput;
            k++;
        }
    }
    
    //Get number of characters stored in array from loop iterations
    endLength = k;
    
    //Output header
    printf("\nUnique Alpha Characters:\n");
    
    //Loop to print chars
    for(k = 0; k < endLength; k++){
        printf("%c ", input[k]);
    }
    
    printf("\n\n");
    bye();
    return 0;
}

//-----------------------------------------------------------------------------
//Func to look thru array and compare to current input, rejecting repeat chars
bool compare(char input[], char tempInput, int count){
    int k = 0;
    bool unique = true;
    
    //Compare input characters looking for duplicates
    for(k = 0; k <  count; k++){
        if(tempInput == input[k]){
            unique = false;  //reject duplicate characters
            break;
        }
    }
    return unique;
}
