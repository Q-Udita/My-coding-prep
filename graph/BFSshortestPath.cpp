#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    public:
        Graph(int n) {
            V=n;
            adj.resize(n);
        }
    
        void add_edge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
    
        vector<int> shortest_reach(int start) {
            vector<int> visited(V);
            vector<int> dist(V);
            int i,l,s,a;
            for(i=0;i<V;i++)
            {
                visited[i]=0;
            }
            for(i=0;i<V;i++)
            {
                dist[i]=INT_MAX;
            }
            dist[start]=0;
            
            queue<int> q;
            q.push(start);
            
            while(!q.empty())
            {
                s=q.front();
                
                q.pop();
                l=adj[s].size();
                for(i=0;i<l;i++)
                {
                    a=adj[s][i];
                    if(!visited[a])
                    {
                        visited[a]=1;
                    if(dist[a]>(dist[s]+6))
                    {
                        dist[a]=dist[s]+6;
                    }
                        q.push(a);
                    }
                }
            }
            for(i=0;i<V;i++)
            {
            	if(!visited[i])
            	dist[i]=-1;
            }
            return dist;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
      int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
