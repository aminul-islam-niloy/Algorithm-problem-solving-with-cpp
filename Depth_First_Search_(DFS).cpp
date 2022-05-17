#include<bits/stdc++.h>
using namespace std;
#define NODES 1000
vector<int>adj[NODES];
vector<bool>visited;
int f[NODES]={0}, d[NODES]={0},T=0;

void DFS(int u)
{
    d[u] = ++T;
    visited[u] = true;
    cout<<u<<" ";
    for(auto x: adj[u])
    {
        if(!visited[x])
        {          
            DFS(x);
        }
    }
    f[u] = ++T;
}

int main()
{
    int nodes, edges, u,v; 
    cin>>nodes>>edges;
    visited.assign(nodes, false);
    for(int i = 0;i<edges;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v); 
    }
    for(int i = 0;i<nodes; i++)
    {
        if(!visited[i])
            DFS(i);
    }
    for(int i = 0;i<nodes; i++)
    {
        printf("\nDiscove time and Finishing time of node %d: %d and %d\n", i, d[i], f[i]);
    }
}
