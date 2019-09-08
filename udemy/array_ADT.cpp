#include <iostream>
#include <limits>

// Abstract data types
// Just need to have a representation and a set of operations
// An array
// Representation : Array space, length (unmber of filled elements) and size
// Operations : Display, Add, Inser, Delete, Search, Get, Set, Max,Min, Reverse, Shift, Rotate

using namespace std;


// EXAMPLE OF HOW TO CREATE A NEW ARRAY
// struct Array
// {
//   int *A;
//   int size;
//   int length;
// };
//
// void display(Array arr)
// {
//   for(int i=0; i<arr.length; i++)
//   {
//     cout<<arr.A[i]<<endl;
//   }
// }
//
// int main()
// {
//   Array arr;
//   cout<<"Enter the size of the array"<<endl;
//   cin>>arr.size;
//   arr.A = new int[arr.size];
//   arr.length = 0;
//
//   int n;
//   cout<<"Enter the number of numbers you want to input"<<endl;
//   cin>>n;
//
//   cout<<"Start entering the numbers"<<endl;
//   for(int i=0;i<n;i++)
//   {
//     cin>>arr.A[i];
//   }
//   arr.length=n;
//
//   cout<<"Displaying the numbers"<<endl;
//   display(arr);
//
//   delete []arr.A;
//
//   return 0;
// }

// ARRAY WITH PREDEFINED SIZE (Just for the ease of not having to add the elements everytime)
// Note that  since the array is defined in the stack we do not need to delete it
struct Array
{
  int A[20];
  int size;
  int length;
  void display() const;
  void add(int x);
  void insert(int ind, int x);
  void del(int ind);
  void swap(int i, int j);
  void bubbleSort();
  int linSearch(int x);
  int binSearch(int x, int l, int r);
  int get(int ind) const;
  void set(int ind, int x);
  int min();
  int max();
  int sum();
  int avg();
  void reverse();
};

// O(n)
void Array::display() const
{
  for(int i=0; i<length; i++)
  {
    cout<<A[i]<<" ";
  }
  cout<<endl;
}

// O(1)
void Array::add(int x)
{
  if(length != size)
  {
    A[length] = x;
    length++;
  }
}

// O(n)
void Array::insert(int ind, int x)
{
  if(length!=size)
  {
    if(ind>=length) add(x);
    else
    {
      for(int i=length-1; i>=ind; i--)
      {
        A[i+1] = A[i];
      }
      A[ind] = x;
      length++;
    }
  }
}

// O(n)
void Array::del(int ind)
{
  if(ind<length)
  {
    for(int i=ind; i<length; i++)
    {
      A[i] = A[i+1];
    }
    A[length-1]=0;
    length--;
  }
}

// O(1)
void Array::swap(int i, int j)
{
  int temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

// O(n^2)
void Array::bubbleSort()
{
  for(int i=0; i<length; i++)
  {
    for(int j=0; j<length-i-1; j++)
    {
      if(A[j]>A[j+1]) swap(j,j+1);
    }
  }
}

// O(n)
// Bonus : Transposition. Because the probability of searching the element again is high
// what you can do is move it 1 index up to reduce the search time
int Array::linSearch(int x)
{
  for(int i=0;i<length;i++)
  {
    if(A[i]==x)
    {
      swap(i,i-1);
      return i-1;
    }
  }
  return -1;
}

// O(logn) but prerequisite of the array being sorted
// Can easily be done iteratively too
// We know that the iterative way will be more optimal than the tail recursion
// as the rescursion will keep on making copies of these variables in the stack
int Array::binSearch(int x, int l, int r)
{
  int m = l + (r-l)/2;

  if(l<=r)
  {
    if(A[m]==x) return m;
    if(A[m]>x) return binSearch(x,l,m-1);
    else return binSearch(x,m+1,r);
  }
  return -1;
}

int Array::get(int ind) const
{
  if(ind>=0 && ind<length) return A[ind];
}

void Array::set(int ind, int x)
{
  if(ind>=0 && ind<length) A[ind] = x;
}

int Array::max()
{
  int max = -numeric_limits<int>::infinity();
  for(int i=0;i<length;i++)
  {
    if(A[i]>max) max=A[i];
  }
  return max;
}

int Array::min()
{
  int min = numeric_limits<int>::infinity();
  for(int i=0;i<length;i++)
  {
    if(A[i]<min) min=A[i];
  }
  return min;
}

int Array::sum()
{
  int sum=0;
  for(int i=0;i<length;i++)
  {
    sum+=A[i];
  }
  return sum;
}

int Array::avg()
{
  return sum()/length;
}

void Array::reverse()
{
  for(int i=0; i<length/2; i++) swap(i,length-1-i);
}

int main()
{
  Array arr = {{2,6,3,5,4},20,5};
  cout<<"Displaying the numbers"<<endl;
  arr.display();

  arr.add(7);
  arr.display();

  arr.insert(3, 8);
  arr.display();

  arr.del(3);
  arr.display();

  cout<<"arr.linSearch(5): "<<arr.linSearch(5)<<endl;
  cout<<"After transposition: ";
  arr.display();

  arr.bubbleSort();
  cout<<"After sort: ";
  arr.display();
  cout<<"arr.binSearch(5,0,arr.length-1): "<<arr.binSearch(5,0,arr.length-1)<<endl;
  cout<<"arr.binSearch(8,0,arr.length-1): "<<arr.binSearch(8,0,arr.length-1)<<endl;
  cout<<"arr.binSearch(2,0,arr.length-1): "<<arr.binSearch(2,0,arr.length-1)<<endl;

  arr.reverse();
  cout<<"After reverse: ";
  arr.display();

  return 0;
}
