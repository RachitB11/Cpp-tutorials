// Preprocessor directives
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <numeric>
// For transform and reverse
#include <algorithm>
//  For the math stuff
#include <cmath>
// For random nos.
#include <ctime>
#include <fstream>

std::vector<std::string> StringToVector(std::string theString, char separator);

int main()
{
  std::ofstream writeToFile;
  std::ifstream readFromFile;
  std::string txtToWrite = "";
  std::string txtFromFile = "";

  // Means writing to file and truncate (Clear everything and write)
  writeToFile.open("test.txt",std::ios_base::out | std::ios_base::trunc);

  if(writeToFile.is_open())
  {
    writeToFile<<"Beginning of file\n";
    std::cout<<"Enter data to write: ";
    getline(std::cin,txtToWrite);
    writeToFile<<txtToWrite;
    writeToFile.close();
  }

  readFromFile.open("test.txt",std::ios_base::in);
  if(readFromFile.is_open())
  {
    while(readFromFile.good())
    {
      getline(readFromFile, txtFromFile);

      std::vector<std::string> strVec = StringToVector(txtFromFile, ' ');

      int word_count = 0;
      double letter_count = 0;

      for(auto x: strVec)
      {
        word_count++;
        letter_count += x.length();
      }

      std::cout<<txtFromFile<<" "<<word_count<<" "<<letter_count/word_count<<"\n";
    }
    readFromFile.close();
  }
  return 0;
}

std::vector<std::string> StringToVector(std::string theString, char separator)
{
  std::vector<std::string> vecsWords;
  std::stringstream ss(theString);
  std::string sIndivStr;

  // String stream and getline combo helps us get words on the basis of the separator
  while(getline(ss, sIndivStr, separator))
  {
    vecsWords.push_back(sIndivStr);
  }

  return vecsWords;
}
