// Preprocessor directives
// These things are run before compile
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <numeric>
#include <stdio.h>
#include <memory>
#include <thread>
#include <ctime>
#include <mutex>

std::string GetTime()
{
  auto nowTime = std::chrono::system_clock::now();
  std::time_t sleepTime = std::chrono::system_clock::to_time_t(nowTime);
  return std::ctime(&sleepTime);
}

void FindPrimes(unsigned int start, unsigned int end, std::vector<unsigned int>& vect)
{
  for(unsigned int x = start; x<=end; x+=2)
  {
    for(unsigned int y = 2; y<x; y++)
    {
      if(x%y==0)
      {
        break;
      }
      else if((y+1)==x)
      {
        vect.push_back(x);
      }
    }
  }
}

std::mutex vectLock;
std::vector<unsigned int> primeThreadVect;

void FindPrimesMutexed(unsigned int start, unsigned int end)
{
  for(unsigned int x = start; x<=end; x+=2)
  {
    for(unsigned int y = 2; y<x; y++)
    {
      if(x%y==0)
      {
        break;
      }
      else if((y+1)==x)
      {
        vectLock.lock();
        primeThreadVect.push_back(x);
        vectLock.unlock();
      }
    }
  }
}

void FindPrimesWithThreads(unsigned int start, unsigned int end, unsigned int numThreads)
{
  std::vector<std::thread> threadVect;
  unsigned int threadSpread = (end-start+1) / numThreads;
  unsigned int newEnd = start + threadSpread - 1;
  for(unsigned int x = 0; x<numThreads; x++)
  {
    threadVect.emplace_back(FindPrimesMutexed, start, newEnd);
    start+=threadSpread;
    newEnd+=threadSpread;
  }
  for(auto &t: threadVect) t.join();
}


// A thread is just a block of code that executes.
// This is the main thread essentially.
// A multi thread is just to do separate calculations simultaneously
int main()
{
  // WITHOUT THREAD
  std::vector<unsigned int> primeVect;
  int startTime = clock();
  FindPrimes(1,100000,primeVect);
  // for(auto i: primeVect)
  //   std::cout<<i<<"\n";
  int endTime = clock();
  std::cout<<"Execution time: "<<(endTime-startTime)/double(CLOCKS_PER_SEC)<<std::endl;

  // WITH THREAD
  startTime = clock();
  FindPrimesWithThreads(1,20,3);
  for(auto i: primeThreadVect)
    std::cout<<i<<"\n";
  endTime = clock();
  std::cout<<"Execution time with threads: "<<(endTime-startTime)/double(CLOCKS_PER_SEC)<<std::endl;

  return 0;
}
