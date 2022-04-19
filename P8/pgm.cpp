//-----------------------------------------------------------------------------
// Nathan Grohoski
// CSCI-2212-01
// Program 8: Crop
//
//-----------------------------------------------------------------------------
#include "pgm.hpp"
//-----------------------------------------------------------------------------
pgm::pgm( ifstream& pgmFile ){
    long pixNum;
    
    //Check for P5 at beginning of header
    pgmFile >> check;
    if(check != "P5") fatal("Header missing P5, incorrect file");
    
    //Get picture dementions
    pgmFile >> width >> height >> grScale;
    cout << endl << "Width: " <<  width << " Height: " << height
         << " Color Scale: " << grScale << endl; 
    
    //Calculate number of pixels in the image
    pixNum = width * height;
    cout << "Number of Pixels: " << pixNum << endl << endl;
    if(!pgmFile.good()) fatal("Incorrect header format");
    
    //Find start of pixels
    while (pgmFile.get() != '\n');
    oldPic = new char[pixNum];
    
    //Read in pixels
    pgmFile.read( oldPic, pixNum );
    if(!pgmFile.good()) fatal("Failure to read pgm");
    
    //Check for end of file
    pgmFile.get();
    if(!pgmFile.eof()) fatal("Full file not read");
}
//-----------------------------------------------------------------------------
void pgm::crop(){
    int sub, col, row;
    int k = 0;
    int rowMin = 500;
    int colMin = 950;
    int rowMax = 1700;
    int colMax = 2000;
    
    //Calculate area to crop
    newWidth = colMax - colMin;
    newHeight = rowMax - rowMin;
    newPix = newWidth * newHeight;
    newPic = new char[newPix];
    
    //Crop Photo
    for(row = rowMin; row < rowMax; row++){
        for(col = colMin; col < colMax; col++){
            sub = row*width + col;
            newPic[k++] = oldPic[sub];
        }
    }
}
//-----------------------------------------------------------------------------
void pgm::print( ofstream& outFile ){
    //Write header to output pgm
    outFile << check << endl << newWidth << ' ' 
            << newHeight  << endl << grScale << endl;
            
    //Write pixels to output pgm      
    outFile.write(newPic, newPix);
    if(!outFile.good()) fatal("Failed to write cropped picture");
    
    cout << "Picture cropped and saved to out.pgm" << endl;
}
//-----------------------------------------------------------------------------
