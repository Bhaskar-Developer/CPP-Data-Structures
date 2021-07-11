#include<bits/stdc++.h>

using namespace std;

class Graph {
  public:
         map<int,bool> visited{};
	 map<int,vector<int>> adjList{};

	 //Function to accept the edge betwenn two nodes in a undirected graph
	 void addEdge(int a, int b) {
	   adjList[a].push_back(b); 	 
	   adjList[b].push_back(a); 	 
	 }

	 //Function to print Adjacency List representation of Graph
	 void showGraph() {
	   for(auto &x : adjList) {
	     cout << x.first << "->";	   
	     for(auto &y: x.second) {
	       cout << y << " ";
	     }
	     cout << '\n';
	   }	 
	 }

	 //Function for iterative DFS Traversal on Graph
	 void DFS(int s) {
	 }
};


int main() {
  auto graph = make_unique<Graph>();
  graph->addEdge(1,2);
  graph->addEdge(1,4);
  graph->addEdge(2,4);
  graph->addEdge(2,3);
  graph->addEdge(4,5);
  graph->addEdge(4,6);
  graph->addEdge(6,3);
  graph->showGraph();
}

//This code is able to print the adjacency list properly
//Complete the code, its not complete! DFS function is still not implemented!
