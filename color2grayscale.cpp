/*
This code shows you an example of how to use the EasyBMP library.

It is not part of the assignment.
*/

#include <iostream>
using std::cout; using std::endl;

#include "EasyBMP.h"

int main( int argc, char* argv[] )
{
  if( argc != 3 ){
  cout << "Usage: color2grayscale"
       << "<input_filename> <output_filename>"
       << endl << endl;
  return 1;
  }

  // declare and read the bitmap
  BMP Input;
  Input.ReadFromFile( argv[1] );

// convert each pixel to grayscale using RGB->YUV
  for( int j=0 ; j < Input.TellHeight() ; j++)
    {
    for( int i=0 ; i < Input.TellWidth() ; i++)
      {
      int Temp = (int) floor( 0.299*Input(i,j)->Red +
			      0.587*Input(i,j)->Green +
			      0.114*Input(i,j)->Blue );
      ebmpBYTE TempBYTE = (ebmpBYTE) Temp;
      Input(i,j)->Red = TempBYTE;
      Input(i,j)->Green = TempBYTE;
      Input(i,j)->Blue = TempBYTE;
      }
    }

  // write the output file
  Input.WriteToFile( argv[2] ); 

  return 0;
}

