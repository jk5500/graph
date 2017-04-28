#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph
{
	int V;
	list<int>* adj;
public:
	Graph(int V);
	void addedge(int v,int w);
	void DFS(int s);
};


Graph::Graph(int V)
{
	this->V=V;
	adj=new list<int>[V];
}
void Graph::addedge(int v, int w)
{
	adj[v].push_back(w);

}

void Graph::DFS(int s)
{
	int visited[V];
	for (int i=0;i<V;i++)
	{
		visited[i]=false;

	}
	stack<int> stack;
	stack.push(s);
	while (!stack.empty())
	{
		s=stack.top();
		cout<<s<<",";
		stack.pop();
		list<int>::iterator i;
        if (!visited[s])
        {
        	visited[s]=true;

        }
		for (i=adj[s].begin();i!=adj[s].end();i++)
		{
			//cout<<&i<<endl;
			if (!visited[*i])
			{
				stack.push(*i);
			}
		}
		

	}
}

int main()
{
	Graph g(5);
	g.addedge(1,0);
	g.addedge(2,1);
	g.addedge(0,3);
	g.addedge(1,4);
	g.addedge(0,2);
	g.DFS(0);
	


}