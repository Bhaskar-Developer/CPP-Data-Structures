#include<bits/stdc++.h>

using namespace std;

int main() {
  int vertices{};
  int edges{};

  cout << "Enter no of Vertices in Graph" << '\n';
  cin>> vertices;

  cout << "Enter no of Edges in Graph" << '\n';
  cin>>edges;

  //2D vector to store Graph
  vector<int> Graph[vertices+1]; 

  //Accept Graph
  for(int i=1;i<=edges;i++) {
    int a{},b{};
    cin >> a >> b;
    Graph[a].push_back(b);
    Graph[b].push_back(a);
  } 

  //Print Graph
  for(int i=1;i<=vertices;i++) {
    cout << i << "->";	  
    for(auto j: Graph[i]) {
      cout << j << " ";
    }
    cout << '\n';
  }
}

/*
 
This code runs on an undirected graph.
This code accepts number of nodes and edges in graph.
After entering the node and edges, we enter the nodes and their conections
After accepting all input, the graph will print the adjacency list representation on the graph. 
*/
