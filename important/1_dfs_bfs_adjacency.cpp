// N vertices and E edges. This is for a bidirectional graph
// The case is to print all the vertices using DFS

// Sample input
// 4
// 3
// 0 2
// 2 1
// 1 3

// This is the DFS way of graph traversal. You search for the first non visited node and continue doing so till you reach the end and then backtrack to find another stream to the end.
// You do this by maintaining a stack (LIFO). You add the first non visited neighbor to the stack then add the first non visited neighbor till you reach the node with no neighbors.
// When you add it to the stack add it as visited. Then you start popping of the stack. At each time check the next non visited neighbor till reaching the end and then popping again.
// This will be done till all the nodes are traversed and the root node is popped off the stack


// The BFS way of graph traversal. You visit all the neighbors. Then pick the neighbors one by one and visit all its neighbors then in the next set of neighbors (of neighbors) visit their neighbors and so on.
// You maintain a queue (FIFO). Then you start from a node pop it, add its connected neighbors to the queue. Then pop the top of the queue and push its unvisited neighbors to the queue and so on till the last node has been popped off the queue.

#include <iostream>
#include <vector>
using namespace std;

void printDFS(int** edges, int n, int sv, bool* visited)
{
  // Print the starting vertex and set its visited to true
  cout<<sv<<endl;
  visited[sv]=true;
  for(int i=0; i<n; i++)
  {
    if(i==sv) continue;
    if(edges[sv][i]==1)
    {
      if(visited[i]) continue;
      // Print the next edge connected to it
      // Ideally this will terminate only when all the ones connected to the node have been terminated
      else printDFS(edges, n, i, visited);
    }
  }
}

void printBFS(int** edges, int n, vector<int>& sv, bool* visited)
{
  vector<int> new_sv;

  for(auto v: sv)
  {
    cout<<v<<" ";
    visited[v] = true;
  }
  cout<<endl;

  for(auto v: sv)
  {
    for(int i=0; i<n; i++)
    {
      if(i==v) continue;
      if(edges[v][i]==1)
      {
        if(visited[i]) continue;
        else new_sv.push_back(i);
      }
    }
  }

  if(!new_sv.empty()) printBFS(edges, n, new_sv, visited);
}

int main()
{
  // Takes in the number of nodes and edges
  int n;
  int e;
  cin >> n >> e;

  // Pointer of pointers to create array of n arrays of size n
  // This is the adjacency matrix initialization
  int** edges  = new int*[n];
  for(int i=0; i<n; i++)
  {
    edges[i] = new int[n];
    for(int j = 0; j<n; j++)
    {
      edges[i][j] = 0;
    }
  }

  // Take the user input to set the adjacency matrix
  for(int i=0; i<e;i++)
  {
    int f,s;
    cin>>f>>s;
    edges[s][f]=1;
    edges[f][s]=1;
  }

  // Initialize the boolean array of visited nodes
  bool* visited = new bool[n];
  for(int i=0; i<n;i++) visited[i] = false;

  // Print the nodes in DFS
  cout<<"DFS"<<endl;
  printDFS(edges, n, 0, visited);

  // Print the nodes in BFS
  cout<<"BFS"<<endl;
  vector<int> sv{0};
  for(int i=0; i<n;i++) visited[i] = false;
  printBFS(edges, n, sv, visited);
}
