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

// NOTE: the find, replace, append, erase, substr options are pretty useful for string manipulation qns'
// NOTE: the getline(ss,indivstring,separator) is also pretty cool to get words from the string

std::vector<std::string> StringToVector(std::string theString, char separator);
std::string VectorToString(std::vector<std::string> theVector, char separator);
std::string Trimwhitespace(std::string theString);
std::vector<int> FindSubstringMatches(std::string phrase, std::string substr);
std::string ReplaceAllSubstrings(std::string theString, std::string substring, std::string replacement);
std::string CaesarCipher(std::string theString, int cipher, bool encrypt);

int main()
{
  // NOTE: " " leads to a const char while the ' ' leads to a simple char
  // PROBLEM 1
  std::vector<std::string> vec  = StringToVector("This is a random string",' ');
  for(auto i : vec)
  {
    std::cout<<i<<"\n";
  }

  // PROBLEM 2
  std::vector<std::string> vCusts(3);
  vCusts[0] = "Bob";
  vCusts[1] = "Sue";
  vCusts[2] = "Tom";
  std::string sCusts = VectorToString(vCusts,' ');
  std::cout<< sCusts << "\n";

  // PROBLEM 3
  std::string aStr= "              Random stuff!!!        ";
  aStr = Trimwhitespace(aStr);
  std::cout<<"*"<<aStr<<"*\n";

  // PROBLEM 4
  std::string phrase = "To be or not to be";
  std::vector<int> matches = FindSubstringMatches(phrase,"be");
  for(auto ind:matches)
  {
    std::cout<<ind<<"\n";
  }

  // PROBLEM 5
  std::cout<<ReplaceAllSubstrings("to know or not to know","know","be")<<"\n";

  // ADDITIONAL USEFUL STRING STUFF
  char letterZ = 'z';
  char num3 = '3';
  char aSpace = ' ';

  std::cout << "Is z a letter or number " <<
          isalnum(letterZ) << "\n";
  std::cout << "Is z a letter " <<
          isalpha(letterZ) << "\n";
  std::cout << "Is z uppercase " <<
          isupper(letterZ) << "\n";
  std::cout << "Is z lowercase " <<
          islower(letterZ) << "\n";
  std::cout << "Is 3 a number " <<
          isdigit(num3) << "\n";
  std::cout << "Is space a space " <<
          isspace(aSpace) << "\n";

  // PROBLEM 6
  std::string theString("Hey Jude!!! Don't be afraid. Take a sad song and make it 7abcxyz!!!!");
  // std::string theString("xyz");
  std::string encryptedStr = CaesarCipher(theString, 23, true);
  std::string decryptedStr = CaesarCipher(encryptedStr, 23, false);
  std::cout<<"Encrypted String: " << encryptedStr << "\n";
  std::cout<<"Decrypted String: " << decryptedStr << "\n";

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

std::string VectorToString(std::vector<std::string> theVector, char separator)
{
  std::string stringWords=theVector[0];

  for(int i=1; i<theVector.size(); i++)
  {
    stringWords += (separator+theVector[i]);
  }
  return stringWords;
}

std::string Trimwhitespace(std::string theString)
{
  std::string whitespaces(" \t\f\n\r");
  // find_last_not_of finds the first character position that does not match any of the white spaces.
  // Erase if given 1 output erases everything after that. Itll delete between if it has 2 arguments fed in.
  theString.erase(theString.find_last_not_of(whitespaces) + 1);
  theString.erase(0, theString.find_first_not_of(whitespaces));
  return theString;
}

std::vector<int> FindSubstringMatches(std::string phrase, std::string substr)
{
  // transform(substr.begin(),substr.end(),substr.begin(),::tolower);
  // std::stringstream ss(phrase);
  // std::string sIndivStr;
  // std::vector<int> indexes;
  // int count = 0;
  // while(getline(ss,sIndivStr,' '))
  // {
  //   transform(sIndivStr.begin(),sIndivStr.end(),sIndivStr.begin(),::tolower);
  //   if(sIndivStr==substr)
  //   {
  //     indexes.push_back(count);
  //   }
  //   count++;
  // }
  // return indexes;

  std::vector<int> matchingIndexes;
  int index = phrase.find(substr,0);
  while(index!=std::string::npos)
  {
    matchingIndexes.push_back(index);
    index = phrase.find(substr,index+1);
  }

  return matchingIndexes;
}

std::string ReplaceAllSubstrings(std::string theString, std::string substring, std::string replacement)
{
  std::vector<int> matches = FindSubstringMatches(theString,substring);
  if(matches.size()!=0)
  {
    int lengthDifference = replacement.size() - substring.size();
    int count = 0;
    for(auto index: matches)
    {
      // Check the replace method
      theString.replace(index+(count*lengthDifference),substring.size(),replacement);
      count++;
    }
  }
  return theString;
}

std::string CaesarCipher(std::string theString, int cipher, bool encrypt)
{
  // a-z: 97-122
  // A-Z: 65-90
  // NOTE: Modulo of a -ve number is negative so add 26 and take another modulo during decryption
  if(!encrypt)
  {
    cipher  = -cipher;
  }
  for(int i=0; i<theString.size(); i++)
  {
    if(isalpha(theString[i]))
    {
      if(isupper(theString[i]))
      {
        theString[i] = (char)((((((int)theString[i]-(int)'A'+cipher)%26)+26)%26)+(int)'A');
      }
      else
      {
        theString[i] = (char)((((((int)theString[i]-(int)'a'-cipher)%26)+26)%26)+(int)'a');
      }
    }
  }
  return theString;
}
