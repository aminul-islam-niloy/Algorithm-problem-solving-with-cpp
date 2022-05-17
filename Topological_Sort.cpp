#include<bits/stdc++.h>
using namespace std;
#define mx 20005
vector<bool> visited;
vector<int>ans;
vector<int>graph[mx];
int edges, nodes;
stack<int>s;

void dfs(int v)
{
    visited[v] = true;
    for(int u: graph[v])
    {
        if(!visited[u])
            dfs(u);
    }
    s.push(v);
}
void topological_sort()
{
    for(int i=0;i<nodes;i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
    for(int i = 0; i< nodes; i++)
    {
        int x = s.top();
        s.pop();
        cout<<x<<" ";
    }
    cout<<endl;
}
int main()
{    
    cin>>nodes>>edges;
    int u,v;
    visited.assign(nodes, false);
    ans.clear();
    while(edges--)
    {
        cin>>u>>v;
        graph[u].push_back(v);
    }
    topological_sort();

}