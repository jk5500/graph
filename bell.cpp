#include <iostream>
#include <list>
#include <queue>
#include <stdio.h>
#include <climits>
using namespace std;

#define INF INT_MAX
typedef pair<int,int> ipair;


class Graph
{
	int V;
	list<ipair> * adj;
public:
	Graph(int V);
	void addedge(int u,int v, int w);
	void shortestpath(int s);
};


Graph::Graph(int V)
{
	this->V=V;
	adj=new list<ipair> [V];
}
void Graph::addedge(int u,int v,int w)
{
	adj[u].push_back(make_pair(v,w));
}

void Graph::shortestpath(int s)
{
	int dist[V];
	for (int i=0;i<V;i++)
	{
		dist[V]=INF;
	}
	

	priority_queue<ipair, vector<ipair>, greater<ipair> > pq;
	for (int i=0;i<(V-1);i++)
	{    
		dist[s]=0;
		pq.push(make_pair(0,s));
		while (!pq.empty())
		{
			int u=pq.top().second;
			pq.pop();
			list<ipair>::iterator i;
			for (i=adj[u].begin();i!=adj[u].end();i++)
			{
				int v=(*i).first;
				int w=(*i).second;
				if (dist[v]>dist[u]+w)
				{
					dist[v]=dist[u]+w;
					pq.push(make_pair(dist[v],v));
					
				}
			}

			
			

		}
	}
	for (int i=0;i<V;i++)
	{
		cout<<"distance from source "<<s<<" to destination "<<i << " is  " <<dist[i]<< endl;
	}
}





int main()
{
	/*int V=6;
	Graph g(V);
	g.addedge(0,1,5);
	g.addedge(0,3,-2);
	g.addedge(1,2,1);
	g.addedge(2,5,3);
	g.addedge(2,4,7);
	g.addedge(2,3,2);
	g.addedge(3,1,2);
	g.addedge(3,4,3);
	g.addedge(4,5,10);
	g.shortestpath(0);
	*/
	int V=5;
	Graph g(V);
	g.addedge(0,1,-1);
	g.addedge(0,2,4);
	g.addedge(1,4,2);
	g.addedge(1,3,2);
	g.addedge(1,2,3);
	g.addedge(3,1,1);
	g.addedge(4,3,-3);
	g.addedge(3,2,5);
	g.shortestpath(0);


}