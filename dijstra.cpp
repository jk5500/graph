#include <iostream>
#include <list>
#include <queue>

using namespace std;

#define INF 99999999
typedef pair<int,int> ipair;


class Graph
{
	int V;
	list<ipair> *adj;
public:
	Graph(int V);
	void addedge(int u,int v,int w);
	void shortest(int s);

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


void Graph::shortest(int s)
{

	int parent[V];
	for (int i=0;i<V;i++)
	{
		parent[i]=-1;
	}

	priority_queue<ipair, vector<ipair>, greater<ipair> > pq;

	int dist[V];
	for (int i=0;i<V;i++)
	{
		dist[i]=INF;
	}

	pq.push(make_pair(0,s));
	dist[s]=0;

	while (!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();

		list<ipair>::iterator i;

		for (i=adj[u].begin();i!=adj[u].end();i++)
		{
			int  v=(*i).first;
			int w=(*i).second;

			if (dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				parent[v]=u;
				pq.push(make_pair(dist[v],v));
			}
		}
	}
    
	for (int i=1;i<V;i++)
	{
		cout<<s<<" start to node "<< i<<" is "<< dist[i]<<" and parent is "<< parent[i]<<endl;
	}
}



int main()
{
	int V=5;
	Graph g(V);
	g.addedge(0,1,10);
	g.addedge(0,4,5);
	g.addedge(1,4,2);
	g.addedge(4,1,3);
	g.addedge(1,2,1);
	g.addedge(4,2,9);
	g.addedge(3,0,7);
	g.addedge(2,3,4);
	g.addedge(3,2,6);
	g.addedge(4,3,2);
	g.shortest(0);


	return 0;
}