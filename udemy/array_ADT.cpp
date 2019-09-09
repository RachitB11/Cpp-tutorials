#include <iostream>
#include <limits>
#include <assert.h>

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
template<typename T>
class Array
{
private:
  T* A;
  int size;
  int length;
  void swap(int i, int j);
  int recBinSearch(T x, int l, int r);

public:
  Array(T* arr, int s, int l);
  Array(initializer_list<T> arr, int s, int l);
  ~Array();
  void display() const;
  void add(T x);
  void insert(int ind, T x);
  void del(int ind);
  void bubbleSort();
  int linSearch(T x);
  int binSearch(T x);
  T get(int ind) const;
  void set(int ind, T x);
  T min();
  T max();
  T sum();
  T avg();
  void reverse();
};

// Initialize using a list
template<typename T> Array<T>::Array(initializer_list<T> arr, int s, int l) {
  assert(arr.size()<=s);
  A = new T[s];
  fill_n(A,s,0);
  copy(arr.begin(), arr.end(), A);
  size = s;
  length = l;
}

// Initialize using a pointer
template<typename T> Array<T>::Array(T* arr, int s, int l)
{
  A = arr;
  size = s;
  length = l;
}

// Destructor to delete the pointer to the array
template<typename T> Array<T>::~Array()
{
  delete []A;
  size=0;
  length=0;
}

// O(n)
template<typename T> void Array<T>::display() const
{
  for(int i=0; i<length; i++)
  {
    cout<<A[i]<<" ";
  }
  cout<<endl;
}

// O(1)
template<typename T> void Array<T>::add(T x)
{
  if(length != size)
  {
    A[length] = x;
    length++;
  }
}

// O(n)
template<typename T> void Array<T>::insert(int ind, T x)
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
template<typename T> void Array<T>::del(int ind)
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
template<typename T> void Array<T>::swap(int i, int j)
{
  T temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

// O(n^2)
template<typename T> void Array<T>::bubbleSort()
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
template<typename T> int Array<T>::linSearch(T x)
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
template<typename T> int Array<T>::recBinSearch(T x, int l, int r)
{
  int m = l + (r-l)/2;

  if(l<=r)
  {
    if(A[m]==x) return m;
    if(A[m]>x) return recBinSearch(x,l,m-1);
    else return recBinSearch(x,m+1,r);
  }
  return -1;
}

template<typename T> int Array<T>::binSearch(T x)
{
  return recBinSearch(x,0,length-1);
}

template<typename T> T Array<T>::get(int ind) const
{
  if(ind>=0 && ind<length) return A[ind];
}

template<typename T> void Array<T>::set(int ind, T x)
{
  if(ind>=0 && ind<length) A[ind] = x;
}

template<typename T> T Array<T>::max()
{
  T max = -numeric_limits<T>::infinity();
  for(int i=0;i<length;i++)
  {
    if(A[i]>max) max=A[i];
  }
  return max;
}

template<typename T> T Array<T>::min()
{
  T min = numeric_limits<T>::infinity();
  for(int i=0;i<length;i++)
  {
    if(A[i]<min) min=A[i];
  }
  return min;
}

template<typename T> T Array<T>::sum()
{
  T sum=0;
  for(int i=0;i<length;i++)
  {
    sum+=A[i];
  }
  return sum;
}

template<typename T> T Array<T>::avg()
{
  return sum()/static_cast<T>(length);
}

template<typename T> void Array<T>::reverse()
{
  for(int i=0; i<length/2; i++) swap(i,length-1-i);
}

int* merge(int* arr1,int* arr2,int m, int n)
{
  int *arr = new int[n+m];
  int i=0, j=0, k=0;

  for(int k=0;k<(n+m);k++)
  {
    if(i<m&&j<n)
    {
      if(arr1[i]<arr2[j])
      {
        arr[k] = arr1[i];
        i++;
      }
      else
      {
        arr[k] = arr2[j];
        j++;
      }
    }
    else if(i<m&&j==n)
    {
      arr[k] = arr1[i];
      i++;
    }
    else
    {
      arr[k] = arr2[j];
      j++;
    }
  }

  return arr;
}

int main()
{
  Array<int> arr({2,6,3,5,1},20,5);
  cout<<"Displaying the numbers"<<endl;
  arr.display();

  cout<<"arr.avg(): "<<arr.avg()<<endl;

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
  cout<<"arr.binSearch(5): "<<arr.binSearch(5)<<endl;
  cout<<"arr.binSearch(8): "<<arr.binSearch(8)<<endl;
  cout<<"arr.binSearch(2): "<<arr.binSearch(2)<<endl;

  arr.reverse();
  cout<<"After reverse: ";
  arr.display();

  // For sorted sets the same concept used to merge with maintaining iterators
  // for each of the arrays can be used for set operations like union, intersection
  // and difference.
  int arr1[] = {3,8,16,20,25};
  int arr2[] = {4,10,12,22,24,33,39};
  int *arr3 = merge(arr1,arr2,5,7);
  cout<<"Merged arrays: ";
  for(int i=0; i<(5+7);i++) cout<<arr3[i]<<" ";
  cout<<endl;
  delete []arr3;

  return 0;
}
