#include <iostream>

using namespace std;

// Types of recursion
// Tail : Only ascending stuff. Better to use loop.
// Head : Only descending stuff
// Linear : Has both ascending and descending stuff
// Tree : Calls itself more than one time. Eg merge sort
// Indirect: Functions calling each other in a cyclic manner
// Nested: Calling the function within the function

void fun(int n)
{
  if(n>0)
  {
    // Implemented before the recursion and starts going in
    cout<<"Ascending"<<endl;
    cout<<n<<endl;
    fun(n-1);
    // Implemented after the recursion reaches its boundary and starts coming out
    cout<<"Descending"<<endl;
    cout<<n*n<<endl;
  }
}

int fun2(int n)
{
  // This is static so its implemented in the code section. So its gonna persist as we go in the recursions
  //
  static int x;
  if(n>0)
  {
    x++;
    return fun2(n-1)+x;
  }
  return 0;
}

// Tree recursion
void fun3(int n)
{
  if(n>0)
  {
    cout<<n;
    fun3(n-1);
    fun3(n-1);
  }
}


int rec_sum(int n)
{
  if(n>0) return rec_sum(n-1)+n; // Recursive call
  else return 0; // Base
}

int rec_fact(int n)
{
  if(n>0) return rec_fact(n-1)*n; // Recursive call
  else return 1; // Base
}

int rec_pow(int x,int n)
{
  if(n>0)
  {
    if(n%2==0)
    {
      return rec_pow(x*x,n/2);
    }
    else
    {
      return x*rec_pow(x*x,n/2);
    }
  }
  else return 1;
}

// This is  order n^2 since  the kth term takes k multiplications
double rec_taylor(double x, double n)
{
  static double f,p;
  f=1;
  p=1;
  double r;
  if(n==0) return 1;
  else
  {
    r = rec_taylor(x,n-1);
    f*=n;
    p*=x;
    return r+(p/f);
  }
}


// This is taylor series expansion with horners rule. Now we only do 10 iterations
// Horners rule just takes common multiplication members out to reduce the number of multiplications you need to do 
double rec_taylor2(double x, double n)
{
  static int i=0;
  if(i==n+1)return 1;
  else
  {
    i++;
    return 1 + (x/i)*rec_taylor2(x,n);
  }
}


// This is a tree recursion and will take exponential time
int rec_fib(int n)
{
  if(n<=1) return n;
  return rec_fib(n-1)+rec_fib(n-2);
}

// This is linear going through all the numbers just once
int iter_fib(int n)
{
  if(n<=1) return n;

  int s = 0;
  int t = 1;
  for(int i=1; i<n;i++)
  {
    int temp = t;
    t=s+t;
    s = temp;
  }
  return t;
}

// Recursion for ncr using pascal triangle ncr = n-1cr-1+n-1cr
int rec_comb(int n,int r)
{
  if(n<=1||r==0||n==r) return 1;
  else
  {
    return rec_comb(n-1,r-1) + rec_comb(n-1,r);
  }
}

// Tower of hanoi move a stack of blocks of decreasing size to another position using just another auxillary position
// Again since this in a tree recursion it will be an exponential time taking function
void tower_of_hanoi(int n, int a, int b, int c)
{
  if(n>0)
  {
    tower_of_hanoi(n-1,a,c,b);
    cout<<"Moved "<<n<<" from "<<a<<" to "<<c<<endl;
    tower_of_hanoi(n-1,b,a,c);
  }
}

int main()
{
  cout<<"fun(5)"<<endl;
  fun(5);
  cout<<endl;

  cout<<"fun2(6)"<<endl;
  cout<<fun2(6)<<endl; // This will return 36 since we increment the static 6 times and then add it 6 times.
  cout<<endl;

  cout<<"fun3(3)"<<endl;
  fun3(3);
  cout<<endl;
  cout<<endl;

  cout<<"rec_sum(5)"<<endl;
  cout<<rec_sum(5)<<endl;
  cout<<endl;

  cout<<"rec_fact(5)"<<endl;
  cout<<rec_fact(5)<<endl;
  cout<<endl;

  cout<<"rec_pow(2,10)"<<endl;
  cout<<rec_pow(2,10)<<endl;
  cout<<endl;

  cout<<"rec_taylor(1,10)"<<endl;
  cout<<rec_taylor(1,10)<<endl;
  cout<<endl;

  cout<<"rec_taylor(1,10)"<<endl;
  cout<<rec_taylor(1,10)<<endl;
  cout<<endl;

  cout<<"rec_taylor2(1,10)"<<endl;
  cout<<rec_taylor2(1,10)<<endl;
  cout<<endl;

  cout<<"rec_fib(7)"<<endl;
  cout<<rec_fib(7)<<endl;
  cout<<endl;

  cout<<"iter_fib(7)"<<endl;
  cout<<iter_fib(7)<<endl;
  cout<<endl;

  cout<<"rec_comb(5,3)"<<endl;
  cout<<rec_comb(5,3)<<endl;
  cout<<endl;

  cout<<"tower_of_hanoi(5,1,2,3)"<<endl;
  tower_of_hanoi(5,1,2,3);
  cout<<endl;

  return 0;
}
