#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector< vector<int> > adj; 
    public:
    Graph(int);
    void addEdge(int,int);
    void BFS(int);
};

Graph::Graph(int v) 
{
    this->V=v;
    adj.resize(V);
}

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int v)
{
    vector<int> visited(V);
    for(int i=0;i<V;i++)
        visited[i]=0;
    
    visited[v]=1;
    list<int> q;
    q.push_back(v);
    
    while(!q.empty())
    {
        int node=q.front();
        cout<<node<<" ";
        q.pop_front();
         int s=adj[node].size();
    for(int i=0;i<s;i++)
    {
        int l=adj[node][i];
        if(!visited[l])
        {
            visited[l]=1;
            q.push_back(l);
        }
    }
        
    }
    
}


int main()
{
    
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
   
    cout<<"Output: ";
    g.BFS(2);
    return 0;
}

   
