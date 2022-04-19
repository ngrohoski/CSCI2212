//-----------------------------------------------------------------------------
// Nathan Grohoski
// CSCI-2212-01
// Program 8: Crop
//
// Header for pgm class
//-----------------------------------------------------------------------------
#pragma once

#include "tools.hpp"
//-----------------------------------------------------------------------------
class pgm{
  private:
    string check;
    int width, height, grScale;
    int newWidth, newHeight;
    long newPix;
    char* oldPic;
    char* newPic;
    
  public:
    pgm() = default;
    ~pgm() = default;
    pgm( ifstream& pgmFile );
    void crop();
    void print( ofstream& outFile );
};
//-----------------------------------------------------------------------------
