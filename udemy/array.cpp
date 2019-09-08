#include <iostream>

// Static array
// int A[5];
// The size of the array was decided at runtime and the size of the memory already decided.
// This is created in the stack. Vectors are also created in the stack but they can be of variable size.


// Dynamic array
// Accessing from the heap requires a pointer
// int* p;  This pointer variable is created in the stack
// p=new int[5]; When you say "new" you are creating memory in the heap. "malloc" is used in c.
// This is a dynamic array. You NEED TO DELETE THIS MEMORY. Otherwise a memory leak is caused.
// delete []p; To delete the array.
// The size of this array cannot be changed.

// Memory for the array is contiguous

// 2D array (3 ways of creating the 2D array based on where the memory is allocated)
// int A[3][2] = {{1,2},{3,4},{5,6}}; Created in the stack
// int *A[3]; A[0] = new int[2]; A[1] = new int[2]; A[2] = new int[2]; Top level in stack but internal arrays in heap
// int **A; A = new int*A[3] A[0] = new int[2]; A[1] = new int[2]; A[2] = new int[2]; Top level and internal arrays in heap
// C++ uses row major accessing the data
// Note that in the second case *(A+2) is the pointer to the third row.
// Note that in the second case to get the data at (2,1) you will do *(*(A+1)+0)

using namespace std;

int main()
{
  // Copying a smaller array to a bigger array
  int *p = new int[5];
  int *q = new int[10];
  for(int i=0; i<5; i++)
  {
    p[i]=i;
  }
  // Start copying to the new array
  for(int i=0; i<5; i++)
  {
    q[i]=p[i];
  }
  // Delete the old pointer, set the old pointer to new pointer
  delete []p;
  p=q;
  q=NULL;
  for(int i=0; i<10; i++)
  {
    cout<<p[i];
  }
  // Delete the new pointer
  delete[] p;
  cout<<endl;

  return 0;
}
