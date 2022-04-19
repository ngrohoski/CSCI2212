//-----------------------------------------------------------------------------
// Nathan Grohoski
// CSCI-2212-01
// Program 7: Bad_Alloc
//
// This program is ment to make the compiler run out of memory by creating a 
// large block of new ints, in order to show the error message for encountering
// a bad_alloc
//-----------------------------------------------------------------------------
#include "tools.hpp"

#define SIZE 1000000000
//-----------------------------------------------------------------------------
int main(void){
    int k = 0;
    vector <int*> pntrs;
    
    //Print one time header
    banner();
    cout <<"        Program 7: Bad_Alloc\n"
         <<"--------------------------------------------------------\n";
    
    while(1){
        //Create large block of ints
        int* temp = new int[SIZE];
        *temp = 1;  //Store number in new array
        
        pntrs.push_back(temp);
        
        //Print loop counter ever 10 passes
        if(++k % 10 == 0) cout << k << endl;
    }
    
    bye();
    return 0;
}
