// Preprocessor directives
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

int main()
{

  /////////////////ARRAYS//////////////////////////////
  // NOTE: Arrays are a fixed size once allocated they cannot be changed
  int arrNums[10] = {1};
  int arrNums2[] = {1,2,3};
  int arrNums3[5] = {8,9};

  std::cout<<"First value: "<<arrNums[0]<<std::endl;
  arrNums[0] = 7;
  std::cout<<"First value: "<<arrNums[0]<<std::endl;

  // Note that the name of the array contains the address
  // to the first object in the array
  std::cout<<"Array size: "<<sizeof(arrNums3)/sizeof(*arrNums3)<<std::endl;

  // Multi dimensional array
  int arrNums4[2][2][2]={{{1,2},{3,4}},{{5,6},{7,8}}};

  /////////////VECTORS///////////////////////////////////
  std::vector<int> vecnRandNums(2);
  vecnRandNums[0]=1;
  vecnRandNums[1]=2;
  vecnRandNums.push_back(3);

  std::string sSentence="This is a random string";
  std::vector<std::string> vecsWords;
  std::stringstream ss(sSentence);
  std::string sIndivStr;
  char cSpace = ' ';

  // The getline will get the strings individually with the space as the delimiter
  while(getline(ss,sIndivStr,cSpace))
  {
    vecsWords.push_back(sIndivStr);
  }

  for(int i=0;i<vecsWords.size();i++)
  {
    std::cout<<vecsWords[i]<<std::endl;
  }

  // FINAL PROBLEM
  std::vector<std::string> vecsEntities;
  std::string sInput, sIndivEntity;
  std::cout<<"Enter Calculation (ex. 5 + 6): ";
  double dFirstNum, dSecondNum, dResult;

  std::cin>>sInput;
  std::stringstream ss2(sInput);

  while(getline(ss2,sIndivEntity,cSpace))
  {
    vecsEntities.push_back(sIndivEntity);
  }

  if(vecsEntities.size()!=3)
  {
    std::cout<<"Invalid format for input"<<std::endl;
    return -1;
  }

  dFirstNum = std::stod(vecsEntities[0]);
  dSecondNum = std::stod(vecsEntities[2]);

  if(vecsEntities[1]=="+")
  {
    dResult = dFirstNum + dSecondNum;
    printf("%.1f + %.1f = %.1f\n",dFirstNum,dSecondNum,dResult);
  }
  else if(vecsEntities[1]=="-")
  {
    dResult = dFirstNum - dSecondNum;
    printf("%.1f - %.1f = %.1f\n",dFirstNum,dSecondNum,dResult);
  }
  else if(vecsEntities[1]=="*")
  {
    dResult = dFirstNum * dSecondNum;
    printf("%.1f * %.1f = %.1f\n",dFirstNum,dSecondNum,dResult);

  }
  else if(vecsEntities[1]=="/")
  {
    dResult = dFirstNum / dSecondNum;
    printf("%.1f / %.1f = %.1f\n",dFirstNum,dSecondNum,dResult);
  }
  else
  {
    std::cout<<"The operation is not supported"<<std::endl;
    return -1;
  }

  return 0;
}
