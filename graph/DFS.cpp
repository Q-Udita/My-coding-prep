#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector< vector<int> > adj; 
    void DFSUtil(int,vector<int>);
    public:
    Graph(int);
    void addEdge(int,int);
    void DFS(int);
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

void Graph::DFS(int v)
{
    vector<int> visited(V);
    for(int i=0;i<V;i++)
        visited[i]=0;
    
    DFSUtil(v,visited);
    
}

void Graph::DFSUtil(int v,vector<int> visited)
{
    visited[v]=1;
    cout<<v<<" ";
    
    int k=adj[v].size();
    for(int i=0;i<k;i++)
    {
        int l=adj[v][i];
        if(!visited[l])
            DFSUtil(l,visited);
    }
}
int main()
{
    int s;
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
   
    cout<<"Output: ";
    g.DFS(2);
    return 0;
}
