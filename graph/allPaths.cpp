#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    const unsigned int M = 1000000000;
    vector<vector<int>> adj;
    void allPathsUtil(int,int,vector<int>,int&);
    public:
    Graph(int);
    void addEdge(int,int);
    void allPaths(int,int);
};

Graph::Graph(int v) {
    this->V=v;
    adj.resize(v);
}

void Graph::addEdge(int u,int v) {
    adj[u].push_back(v);
}

void Graph::allPaths(int s,int d) {
    int i,p=0;
    vector<int> visited(V);
    for(i=0;i<V;i++) {
        visited[i]=0;
    }

    allPathsUtil(s,d,visited,p);
    if(p==-1)
        cout<<"INFINITE PATHS";
    else 
        cout<<p;
}

void Graph::allPathsUtil(int u,int d,vector<int> visited,int& p) {

    int l,i,node;
    visited[u]=1;
    if(u==d) {
        if(p!=-1)
        p=(p+1)%M;
    }
    else {
    l=adj[u].size();
    for(i=0;i<l;i++) {
        node=adj[u][i];
        if(!visited[node]) {
            allPathsUtil(node,d,visited,p);
        }
        else p=-1;
    }
    }
    visited[u]=0;
}
int main() {
    
    int n,m,u,v;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++) {
        cin>>u>>v;
        u--;v--;
        g.addEdge(u,v);
    }
    
    g.allPaths(0,n-1);
    return 0;
}
