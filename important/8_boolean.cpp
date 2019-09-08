#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int my_ops(int a, int b, string ops)
{
  int res = 0;

  // Assuming 32 bit ints
  for(int i=0;i<32;i++)
  {
    // Do an and with a 1 left shifted to get the bit at the ith place
    bool b_a = a & 1<<i;
    bool b_b = b & 1<<i;
    int out;

    // Run an and on the bits
    if(ops=="and")
    {
     out = b_a && b_b ? 1 : 0;
    }
    else if(ops=="xor")
    {
      out = b_a && b_b ? 0 : b_a || b_b;
    }
    else return 0;

    // cout<<b_a<<","<<b_b<<","<<and_ab<<endl;

    out<<=i;
    res |= out;
  }

  return res;
}

int main()
{
  int a = 3;//(11)
  int b = 5;//(101)

  int res_and = my_ops(a,b,"and");//001 = 1
  int res_xor = my_ops(a,b,"xor");//110 = 6

  cout<<(res_and==(a&b))<<endl;
  cout<<(res_xor==(a^b))<<endl;
}
