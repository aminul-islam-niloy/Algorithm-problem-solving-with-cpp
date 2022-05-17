//BFS FOR COMPETITIVE PROGRAMMING
//Breadth First Search
#include<bits/stdc++.h>
using namespace std;
#define Nodes 10000
vector<int> adj[Nodes];
vector<bool> visited;
int level[Nodes];
void BFS(int root)
{
    queue<int>q;
    q.push(root);    
    
    level[root] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(auto v:adj[u])
        {
            if(!visited[v])
            {
                level[v] = level[u] + 1;
                q.push(v);
                visited[v] = true;
            }
        }
    }
    return;
}
int main()
{
    int u,v,nodes,edges;
    //bfs
    cin>>nodes>>edges;
    for(int i = 0; i<nodes;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    visited.assign(nodes,false);
    for(int i=0;i<edges;i++)
    {
        if(!visited[i])
        {
            BFS(i);
        }
    }
    for(int i=0;i<nodes;i++)
    {
        printf("Level of node %d is %d\n",i,level[i]);
    }

}