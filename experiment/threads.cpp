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

int GetRandom(int max)
{
  srand(time(NULL));
  return rand() % max;
}

void ExecuteThread(int id)
{
  auto nowTime = std::chrono::system_clock::now();
  std::time_t sleepTime = std::chrono::system_clock::to_time_t(nowTime);
  tm myLocalTime = *localtime(&sleepTime);
  std::cout<<"Thread "<<id<<" Sleep time : "<<std::ctime(&sleepTime)<<"\n";
  std::cout<<"Month: "<<myLocalTime.tm_mon<<"\n";
  std::cout<<"Day: "<<myLocalTime.tm_mday<<"\n";
  std::cout<<"Year: "<<myLocalTime.tm_year+1900<<"\n";
  std::cout<<"Hour: "<<myLocalTime.tm_hour<<"\n";
  std::cout<<"Minute: "<<myLocalTime.tm_min<<"\n";
  std::cout<<"Second: "<<myLocalTime.tm_sec<<"\n";
  std::this_thread::sleep_for(std::chrono::seconds(GetRandom(3)));
  nowTime = std::chrono::system_clock::now();
  sleepTime = std::chrono::system_clock::to_time_t(nowTime);
  std::cout<<"Thread "<<id<<" Awake time : "<<std::ctime(&sleepTime)<<"\n";
}

std::string GetTime()
{
  auto nowTime = std::chrono::system_clock::now();
  std::time_t sleepTime = std::chrono::system_clock::to_time_t(nowTime);
  return std::ctime(&sleepTime);
}

double acctBalance = 100;
// This is gonna prevent 2 different threads from accessing the same data at the same time.
std::mutex acctLock;

void GetMoney(int id, double withdrawal)
{
  // This is gonna restrict access to the entire scope of the function once another thread start executing this code
  // Alternately you could use acctLock.lock() and acctLock.unlock() (To block the code you want)
  // but it is not safe against exceptions. Read about it more.
  std::lock_guard<std::mutex> lock(acctLock);
  std::this_thread::sleep_for(std::chrono::seconds(3));
  std::cout<<id<< " tries to withdraw $"<< withdrawal<<" on "<<GetTime()<<"\n";
  if(acctBalance>=withdrawal)
  {
    acctBalance-=withdrawal;
    std::cout<<"New account balance is $"<<acctBalance<<"\n";
  }
  else
  {
    std::cout<<"Not enough money in the account"<<"\n";
    std::cout<<"Current balance is $"<<acctBalance<<"\n";
  }
}

// A thread is just a block of code that executes.
// This is the main thread essentially.
// A multi thread is just to do separate calculations simultaneously
int main()
{
  // // EXAMPLE 1 (Sequential)
  // std::thread th1(ExecuteThread, 1); // 1 is just the id being passed
  // th1.join();
  // std::thread th2(ExecuteThread, 2); // 2 is just the id
  // th2.join();

  // EXAMPLE 2 (Concurrent)
  std::thread threads[10];

  for(int i=0; i<10; i++)
  {
    threads[i] = std::thread(GetMoney, i , 15);
  }

  for(int i=0; i<10; i++)
  {
    threads[i].join();
  }

  return 0;
}
