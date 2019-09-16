#include <iostream>
#include <bitset>
#include "math.h"

#define RADIX_NUMBER 2

void print(unsigned int* h_mask_array, size_t size)
{
  for(int i=0; i<size; i++)
  {
    std::cout<<std::bitset<32>(h_mask_array[i])<<std::endl;
  }
}


int main()
{
  const unsigned int radixBits = std::pow(2,RADIX_NUMBER);
  unsigned int mask = std::pow(2,radixBits)-1;

  // Assuming unsigned int size of 32 number of histograms equals number of masks
  // equals 32/radixBits
  const size_t numHistograms = 32/radixBits;
  unsigned int* h_mask_array = new unsigned int[numHistograms];
  // Populate the mask array
  std::cout<<"Masks:"<<std::endl;
  std::cout<<std::bitset<32>(mask)<<std::endl;
  for(int i=1; i<numHistograms; i++)
  {
    h_mask_array[i] = mask<<(radixBits*i);
    std::cout<<std::bitset<32>(h_mask_array[i])<<std::endl;
  }

  std::cout<<"Printing from the 3rd element"<<std::endl;
  print(h_mask_array+2,numHistograms-3);

  delete []h_mask_array;
}
