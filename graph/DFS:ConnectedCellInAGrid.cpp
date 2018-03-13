#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> DFS(int i,int j,vector<vector<vector<int>>> adj,vector<vector<int>> visited,int &s);

int get_biggest_region(vector< vector<int> > grid) {
    
      
    int n=grid.size();
    int m=grid[0].size();
    int i,j,s=0,max=0,ver=n*m,t=0;
    
    vector <vector<vector<int>>> adj(n);
    vector<vector<int>> visited(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        adj[i].resize(m);
    }
    
    
    //create an adjacency list
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(grid[i][j])
            {	t=0;
                if((i-1)>=0 && (j-1)>=0 && grid[i-1][j-1])
                   { adj[i][j].push_back(1); t=1;}
                if((i-1)>=0 && grid[i-1][j])
                   { adj[i][j].push_back(2); t=1;}
                if((i-1)>=0 && (j+1)<m && grid[i-1][j+1])
                   { adj[i][j].push_back(3); t=1;}
                if((j-1)>=0 && grid[i][j-1])
                   { adj[i][j].push_back(4); t=1;}
                if((j+1)<m && grid[i][j+1])
                   { adj[i][j].push_back(5); t=1;}
                if((i+1)<n && (j-1)>=0 && grid[i+1][j-1])
                   { adj[i][j].push_back(6); t=1;}
                if((i+1)<n && grid[i+1][j])
                   { adj[i][j].push_back(7); t=1;}
                if((i+1)<n && (j+1)<m && grid[i+1][j+1])
                   { adj[i][j].push_back(8); t=1;}
                if(t==0)
                    adj[i][j].push_back(0);
                
            }
        }
    }
    
    //initialising visited to 0
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            visited[i][j]=0;
        }
    } 
    
    // The function to do DFS traversal. It uses recursive DFS()
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(grid[i][j]==1 && visited[i][j]==0)
            {
                s=0;
               	visited=DFS(i,j,adj,visited,s);
                if(s>max) max=s; 
            }
            else if(visited[i][j]==0)
                visited[i][j]=1;
        }
    }
    return max;
}

vector<vector<int>> DFS(int i,int j,vector<vector<vector<int>>> adj,vector<vector<int>> visited,int &s)
{
    // Mark the current node as visited and increment the number of cell
    s++; //cout<<i<<" "<<j<<endl;    
    visited[i][j]=1;
    
    int len=adj[i][j].size();
    int node; 
   
    // Recur for all the vertices adjacent to this vertex
    for(int k=0;k<len;k++)
    {
        node=adj[i][j][k];
        if(node==1 && !visited[i-1][j-1])
            visited=DFS(i-1,j-1,adj,visited,s);
        else if(node==2 && !visited[i-1][j])
            visited=DFS(i-1,j,adj,visited,s);
        else if(node==3 && !visited[i-1][j+1])
            visited=DFS(i-1,j+1,adj,visited,s);
        else if(node==4 && !visited[i][j-1])
            visited=DFS(i,j-1,adj,visited,s);
        else if(node==5 && !visited[i][j+1])
            visited=DFS(i,j+1,adj,visited,s);
        else if(node==6 && !visited[i+1][j-1])
            visited=DFS(i+1,j-1,adj,visited,s);
        else if(node==7 && !visited[i+1][j])
            visited=DFS(i+1,j,adj,visited,s);
        else if(node==8 && !visited[i+1][j+1])
            visited=DFS(i+1,j+1,adj,visited,s);
    }
    return visited;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    //int p=get_biggest_region(grid);
    cout << get_biggest_region(grid) << endl;
    return 0;
}
