#include<iostream>
#include<conio.h>

#include "List.h"
using namespace std;


class Graph
{
	List<int>*adj;
	int n;
	
	
	public:
		void getdata();
		void addEdge(const int,const int);
		void BFS();
		void BFS(int);
	
};

void Graph::getdata()
{
	int choice;
	cout<<"\nType of Graph:-\n";
	cout<<"\n1.Directed Graph";
	cout<<"\n2.Undirected Graph";
	cout<<"\nEnter your choice:-";
	cin>>choice;
	
	
	cout<<"\n\nNo. of nodes:-";
	cin>>n;
	adj=new List<int>[n];			//Adjacency list created
	
	int x;
	cout<<"\n-----[Enter 1 if there is an edge else 0]-----";
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(choice==2)
			{
			
				if(i<j)
				{
					cout<<"\nIs there an edge b/w("<<i<<","<<j<<"):-";
					cin>>x;
				
					if(x==1)
					{
						addEdge(i,j);
						addEdge(j,i);
					}
				}
			}
			
			else
			{
					if(i!=j)
					{
							cout<<"\nIs there an edge from("<<i<<" to "<<j<<"):-";
							cin>>x;
							if(x==1)
								addEdge(i,j);
					}		
			}
}



void Graph::addEdge(const int v,const int w)
{
	adj[v].addtail(w);
}

void Graph::BFS()
{
	int v;
	cout<<"\nEnter the source code:-";
	cin>>v;
	cout << "Following is Breadth First Traversal (starting from vertex "<<v<<"): ";
	BFS(v);
}

void Graph::BFS( int s)
{
	bool *visited=new bool[n];
	for(int i=0;i<n;++i)
	{
		visited[i]=false;
	}
	List<int>q;
	visited[s]=true;
	q.addtail(s);
	
	while(!q.empty())
	{
		s=q.front();
		cout<<s<<" ";
		q.deletefront();
		
		node<int>* temp=adj[s].getHead();
		while(temp!=NULL)
		{
			if(!visited[adj[s].getEle(temp)])
			{
		
				visited[adj[s].getEle(temp)]=true;
				q.addtail(adj[s].getEle(temp));
				
			}
			temp=adj[s].getNext(temp);
		}		
		

	}
}

int main()
{
	cout<<"                       ***********************  BREADTH FIRST SEARCH  ***********************\n\n";
	Graph b1;
	b1.getdata();
	b1.BFS();

	getch();
	return 0;
	
}

