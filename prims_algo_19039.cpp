#include<iostream>
#include<conio.h>
#include<list>
#include<set>
using namespace std;

typedef struct nodes {
   int dest;
   int cost;
}node;

class Graph {
   int n;
   list<node> *adjList;
   private:
      void showList(int src, list<node> lt) {
         list<node> :: iterator i;
         node tempNode;

         for(i = lt.begin(); i != lt.end(); i++) {
            tempNode = *i;
            cout << " " << src << "                      "<<tempNode.dest << "                 "<<tempNode.cost<<"    ";
            cout<<endl;
         }
         cout << endl;
      }

   public:
      Graph() {
         n = 0;
      }

      Graph(int nodeCount) {
         n = nodeCount;
         adjList = new list<node>[n];
      }

      void addEdge(int source, int dest, int cost) {
         node newNode;
         newNode.dest = dest;
         newNode.cost = cost;
         adjList[source].push_back(newNode);
      }

      void displayEdges() {
         for(int i = 0; i<n; i++) {
            list<node> tempList = adjList[i];
            showList(i, tempList);
         }
      }

      friend Graph primsMST(Graph g, int start);
};

set<int> difference(set<int> first, set<int> second) {
   set<int> :: iterator it;
   set<int> res;

   for(it = first.begin(); it != first.end(); it++) {
      if(second.find(*it) == second.end())
         res.insert(*it);     
   }

   return res;     
}

Graph primsMST(Graph g, int start) {
   int n = g.n;
   set<int> B, N, diff;
   Graph tree(n);        
   B.insert(start);     

   for(int u = 0; u<n; u++) {
      N.insert(u);  
   }

   while(B != N) {
      int min = 9999;             
      int v, par;
      diff = difference(N, B);     

      for(int u = 0; u < n; u++) {
         if(B.find(u) != B.end()) {
            list<node>::iterator it;
            for(it = g.adjList[u].begin(); it != g.adjList[u].end(); it++) {
               if(diff.find(it->dest) != diff.end()) {
                  if(min > it->cost) {
                     min = it->cost;    
                     par = u;
                     v = it->dest;
                  }
               }
            }
         }
      }

      B.insert(v);
      tree.addEdge(par, v, min);
      tree.addEdge(v, par, min);
   }
   return tree;
}

main() {
   Graph g(7), tree(7);
   int E;
   cout<<"Enter the number of edges:- ";
   cin>>E;
  cout<<"\nEnter the values :source : destination : weight \n";
	for(int i=0;i<E;i++)
	{
		int s,d,w;
	    cin>>s>>d>>w;
	    g.addEdge(s,d,w);
	}
	 cout<<" source              destination           weight";
	 cout<<endl;
   tree = primsMST(g, 0);
   tree.displayEdges();
   getch();
   return 0;
}

/*
Enter the number of edges:- 20

Enter the values :source : destination : weight

0 1 1
0 2 3
0 3 4
0 5 5
1 0 1
1 3 7
1 4 2
2 0 3
2 4 8
3 0 4
3 1 7
4 1 2
4 2 8
4 5 2
4 6 4
5 0 5
5 4 2
5 6 3
6 4 4
6 5 3
 
 source               destination        weight
 0                      1                 1
 0                      2                 3
 0                      3                 4

 1                      0                 1
 1                      4                 2

 2                      0                 3

 3                      0                 4

 4                      1                 2
 4                      5                 2

 5                      4                 2
 5                      6                 3

 6                      5                 3


*/
